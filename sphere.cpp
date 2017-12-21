#include "sphere.h"

Sphere::Sphere()
{
    radius = 1;
}

Sphere::Sphere(double radius)
{
    this->radius = radius;
}

Sphere::Sphere(const Sphere &source)
{
    coordinates = source.coordinates;
    radius = source.radius;
    volume = source.volume;
}

double Sphere::getRadius()
{
    return radius;
}

void Sphere::setRadius(double radius)
{
    this->radius = radius;
}

double Sphere::countVolume()
{
    return 4/3 * PI * pow(radius, 3.0);
}

type Sphere::getType()
{
    return SPHERE;
}
