// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "VMC4UE.h"
#include "Modules/ModuleManager.h"

class FVMC4UEModule : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
    }
    virtual void ShutdownModule() override
    {
    }
    virtual bool IsGameModule() const override
    {
        return true;
    }
};

IMPLEMENT_GAME_MODULE(FVMC4UEModule, VMC4UE);
