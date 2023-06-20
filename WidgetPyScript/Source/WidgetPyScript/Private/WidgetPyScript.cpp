// Copyright Epic Games, Inc. All Rights Reserved.

#include "WidgetPyScript.h"
#include "WidgetPyScriptStyle.h"
#include "WidgetPyScriptCommands.h"
#include "WidgetPyScriptFunctionLibrary.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "ContentBrowserModule.h"
#include "EditorUtilityWidgetBlueprint.h"

#define LOCTEXT_NAMESPACE "FWidgetPyScriptModule"

void FWidgetPyScriptModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FWidgetPyScriptStyle::Initialize();
	FWidgetPyScriptStyle::ReloadTextures();

	FWidgetPyScriptCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FWidgetPyScriptCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FWidgetPyScriptModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FWidgetPyScriptModule::RegisterMenus));
}

void FWidgetPyScriptModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FWidgetPyScriptStyle::Shutdown();

	FWidgetPyScriptCommands::Unregister();
}

void FWidgetPyScriptModule::PluginButtonClicked()
{
	FText DialogText = FText(
							LOCTEXT("PluginButtonDialogText", 
								"Not supported yet.\n Please locate the asset in Content Browser and generate Python scripts from RMB clicked menu.")
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FWidgetPyScriptModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	//{
	//	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
	//	{
	//		FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
	//		Section.AddMenuEntryWithCommandList(FWidgetPyScriptCommands::Get().PluginAction, PluginCommands);
	//	}
	//}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("AssetEditor.BlueprintEditor.ToolBar.DesignerName");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Compile");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FWidgetPyScriptCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}

	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));
	{
		TArray<FContentBrowserMenuExtender_SelectedAssets>& CBMenuAssetExtenderDelegates = ContentBrowserModule.GetAllAssetViewContextMenuExtenders();
		CBMenuAssetExtenderDelegates.Add(FContentBrowserMenuExtender_SelectedAssets::CreateRaw(this, &FWidgetPyScriptModule::AddCBMenuExtender));
	}
}

TSharedRef<FExtender> FWidgetPyScriptModule::AddCBMenuExtender(const TArray<FAssetData>& SelectedAssets)
{
	TSharedRef<FExtender> Extender = MakeShared<FExtender>();

	bool HasWidgetAsset = false;
	for (auto AssetIt = SelectedAssets.CreateConstIterator(); AssetIt; ++AssetIt)
	{
		const FAssetData& Asset = *AssetIt;
		if (!Asset.IsRedirector() && Asset.AssetClass != NAME_Class && !(Asset.PackageFlags & PKG_FilterEditorOnly))
		{
			if (Asset.GetClass()->IsChildOf(UEditorUtilityWidgetBlueprint::StaticClass()))
			{
				HasWidgetAsset = true;
				break;
			}
		}
	}

	if (HasWidgetAsset)
	{
		Extender->AddMenuExtension(
			"CommonAssetActions",
			EExtensionHook::After,
			PluginCommands,
			FMenuExtensionDelegate::CreateLambda([&](FMenuBuilder& MenuBuilder)
				{
					MenuBuilder.BeginSection("Python", LOCTEXT("ASSET_CONTEXT", "Python"));
					{
						// Add Menu Entry Here
						MenuBuilder.AddMenuEntry(
							LOCTEXT("GeneratePy", "Genereate Python Scripts"),
							LOCTEXT("GeneratePy ToolTip", "Generate Python Scripts for the associated Widget"),
							FSlateIcon(FWidgetPyScriptStyle::GetStyleSetName(), "WidgetPyScript.MenuIcon"),
							FUIAction(FExecuteAction::CreateRaw(this, &FWidgetPyScriptModule::AddCBMenuAction, SelectedAssets)),
							NAME_None,
							EUserInterfaceActionType::Button
						);
					}
					MenuBuilder.EndSection();
				}
			)
		);
	}

	return Extender;
}

void FWidgetPyScriptModule::AddCBMenuAction(TArray<FAssetData> SelectedAssets)
{
	UWidgetPyScriptFunctionLibrary::GeneratePyFromWidgets(SelectedAssets);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FWidgetPyScriptModule, WidgetPyScript)