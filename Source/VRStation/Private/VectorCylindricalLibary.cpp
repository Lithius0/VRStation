// Fill out your copyright notice in the Description page of Project Settings.


#include "VectorCylindricalLibrary.h"

FVectorCylindrical UVectorCylindricalLibrary::MakeVectorCylindrical(float Rho, float Phi, float Z)
{
	return FVectorCylindrical(Rho, Phi, Z);
}

void UVectorCylindricalLibrary::BreakVector(FVectorCylindrical InVector, float& Rho, float& Phi, float& Z)
{
	Rho = InVector.Rho;
	Phi = InVector.getPhi();
	Z = InVector.Z;
}

FVector UVectorCylindricalLibrary::ConvertCylindricalToCartesian(FVectorCylindrical VectorToConvert)
{
	// Formulas taken from Wikipedia article on cylindrical coordinate systems
	float x = VectorToConvert.Rho * cos(VectorToConvert.getPhi());
	float y = VectorToConvert.Rho * sin(VectorToConvert.getPhi());
	//Z is the same in both coordinate systems

	return FVector(x, y, VectorToConvert.Z);
}

FVectorCylindrical UVectorCylindricalLibrary::ConvertCartesianToCylindrical(FVector VectorToConvert)
{
	float rho = VectorToConvert.Size(); // Rho is just the length of the cartesian vector
	float phi = 0; // Phi is a little complicated

	// Formulas taken from Wikipedia article on cylindrical coordinate systems
	if (VectorToConvert.X >= 0) {
		phi = asin(VectorToConvert.Y / rho);
	}
	else { // X < 0
		phi = -asin(VectorToConvert.Y / rho) + PI;
	}
	// Z is the same in both coordinate systems

	return FVectorCylindrical(rho, phi, VectorToConvert.Z);
}

FString UVectorCylindricalLibrary::ConvertCylindricalVectorToString(FVectorCylindrical InVectorCylindrical)
{
	return FString::Printf(TEXT("Rho=%f Phi=%f Z=%f"), InVectorCylindrical.Rho, InVectorCylindrical.getPhi(), InVectorCylindrical.Z);
}

FVectorCylindrical UVectorCylindricalLibrary::AddVectorVector(FVectorCylindrical vector1, FVectorCylindrical vector2)
{
	return vector1 + vector2;
}

FVectorCylindrical::FVectorCylindrical()
{
	Rho = 0;
	Phi = 0;
	Z = 0;
}

FVectorCylindrical::FVectorCylindrical(float newRho, float newPhi, float newZ)
{
	Rho = newRho;
	setPhi(newPhi);
	Z = newZ;
}

void FVectorCylindrical::setPhi(const float newPhi)
{
	//Confining the angle between 0 and 2 * pi
	Phi = (newPhi > 0) ? (fmod(newPhi, 2 * PI)) : (fmod(-newPhi, 2 * PI));
}

float FVectorCylindrical::getPhi()
{
	return Phi;
}

FVectorCylindrical FVectorCylindrical::operator+(const FVectorCylindrical vector1)
{
	return FVectorCylindrical(this->Rho + vector1.Rho, this->Phi + vector1.Phi, this->Z + vector1.Z);
}
