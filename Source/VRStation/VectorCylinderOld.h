// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



/**
 * A cylindrical coordinate system with methods to convert to and from Cartesian
 * Designed for character movement under the static friction regime
 */
class VRSTATION_API VectorCylinder
{
private:
	UPROPERTY(BlueprintReadOnly, Category = )
	double rho; //Axial distance, radius from the center

	UPROPERTY(BlueprintReadOnly)
	double phi; //Azimuth, distance along the circumference of cylinder

	UPROPERTY(BlueprintReadOnly)
	double z; //Height along z-axis

public:

	VectorCylinder();
	~VectorCylinder();
};
