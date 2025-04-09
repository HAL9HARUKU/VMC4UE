// Fill out your copyright notice in the Description page of Project Settings.

#include "../Include/VMC4UEBoneMappingAssetFactory.h"
#include "../../VMC4UE/Include/VMC4UEBoneMapping.h"
#include "../../VMC4UE/Include/VMC4UEStreamingData.h"
#include "Dom/JsonObject.h"
#include "JsonObjectConverter.h"

UVMC4UEBoneMappingAssetFactory::UVMC4UEBoneMappingAssetFactory(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
    SupportedClass = UVMC4UEVRMMapping::StaticClass();
    bCreateNew = false;
    bEditorImport = true;
    bText = true;
    Formats.Add(TEXT("vrmmap;VMC Bone Mapping Asset"));
}

bool UVMC4UEBoneMappingAssetFactory::DoesSupportClass(UClass *Class)
{
    return (Class == UVMC4UEVRMMapping::StaticClass());
}

UClass *UVMC4UEBoneMappingAssetFactory::ResolveSupportedClass()
{
    return UVMC4UEVRMMapping::StaticClass();
}

UObject *UVMC4UEBoneMappingAssetFactory::FactoryCreateText(UClass *InClass, UObject *InParent, FName InName, EObjectFlags Flags, UObject *Context, const TCHAR *Type, const TCHAR *&Buffer, const TCHAR *BuferEnd, FFeedbackContext *Warn)
{
    FString TextData = FString(Buffer);

#if (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 3)
    FStaticConstructObjectParameters Params(InClass);
    Params.Name = InName;
    Params.SetFlags = Flags;
    Params.Outer = InParent;

    UVMC4UEVRMMapping *NewAsset = CastChecked<UVMC4UEVRMMapping>(StaticConstructObject_Internal(Params));
#else
    UVMC4UEVRMMapping* NewAsset = CastChecked<UVMC4UEVRMMapping>(StaticConstructObject_Internal(InClass, InParent, InName, Flags));
#endif
    if (!IsValid(NewAsset))
    {
        return nullptr;
    }

    if (!FJsonObjectConverter::JsonObjectStringToUStruct<FVMC4UEVRMMappingData>(TextData, &NewAsset->VRMMapping, 0, 0))
    {
        UE_LOG(LogTemp, Error, TEXT("vrmmap Load Error"));
    }
    return NewAsset;
}
