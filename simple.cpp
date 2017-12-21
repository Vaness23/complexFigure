#include "simple.h"

Simple::Simple()
{
    coordinates.x = 0;
    coordinates.y = 0;
    coordinates.z = 0;
}

Simple::Simple(Coordinates coordinates)
{
    this->coordinates.x = coordinates.x;
    this->coordinates.y = coordinates.y;
    this->coordinates.z = coordinates.z;
}

Simple::Simple(const Simple &source)
{
    coordinates = source.coordinates;
    volume = source.volume;
}

Coordinates Simple::getCoordinates()
{
    return coordinates;
}

QString Simple::transformCoordinates()
{
    QString x = QString::number(coordinates.x);
    QString y = QString::number(coordinates.y);
    QString z = QString::number(coordinates.z);
    return x + "; " + y + "; " + z;
}

void Simple::setCoordinates(Coordinates coordinates)
{
    this->coordinates.x = coordinates.x;
    this->coordinates.y = coordinates.y;
    this->coordinates.z = coordinates.z;
}

void Simple::setCoordinates(double x, double y, double z)
{
    this->coordinates.x = x;
    this->coordinates.y = y;
    this->coordinates.z = z;
}

double Simple::getVolume()
{
    return volume;
}

void Simple::setVolume(double volume)
{
    this->volume = volume;
}

double Simple::countVolume()
{
    return 0;
}

type Simple::getType()
{
    return CUBE;
}

void Simple::setType(type figureType)
{
    this->figureType = figureType;
}
