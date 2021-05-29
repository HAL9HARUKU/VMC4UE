// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "VMC4UEBoneMappingAssetFactory.generated.h"

/**
 * 
 */
UCLASS()
class VMC4UEED_API UVMC4UEBoneMappingAssetFactory : public UFactory
{
    GENERATED_BODY()

    UVMC4UEBoneMappingAssetFactory(const FObjectInitializer &ObjectInitializer);

    virtual bool DoesSupportClass(UClass *Class) override;
    virtual UClass *ResolveSupportedClass() override;

	virtual UObject* FactoryCreateText(
		UClass* InClass,
		UObject* InParent,
		FName InName,
		EObjectFlags Flags,
		UObject* Context,
		const TCHAR* Type,
		const TCHAR*& Buffer,
		const TCHAR* BuferEnd,
		FFeedbackContext* Warn
	) override;
};
