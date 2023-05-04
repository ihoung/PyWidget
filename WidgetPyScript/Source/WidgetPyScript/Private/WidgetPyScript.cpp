// Copyright Epic Games, Inc. All Rights Reserved.

#include "WidgetPyScript.h"
#include "WidgetPyScriptStyle.h"
#include "WidgetPyScriptCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName WidgetPyScriptTabName("WidgetPyScript");

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
	// Put your "OnButtonClicked" stuff here
	//FText DialogText = FText::Format(
	//						LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
	//						FText::FromString(TEXT("FWidgetPyScriptModule::PluginButtonClicked()")),
	//						FText::FromString(TEXT("WidgetPyScript.cpp"))
	//				   );
	//FMessageDialog::Open(EAppMsgType::Ok, DialogText);
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
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FWidgetPyScriptModule, WidgetPyScript)