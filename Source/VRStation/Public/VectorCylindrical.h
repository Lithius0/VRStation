// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VectorCylindrical.generated.h"

USTRUCT(BlueprintType)
struct VRSTATION_API FCylindricalCoordinates
{
	GENERATED_BODY()

		
	float Rho; //Axial distance, radius from the center
	float Z; //Height along z-axis

private: //phi is an angle and required mod to set
	float Phi; //Azimuth, distance along the circumference of cylinder, measured in radians

public:
	FCylindricalCoordinates()
	{
		Rho = 0;
		Phi = 0;
		Z = 0;
	}

	float getPhi() const {
		return Phi;
	}

	void setPhi(const float newPhi) {
		if (newPhi >= 0) {
			Phi = fmod(newPhi, 2 * PI);
		}
		else {
			Phi = (2 * PI) - fmod(newPhi, 2 * PI);
		}
	}
};

/**
 * 
 */
UCLASS()
class VRSTATION_API UVectorCylindrical : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:
	/** Breaks apart a vector into rho, phi and z */
	UFUNCTION(BlueprintPure, meta = (Keywords = "construct build cylinder", NativeMakeFunc))
	static FCylindricalCoordinates MakeVectorCylindrical(float Rho, float Phi, float Z);

	UFUNCTION(BlueprintPure, meta = (NativeBreakFunc))
	static void BreakVector(FCylindricalCoordinates& InVector, float& Rho, float& Phi, float& Z);

	UFUNCTION(BlueprintPure)
	static FVector ConvertToCartesian(FCylindricalCoordinates VectorToConvert);

	UFUNCTION(BlueprintPure)
	static FCylindricalCoordinates ConvertToCylindrical(FVector VectorToConvert);
};
	
