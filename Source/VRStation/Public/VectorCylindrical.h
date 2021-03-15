// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VectorCylindrical.generated.h"

/**
 * 
 */
UCLASS()
class VRSTATION_API UVectorCylindrical : public UObject
{
	GENERATED_BODY()


private:
	float Rho; //Axial distance, radius from the center
	float Z; //Height along z-axis
	float Phi; //Azimuth, distance along the circumference of cylinder, measured in radians

	
public:

	/** Breaks apart a vector into rho, phi and z */
	UFUNCTION(BlueprintPure, meta = (Keywords = "construct build cylinder", NativeMakeFunc))
	static UVectorCylindrical* MakeVectorCylindrical(float Rho, float Phi, float Z);

	UFUNCTION(BlueprintPure, meta = (NativeBreakFunc))
	void BreakVector(UVectorCylindrical* InVector, float& Rho, float& Phi, float& Z);

	UFUNCTION(BlueprintPure)
	FVector ConvertCylindricalToCartesian(UVectorCylindrical* InVector);

	// Converts a cartesian vector to a cylindrical one
	UFUNCTION(BlueprintPure)
	static UVectorCylindrical* ConvertCartesianToCylindrical(FVector InVector);

	/** Converts a cylindrical vector value to a string, in the form 'Rho= Phi= Z=' */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (CylindricalVector)", CompactNodeTitle = "->", BlueprintAutocast))
	static FString ConvertCylindricalVectorToString(UVectorCylindrical* InVectorCylindrical);

	// Default constructor, sets everything to 0
	UVectorCylindrical();

	// Constructor, sets object values to the values given, Phi gets restricted between 0 and 2 pi
	UVectorCylindrical(float newRho, float newPhi, float newZ);

	// Setter function for Rho
	void setRho(const float newRho);
	
	// Getter function for Rho
	float getRho();

	// Setter function that restricts phi to between 0 and 2 pi
	void setPhi(const float newPhi);

	// Getter function for Phi
	float getPhi();

	// Setter function for Z
	void setZ(const float newZ);

	// Getter function for Z
	float getZ();
};
	
