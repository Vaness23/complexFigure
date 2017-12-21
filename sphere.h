#include <simple.h>
#include <math.h>

class Sphere: public Simple
{
public:
    Sphere();
    Sphere(double radius);
    Sphere(const Sphere &source);
    double getRadius();
    void setRadius(double radius);
    double countVolume();
    type getType();
private:
    double radius; // радиус сферы
    const double PI = 3.14;
};
