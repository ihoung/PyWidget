// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WidgetPyScriptFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class WIDGETPYSCRIPT_API UWidgetPyScriptFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	//static UObject* GetCurrentEditingWidget();

	//UFUNCTION(BlueprintCallable)
	//static TArray<UObject*> GetAllObjects();

	UFUNCTION(BlueprintCallable)
	static void GeneratePyFromWidgets(const TArray<FAssetData>& Assets);

	UFUNCTION(BlueprintCallable)
	static void GeneratePyFromWidget(const FAssetData& Asset);

	UFUNCTION(BlueprintCallable)
	static TArray<UWidget*> GetAllVariableWidgets(UWidgetBlueprint* WidgetBP);

};
