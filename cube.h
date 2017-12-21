#include <simple.h>

struct Size
{
    double length; // длина параллелепипеда
    double width; // ширина параллелепипеда
    double height; // высота параллелепипеда
};

class Cube: public Simple
{
public:
    Cube();
    Cube(double length, double width, double height);
    Cube(const Cube &source);
    Size getSize();
    void setSize(Size size);
    double countVolume();
    type getType();
private:
    Size size; // размер фигуры
};
