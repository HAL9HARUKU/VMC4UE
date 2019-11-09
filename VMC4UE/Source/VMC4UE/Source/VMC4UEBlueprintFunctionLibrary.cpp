// Fill out your copyright notice in the Description page of Project Settings.

#include "../Include/VMC4UEBlueprintFunctionLibrary.h"
#include "../Include/VMC4UEStreamingData.h"

void UVMC4UEBlueprintFunctionLibrary::OnReceivedVMC(UVMC4UEStreamingSkeletalMeshTransform *SkeletalMeshTransform, const FName &Address, const TArray<FOscDataElemStruct> &Data, const FString &SenderIp)
{
	if (SkeletalMeshTransform == nullptr)
	{
		return;
	}

    const FString AddressString = Address.ToString();
    if (AddressString == TEXT("/VMC/Ext/Bone/Pos"))
    {
        if (Data.Num() != 8)
        {
            return;
        }
        int32 Index = 0;

        const FName BoneName = Data[Index++].GetValue<FName>();
        FVMC4UEStreamingBoneTransform &VMCBone = SkeletalMeshTransform->Bones.FindOrAdd(BoneName);

        const float UnityLocationX = Data[Index++].GetValue<float>();
        const float UnityLocationY = Data[Index++].GetValue<float>();
        const float UnityLocationZ = Data[Index++].GetValue<float>();
        const float UnityRotationX = Data[Index++].GetValue<float>();
        const float UnityRotationY = Data[Index++].GetValue<float>();
        const float UnityRotationZ = Data[Index++].GetValue<float>();
        const float UnityRotationW = Data[Index++].GetValue<float>();

		VMCBone.Location.X = -UnityLocationX * 100.0f;
		VMCBone.Location.Y = UnityLocationZ * 100.0f;
		VMCBone.Location.Z = UnityLocationY * 100.0f;

		VMCBone.Rotation.X = -UnityRotationX;
		VMCBone.Rotation.Y = UnityRotationZ;
		VMCBone.Rotation.Z = UnityRotationY;
		VMCBone.Rotation.W = UnityRotationW;
	}
    else if (AddressString == TEXT("/VMC/Ext/Root/Pos"))
    {
        int32 Index = 0;

        FVMC4UEStreamingBoneTransform &VMCBone = SkeletalMeshTransform->Root;

        ++Index;
        const float UnityLocationX = Data[Index++].GetValue<float>();
        const float UnityLocationY = Data[Index++].GetValue<float>();
        const float UnityLocationZ = Data[Index++].GetValue<float>();
        const float UnityRotationX = Data[Index++].GetValue<float>();
        const float UnityRotationY = Data[Index++].GetValue<float>();
        const float UnityRotationZ = Data[Index++].GetValue<float>();
        const float UnityRotationW = Data[Index++].GetValue<float>();

        VMCBone.Location.X = -UnityLocationX * 100.0f;
        VMCBone.Location.Y = UnityLocationZ * 100.0f;
        VMCBone.Location.Z = UnityLocationY * 100.0f;

        VMCBone.Rotation.X = -UnityRotationX;
        VMCBone.Rotation.Y = UnityRotationZ;
        VMCBone.Rotation.Z = UnityRotationY;
        VMCBone.Rotation.W = UnityRotationW;
    }
}

void UVMC4UEBlueprintFunctionLibrary::CreateObject(UClass *ObjectClass, UObject* &CreatedObject)
{
	CreatedObject = NewObject<UObject>((UObject*)GetTransientPackage(), ObjectClass);
}
