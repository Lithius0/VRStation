// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * A cylindrical coordinate system with methods to convert to and from Cartesian
 * Designed for character movement under the static friction regime
 */
class VRSTATION_API VectorCylindrical
{
public:
	UPROPERTY()
	double rho; //Axial distance, radius from the center

	UPROPERTY()
	double phi; //Azimuth, distance along the circumference of cylinder

	UPROPERTY()
	double z; //Height along z-axis

	VectorCylindrical();
	~VectorCylindrical();
};
