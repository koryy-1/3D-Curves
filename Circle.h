#pragma once
#include "Curve.h"

class Circle : public Curve
{
private:
	float Radius;
public:
	Circle(float radius);
	float getRadius();
	Vector3* getPoint(float t) override;
	Vector3* getDerivative(float t) override;
};

