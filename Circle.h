#pragma once
#include "Curve.h"

class Circle : public Curve
{
public:
	float Radius;

	Circle(float radius);
	Vector3 getPoint(float t) override;
	Vector3 getDerivative(float t) override;
};

