#pragma once
#include "Curve.h"

class Helix : public Curve
{
public:
	float Radius;
	float Step;

	Helix(float radius, float step);
	Vector3 getPoint(float t) override;
	Vector3 getDerivative(float t) override;
};

