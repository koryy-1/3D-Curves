#include "Circle.h"
#include <cmath>

Circle::Circle(float radius)
{
	Radius = radius;
}

float Circle::getRadius()
{
	return Radius;
}

Vector3* Circle::getPoint(float t)
{
	float x = Radius * cos(t);
	float y = Radius * sin(t);
	return new Vector3(x, y, 0);
}

Vector3* Circle::getDerivative(float t)
{
	float dx_dt = -Radius * sin(t);
	float dy_dt = Radius * cos(t);
	return new Vector3(dx_dt, dy_dt, 0);
}
