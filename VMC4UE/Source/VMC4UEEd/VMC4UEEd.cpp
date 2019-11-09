// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "VMC4UEEd.h"
#include "Modules/ModuleManager.h"

class FVMC4UEEdModule : public IModuleInterface
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

IMPLEMENT_GAME_MODULE(FVMC4UEEdModule, VMC4UEEd);
