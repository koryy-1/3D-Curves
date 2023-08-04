#pragma once
#include "Curve.h"

class Ellipse : public Curve
{
private:
	float RadiusX;
	float RadiusY;
public:
	Ellipse(float radiusX, float radiusY);
	float getRadiusX();
	float getRadiusY();
	Vector3* getPoint(float t) override;
	Vector3* getDerivative(float t) override;
};

