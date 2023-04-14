// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Blueprint/WidgetBlueprintGeneratedClass.h"
#include "PyWidgetFunction.generated.h"

/**
 * 
 */
UCLASS()
class PYTHONSCRIPTINGWIDGET_API UPyWidgetFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		static UObject* GetWidgetVariable(UObject* WidgetObject, FString VarName/*, UClass* VarClass*/);
	
};
