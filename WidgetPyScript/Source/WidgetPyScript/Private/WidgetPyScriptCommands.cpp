// Copyright Epic Games, Inc. All Rights Reserved.

#include "WidgetPyScriptCommands.h"

#define LOCTEXT_NAMESPACE "FWidgetPyScriptModule"

void FWidgetPyScriptCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "WidgetPyScript", "Execute WidgetPyScript action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
