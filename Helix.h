#pragma once
#include "Curve.h"

class Helix : public Curve
{
private:
	float Radius;
	float Step;
public:
	Helix(float radius, float step);
	float getRadius();
	float getStep();
	Vector3* getPoint(float t) override;
	Vector3* getDerivative(float t) override;
};

