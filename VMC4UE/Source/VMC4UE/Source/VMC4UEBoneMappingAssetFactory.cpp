// Fill out your copyright notice in the Description page of Project Settings.

#include "../Include/VMC4UEBoneMappingAssetFactory.h"
#include "../Include/VMC4UEBoneMapping.h"
#include "../Include/VMC4UEStreamingData.h"
#include "Dom/JsonObject.h"
#include "JsonObjectConverter.h"

UVMC4UEBoneMappingAssetFactory::UVMC4UEBoneMappingAssetFactory(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
    SupportedClass = UVMC4UEBoneMapping::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
	bText = true;
	Formats.Add(TEXT("bmap;VMC Bone Mapping Asset"));
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

UObject* UVMC4UEBoneMappingAssetFactory::FactoryCreateText(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const TCHAR*& Buffer, const TCHAR* BuferEnd, FFeedbackContext* Warn)
{
	FString TextData = FString(Buffer);

	UVMC4UEBoneMapping* NewAsset = CastChecked<UVMC4UEBoneMapping>(StaticConstructObject_Internal(InClass, InParent, InName, Flags));
	if (NewAsset != nullptr)
	{
		FVMC4UEBoneMappingText BoneMappingText;
		if (FJsonObjectConverter::JsonObjectStringToUStruct<FVMC4UEBoneMappingText>(TextData, &BoneMappingText, 0, 0))
		{
			NewAsset->Hips = BoneMappingText.Hips;
			NewAsset->LeftUpperLeg = BoneMappingText.LeftUpperLeg;
			NewAsset->RightUpperLeg = BoneMappingText.RightUpperLeg;
			NewAsset->LeftLowerLeg = BoneMappingText.LeftLowerLeg;
			NewAsset->RightLowerLeg = BoneMappingText.RightLowerLeg;
			NewAsset->LeftFoot = BoneMappingText.LeftFoot;
			NewAsset->RightFoot = BoneMappingText.RightFoot;
			NewAsset->Spine = BoneMappingText.Spine;
			NewAsset->Chest = BoneMappingText.Chest;
			NewAsset->Neck = BoneMappingText.Neck;
			NewAsset->Head = BoneMappingText.Head;
			NewAsset->LeftShoulder = BoneMappingText.LeftShoulder;
			NewAsset->RightShoulder = BoneMappingText.RightShoulder;
			NewAsset->LeftUpperArm = BoneMappingText.LeftUpperArm;
			NewAsset->RightUpperArm = BoneMappingText.RightUpperArm;
			NewAsset->LeftLowerArm = BoneMappingText.LeftLowerArm;
			NewAsset->RightLowerArm = BoneMappingText.RightLowerArm;
			NewAsset->LeftHand = BoneMappingText.LeftHand;
			NewAsset->RightHand = BoneMappingText.RightHand;
			NewAsset->LeftToes = BoneMappingText.LeftToes;
			NewAsset->RightToes = BoneMappingText.RightToes;
			NewAsset->LeftEye = BoneMappingText.LeftEye;
			NewAsset->RightEye = BoneMappingText.RightEye;
			NewAsset->Jaw = BoneMappingText.Jaw;
			NewAsset->LeftThumbProximal = BoneMappingText.LeftThumbProximal;
			NewAsset->LeftThumbIntermediate = BoneMappingText.LeftThumbIntermediate;
			NewAsset->LeftThumbDistal = BoneMappingText.LeftThumbDistal;
			NewAsset->LeftIndexProximal = BoneMappingText.LeftIndexProximal;
			NewAsset->LeftIndexIntermediate = BoneMappingText.LeftIndexIntermediate;
			NewAsset->LeftIndexDistal = BoneMappingText.LeftIndexDistal;
			NewAsset->LeftMiddleProximal = BoneMappingText.LeftMiddleProximal;
			NewAsset->LeftMiddleIntermediate = BoneMappingText.LeftMiddleIntermediate;
			NewAsset->LeftMiddleDistal = BoneMappingText.LeftMiddleDistal;
			NewAsset->LeftRingProximal = BoneMappingText.LeftRingProximal;
			NewAsset->LeftRingIntermediate = BoneMappingText.LeftRingIntermediate;
			NewAsset->LeftRingDistal = BoneMappingText.LeftRingDistal;
			NewAsset->LeftLittleProximal = BoneMappingText.LeftLittleProximal;
			NewAsset->LeftLittleIntermediate = BoneMappingText.LeftLittleIntermediate;
			NewAsset->LeftLittleDistal = BoneMappingText.LeftLittleDistal;
			NewAsset->RightThumbProximal = BoneMappingText.RightThumbProximal;
			NewAsset->RightThumbIntermediate = BoneMappingText.RightThumbIntermediate;
			NewAsset->RightThumbDistal = BoneMappingText.RightThumbDistal;
			NewAsset->RightIndexProximal = BoneMappingText.RightIndexProximal;
			NewAsset->RightIndexIntermediate = BoneMappingText.RightIndexIntermediate;
			NewAsset->RightIndexDistal = BoneMappingText.RightIndexDistal;
			NewAsset->RightMiddleProximal = BoneMappingText.RightMiddleProximal;
			NewAsset->RightMiddleIntermediate = BoneMappingText.RightMiddleIntermediate;
			NewAsset->RightMiddleDistal = BoneMappingText.RightMiddleDistal;
			NewAsset->RightRingProximal = BoneMappingText.RightRingProximal;
			NewAsset->RightRingIntermediate = BoneMappingText.RightRingIntermediate;
			NewAsset->RightRingDistal = BoneMappingText.RightRingDistal;
			NewAsset->RightLittleProximal = BoneMappingText.RightLittleProximal;
			NewAsset->RightLittleIntermediate = BoneMappingText.RightLittleIntermediate;
			NewAsset->RightLittleDistal = BoneMappingText.RightLittleDistal;
		}
	}

	return NewAsset;
}
