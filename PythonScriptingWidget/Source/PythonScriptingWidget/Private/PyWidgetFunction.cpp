// Fill out your copyright notice in the Description page of Project Settings.


#include "PyWidgetFunction.h"

UObject* UPyWidgetFunction::GetWidgetVariable(UObject* WidgetObject, FString VarName/*, UClass* VarClass*/) {
	//TArray<FName> slots = Cast<UWidgetBlueprintGeneratedClass>(WidgetClass)->NamedSlots;
	//for (int i = 0; i < slots.Num(); ++i) {
	//	UE_LOG(LogTemp, Warning, TEXT("UObject: %s, VarName: %s"), *slots[i].ToString(), *VarName);
	//}
	UArrayProperty* property = FindFProperty<UArrayProperty>(WidgetObject->GetClass(), FName("NamedSlots"));
	if (property != NULL) {
		TArray<FName>* Value = property->ContainerPtrToValuePtr<TArray<FName>>(WidgetObject);
		//UE_LOG(LogTemp, Warning, TEXT("Find the property %s"), *Value->StaticConfigName());
		//return Value;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Cannot find the property"));
	}
	return NULL;
}

