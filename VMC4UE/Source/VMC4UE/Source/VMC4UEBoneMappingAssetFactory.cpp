// Fill out your copyright notice in the Description page of Project Settings.

#include "../Include/VMC4UEBoneMappingAssetFactory.h"
#include "../Include/VMC4UEBoneMapping.h"

UVMC4UEBoneMappingAssetFactory::UVMC4UEBoneMappingAssetFactory(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
    SupportedClass = UVMC4UEBoneMapping::StaticClass();
    bCreateNew = true;
}

bool UVMC4UEBoneMappingAssetFactory::DoesSupportClass(UClass *Class)
{
    return (Class == UVMC4UEBoneMapping::StaticClass());
}

UClass *UVMC4UEBoneMappingAssetFactory::ResolveSupportedClass()
{
    return UVMC4UEBoneMapping::StaticClass();
}
UObject *UVMC4UEBoneMappingAssetFactory::FactoryCreateNew(UClass *InClass, UObject *InParent, FName InName, EObjectFlags Flags, UObject *Context, FFeedbackContext *Warn)
{
    UVMC4UEBoneMapping *NewAsset = CastChecked<UVMC4UEBoneMapping>(StaticConstructObject_Internal(InClass, InParent, InName, Flags));
    return NewAsset;
}
