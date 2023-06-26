// Copyright Epic Games, Inc. All Rights Reserved.

#include "WidgetPyScript.h"
#include "WidgetPyScriptToolkit.h"

void FWidgetPyScriptModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	PluginToolkit = MakeShared<FWidgetPyScriptToolkit>();
}

void FWidgetPyScriptModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	PluginToolkit.Reset();
}
	
IMPLEMENT_MODULE(FWidgetPyScriptModule, WidgetPyScript)