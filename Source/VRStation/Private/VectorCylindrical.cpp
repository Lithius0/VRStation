// Fill out your copyright notice in the Description page of Project Settings.


#include "VectorCylindrical.h"

FCylindricalCoordinates UVectorCylindrical::MakeVectorCylindrical(float Rho, float Phi, float Z)
{
	FCylindricalCoordinates newVector = FCylindricalCoordinates();

	newVector.Rho = Rho;
	newVector.Z = Z;
	newVector.setPhi(Phi);

	return newVector;
}

void UVectorCylindrical::BreakVector(FCylindricalCoordinates& InVector, float& Rho, float& Phi, float& Z)
{
	Rho = InVector.Rho;
	Phi = InVector.getPhi();
	Z = InVector.Z;
}

FVector UVectorCylindrical::ConvertToCartesian(FCylindricalCoordinates VectorToConvert)
{
	float x = VectorToConvert.Rho * cos(VectorToConvert.getPhi());
	float y = VectorToConvert.Rho * sin(VectorToConvert.getPhi());
	//Z is the same in both coordinate systems

	return FVector(x, y, VectorToConvert.Z);
}

FCylindricalCoordinates UVectorCylindrical::ConvertToCylindrical(FVector VectorToConvert)
{
	float rho = VectorToConvert.Size(); // Rho is just the length of the cartesian vector
	float phi = 0; // Phi is a little complicated
	if (VectorToConvert.X > 0) {
		phi = atan(VectorToConvert.Y / VectorToConvert.X);
	}
	else {

	}
	// Z is the same in both coordinate systems

	return FCylindricalCoordinates();
}
