#pragma once
#include "Curve.h"

class Ellipse : public Curve
{
public:
	float RadiusX;
	float RadiusY;

	Ellipse(float radiusX, float radiusY);
	Vector3 getPoint(float t) override;
	Vector3 getDerivative(float t) override;
};

