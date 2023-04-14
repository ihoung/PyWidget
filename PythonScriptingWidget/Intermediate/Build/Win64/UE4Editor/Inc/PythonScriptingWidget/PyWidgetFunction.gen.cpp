// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PythonScriptingWidget/Public/PyWidgetFunction.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePyWidgetFunction() {}
// Cross Module References
	PYTHONSCRIPTINGWIDGET_API UClass* Z_Construct_UClass_UPyWidgetFunction_NoRegister();
	PYTHONSCRIPTINGWIDGET_API UClass* Z_Construct_UClass_UPyWidgetFunction();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_PythonScriptingWidget();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UPyWidgetFunction::execGetWidgetVariable)
	{
		P_GET_OBJECT(UObject,Z_Param_WidgetObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_VarName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UObject**)Z_Param__Result=UPyWidgetFunction::GetWidgetVariable(Z_Param_WidgetObject,Z_Param_VarName);
		P_NATIVE_END;
	}
	void UPyWidgetFunction::StaticRegisterNativesUPyWidgetFunction()
	{
		UClass* Class = UPyWidgetFunction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetWidgetVariable", &UPyWidgetFunction::execGetWidgetVariable },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics
	{
		struct PyWidgetFunction_eventGetWidgetVariable_Parms
		{
			UObject* WidgetObject;
			FString VarName;
			UObject* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WidgetObject;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_VarName;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::NewProp_WidgetObject = { "WidgetObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyWidgetFunction_eventGetWidgetVariable_Parms, WidgetObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::NewProp_VarName = { "VarName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyWidgetFunction_eventGetWidgetVariable_Parms, VarName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyWidgetFunction_eventGetWidgetVariable_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::NewProp_WidgetObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::NewProp_VarName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*, UClass* VarClass*/" },
		{ "ModuleRelativePath", "Public/PyWidgetFunction.h" },
		{ "ToolTip", ", UClass* VarClass" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyWidgetFunction, nullptr, "GetWidgetVariable", nullptr, nullptr, sizeof(PyWidgetFunction_eventGetWidgetVariable_Parms), Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPyWidgetFunction_NoRegister()
	{
		return UPyWidgetFunction::StaticClass();
	}
	struct Z_Construct_UClass_UPyWidgetFunction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPyWidgetFunction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_PythonScriptingWidget,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPyWidgetFunction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPyWidgetFunction_GetWidgetVariable, "GetWidgetVariable" }, // 462153584
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPyWidgetFunction_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "PyWidgetFunction.h" },
		{ "ModuleRelativePath", "Public/PyWidgetFunction.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPyWidgetFunction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPyWidgetFunction>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPyWidgetFunction_Statics::ClassParams = {
		&UPyWidgetFunction::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPyWidgetFunction_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPyWidgetFunction_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPyWidgetFunction()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPyWidgetFunction_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPyWidgetFunction, 2769157126);
	template<> PYTHONSCRIPTINGWIDGET_API UClass* StaticClass<UPyWidgetFunction>()
	{
		return UPyWidgetFunction::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPyWidgetFunction(Z_Construct_UClass_UPyWidgetFunction, &UPyWidgetFunction::StaticClass, TEXT("/Script/PythonScriptingWidget"), TEXT("UPyWidgetFunction"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPyWidgetFunction);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
