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
	float rho = sqrt(VectorToConvert.X * VectorToConvert.X + VectorToConvert.Y * VectorToConvert.Y); // Distance to the Z-Axis
	float phi = 0; // Phi is a little complicated

	// Formulas taken from Wikipedia article on cylindrical coordinate systems
	if (rho > 0) { // If rho is 0, we set phi to 0 otherwise it goes to NaN
		if (VectorToConvert.X >= 0) {
			phi = asin(VectorToConvert.Y / rho);
		}
		else { // X < 0
			phi = -asin(VectorToConvert.Y / rho) + PI;
		}
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


FVectorCylindrical UVectorCylindricalLibrary::MultiplyVectorFloat(FVectorCylindrical vector, float multiplier)
{
	return vector * multiplier;
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
	//Confining the angle between 0 and 2 * pi (tau)
	float x = fmod(newPhi, 2 * PI);
	if (newPhi < 0) {
		x += 2 * PI;
	}

	Phi = x;
}

float FVectorCylindrical::getPhi()
{
	return Phi;
}

FVectorCylindrical FVectorCylindrical::operator+(const FVectorCylindrical vector1)
{
	return FVectorCylindrical(this->Rho + vector1.Rho, this->Phi + vector1.Phi, this->Z + vector1.Z);
}

FVectorCylindrical FVectorCylindrical::operator*(const float multiplier)
{
	return FVectorCylindrical(this->Rho * multiplier, this->Phi * multiplier, this->Z * multiplier);
}
