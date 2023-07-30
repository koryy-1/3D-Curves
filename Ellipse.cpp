#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse(float radiusX, float radiusY)
{
	RadiusX = radiusX;
	RadiusY = radiusY;
}

Vector3 Ellipse::getPoint(float t)
{
	float x = RadiusX * cos(t);
	float y = RadiusY * sin(t);
	return Vector3(x, y, 0);
}

Vector3 Ellipse::getDerivative(float t)
{
	float dx_dt = -RadiusX * sin(t);
	float dy_dt = RadiusY * cos(t);

	return Vector3(dx_dt, dy_dt, 0);
}
