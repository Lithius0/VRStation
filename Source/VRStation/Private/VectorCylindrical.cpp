// Fill out your copyright notice in the Description page of Project Settings.


#include "VectorCylindrical.h"

UVectorCylindrical* UVectorCylindrical::MakeVectorCylindrical(float Rho, float Phi, float Z)
{
	return &UVectorCylindrical(Rho, Phi, Z);
}

void UVectorCylindrical::BreakVector(UVectorCylindrical* InVector, float& Rho, float& Phi, float& Z)
{
	Rho = InVector->Rho;
	Phi = InVector->Phi;
	Z = InVector->Z;
}

FVector UVectorCylindrical::ConvertCylindricalToCartesian(UVectorCylindrical* VectorToConvert)
{
	float x = VectorToConvert->Rho * cos(VectorToConvert->Phi);
	float y = VectorToConvert->Rho * sin(VectorToConvert->Phi);
	//Z is the same in both coordinate systems

	return FVector(x, y, VectorToConvert->Z);
}

UVectorCylindrical* UVectorCylindrical::ConvertCartesianToCylindrical(FVector VectorToConvert)
{
	float rho = VectorToConvert.Size(); // Rho is just the length of the cartesian vector
	float phi = 0; // Phi is a little complicated
	if (VectorToConvert.X > 0) {
		phi = atan(VectorToConvert.Y / VectorToConvert.X);
	}
	else {

	}
	// Z is the same in both coordinate systems

	return &UVectorCylindrical();
}

FString UVectorCylindrical::ConvertCylindricalVectorToString(UVectorCylindrical* InVectorCylindrical)
{
	return FString::Printf(TEXT("Rho=%f Phi=%f Z=%f"), InVectorCylindrical->getRho(), InVectorCylindrical->getPhi(), InVectorCylindrical->getZ());
}

UVectorCylindrical::UVectorCylindrical()
{
	Rho = 0;
	Phi = 0;
	Z = 0;
}

UVectorCylindrical::UVectorCylindrical(float newRho, float newPhi, float newZ)
{
	Rho = newRho;
	this->setPhi(newPhi);
	Z = newZ;
}

void UVectorCylindrical::setRho(const float newRho)
{
	//Confining the angle between 0 and 2 * pi
	Rho = (newRho > 0) ? (fmod(newRho, 2 * PI)) : (fmod(-newRho, 2 * PI));
}

float UVectorCylindrical::getRho()
{
	return Rho;
}

void UVectorCylindrical::setPhi(const float newPhi) 
{
	Phi = newPhi; // Phi and Z aren't interesting, the domain isn't bounded
}

float UVectorCylindrical::getPhi() 
{
	return Phi;
}

void UVectorCylindrical::setZ(const float newZ)
{
	Z = newZ; // Phi and Z aren't interesting, the domain isn't bounded
}

float UVectorCylindrical::getZ()
{
	return Z;
}

