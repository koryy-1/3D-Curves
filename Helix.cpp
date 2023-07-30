#include "Helix.h"
#include <cmath>

Helix::Helix(float radius, float step)
{
    Radius = radius;
    Step = step;
}

Vector3 Helix::getPoint(float t)
{
    float x = Radius * cos(t);
    float y = Radius * sin(t);
    float z = Step * t;
    return Vector3(x, y, z);
}

Vector3 Helix::getDerivative(float t)
{
    float dx_dt = -Radius * sin(t);
    float dy_dt = Radius * cos(t);
    float dz_dt = Step;

    return Vector3(dx_dt, dy_dt, dz_dt);
}
