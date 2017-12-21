#include "cube.h"

Cube::Cube()
{
    size.length = 1;
    size.width = 1;
    size.height = 1;
}

Cube::Cube(double length, double width, double height)
{
    this->size.length = length;
    this->size.width = width;
    this->size.height = height;
}

Cube::Cube(const Cube &source)
{
    coordinates = source.coordinates;
    size = source.size;
    volume = source.volume;
}

Size Cube::getSize()
{
    return size;
}

void Cube::setSize(Size size)
{
    this->size = size;
}

double Cube::countVolume()
{
    return size.length * size.width * size.height;
}

type Cube::getType()
{
    return CUBE;
}
