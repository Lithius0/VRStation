// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VectorCylindricalLibrary.generated.h"

USTRUCT(BlueprintType)
struct VRSTATION_API FVectorCylindrical
{
	GENERATED_BODY()

public:
	float Rho; //Axial distance, radius from the center
	float Z; //Height along z-axis
private:
	float Phi; //Azimuth, distance along the circumference of cylinder, measured in radians

public:
	// Default constructor, sets everything to 0
	FVectorCylindrical();

	// Constructor, sets object values to the values given, Phi gets restricted between 0 and 2 pi
	FVectorCylindrical(float newRho, float newPhi, float newZ);

	// Setter function that restricts phi to between 0 and 2 pi
	void setPhi(const float newPhi);

	// Getter function for Phi
	float getPhi();

	// Overloaded add operator, adds every coordinate separately
	FVectorCylindrical operator+(const FVectorCylindrical vector1);

};


/**
 * 
 */
UCLASS()
class VRSTATION_API UVectorCylindricalLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


private:
	float Rho; //Axial distance, radius from the center
	float Z; //Height along z-axis
	float Phi; //Azimuth, distance along the circumference of cylinder, measured in radians

	
public:

	/** Breaks apart a vector into rho, phi and z */
	UFUNCTION(BlueprintPure, meta = (Keywords = "construct build cylinder", NativeMakeFunc))
	static FVectorCylindrical MakeVectorCylindrical(float Rho, float Phi, float Z);

	UFUNCTION(BlueprintPure, meta = (NativeBreakFunc))
	static void BreakVector(FVectorCylindrical InVector, float& Rho, float& Phi, float& Z);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToVector (CylindricalVector)", CompactNodeTitle = "->", BlueprintAutocast))
	static FVector ConvertCylindricalToCartesian(FVectorCylindrical InVector);

	// Converts a cartesian vector to a cylindrical one
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToVectorCylindrical (Vector, Cartesian)", CompactNodeTitle = "->", BlueprintAutocast))
	static FVectorCylindrical ConvertCartesianToCylindrical(FVector InVector);

	/** Converts a cylindrical vector value to a string, in the form 'Rho= Phi= Z=' */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (CylindricalVector)", CompactNodeTitle = "->", BlueprintAutocast))
	static FString ConvertCylindricalVectorToString(FVectorCylindrical InVectorCylindrical);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "VectorCylindrical + VectorCylindrical", CompactNodeTitle = "+", Keywords = "+ add plus", CommutativeAssociativeBinaryOperator = "true"))
	static FVectorCylindrical AddVectorVector(FVectorCylindrical vector1, FVectorCylindrical vector2);
};
	
