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

	if (AddressString == TEXT("/VMC/Ext/Root/Pos"))
	{
		if (Data.Num() < 7)
		{
			return;
		}
		int32 Index = 0;

		FRWScopeLock RWScopeLock(SkeletalMeshTransform->RWLock, FRWScopeLockType::SLT_Write);
		
		++Index;
		const auto UnityLocationX = Data[Index++].GetValue<float>();
		const auto UnityLocationY = Data[Index++].GetValue<float>();
		const auto UnityLocationZ = Data[Index++].GetValue<float>();
		const auto UnityRotationX = Data[Index++].GetValue<float>();
		const auto UnityRotationY = Data[Index++].GetValue<float>();
		const auto UnityRotationZ = Data[Index++].GetValue<float>();
		const auto UnityRotationW = Data[Index++].GetValue<float>();

		auto& VMCBone = SkeletalMeshTransform->Root;

		VMCBone.Location.X = -UnityLocationX * 100.0f;
		VMCBone.Location.Y = UnityLocationZ * 100.0f;
		VMCBone.Location.Z = UnityLocationY * 100.0f;

		VMCBone.Rotation.X = -UnityRotationX;
		VMCBone.Rotation.Y = UnityRotationZ;
		VMCBone.Rotation.Z = UnityRotationY;
		VMCBone.Rotation.W = UnityRotationW;
	}
	else if (AddressString == TEXT("/VMC/Ext/Bone/Pos"))
    {
        if (Data.Num() < 8)
        {
            return;
        }
        int32 Index = 0;

		FRWScopeLock RWScopeLock(SkeletalMeshTransform->RWLock, FRWScopeLockType::SLT_Write);
		
        const auto BoneName = Data[Index++].GetValue<FName>();
        const auto UnityLocationX = Data[Index++].GetValue<float>();
        const auto UnityLocationY = Data[Index++].GetValue<float>();
        const auto UnityLocationZ = Data[Index++].GetValue<float>();
        const auto UnityRotationX = Data[Index++].GetValue<float>();
        const auto UnityRotationY = Data[Index++].GetValue<float>();
        const auto UnityRotationZ = Data[Index++].GetValue<float>();
        const auto UnityRotationW = Data[Index++].GetValue<float>();

		auto& VMCBone = SkeletalMeshTransform->Bones.FindOrAdd(BoneName);

		VMCBone.Location.X = -UnityLocationX * 100.0f;
		VMCBone.Location.Y = UnityLocationZ * 100.0f;
		VMCBone.Location.Z = UnityLocationY * 100.0f;

		VMCBone.Rotation.X = -UnityRotationX;
		VMCBone.Rotation.Y = UnityRotationZ;
		VMCBone.Rotation.Z = UnityRotationY;
		VMCBone.Rotation.W = UnityRotationW;
	}
	else if (AddressString == TEXT("/VMC/Ext/Blend/Val"))
	{
		if (Data.Num() < 2)
		{
			return;
		}
		int32 Index = 0;

		const auto Name = Data[Index++].GetValue<FName>();
		const auto Value = Data[Index++].GetValue<float>();

		auto& TargetBlendShape = SkeletalMeshTransform->FutureBlendShapes.FindOrAdd(Name);

		TargetBlendShape = Value;
	}
	else if (AddressString == TEXT("/VMC/Ext/Blend/Apply"))
	{
		FRWScopeLock RWScopeLock(SkeletalMeshTransform->RWLock, FRWScopeLockType::SLT_Write);
		
		SkeletalMeshTransform->CurrentBlendShapes.Empty();
		for (auto& FutureBlendShape : SkeletalMeshTransform->FutureBlendShapes)
		{
			SkeletalMeshTransform->CurrentBlendShapes.FindOrAdd(FutureBlendShape.Key);
			SkeletalMeshTransform->CurrentBlendShapes[FutureBlendShape.Key] = FutureBlendShape.Value;
		}
		SkeletalMeshTransform->FutureBlendShapes.Empty();
	}
}

void UVMC4UEBlueprintFunctionLibrary::CreateObject(UClass *ObjectClass, UObject* &CreatedObject)
{
	CreatedObject = NewObject<UObject>((UObject*)GetTransientPackage(), ObjectClass);
}
