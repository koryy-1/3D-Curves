#pragma once
#include "Vector3.h"

class Curve
{
public:
	virtual Vector3 getPoint(float t);
	virtual Vector3 getDerivative(float t);
};

