// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetPyScriptFunctionLibrary.h"
#include "BlueprintEditor.h"
#include "EditorUtilityWidgetBlueprint.h"

//UObject* UWidgetPyScriptFunctionLibrary::GetCurrentEditingWidget()
//{
//    UAssetEditorSubsystem* AssetEditorSubsystem = GEditor->GetEditorSubsystem<UAssetEditorSubsystem>();
//    TArray<UObject*> Assets = AssetEditorSubsystem->GetAllEditedAssets();
//    TArray<IAssetEditorInstance*> AssetEditors;
//    for (UObject* Asset : Assets)
//    {
//        if (Asset->GetClass()->IsChildOf(UEditorUtilityWidgetBlueprint::StaticClass()))
//        {
//            IAssetEditorInstance* AssetEditor = AssetEditorSubsystem->FindEditorForAsset(Asset, false);
//            AssetEditors.Add(AssetEditor);
//            UE_LOG(LogTemp, Warning, TEXT("asset: %s"), *StaticCast<FBlueprintEditor*>(AssetEditor)->GetBlueprintObj()->GetFName().ToString());
//        }
//    }
//    return nullptr;
//
//    return nullptr;
//}

//TArray<UObject*> UWidgetPyScriptFunctionLibrary::GetAllObjects()
//{
//    TArray<UObject*> Array;
//    for (TObjectIterator<UObject> Itr; Itr; ++Itr)
//    {
//        Array.Add(*Itr);
//    }
//    return Array;
//}
