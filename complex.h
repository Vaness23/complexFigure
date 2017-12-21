#include <simple.h>

struct Figure
{
    Simple *info;
    Figure *next, *prev;
};

class Complex
{
public:
    Complex();
    void addFigure(Coordinates coordinates, double volume, int position);
    void deleteFigure(int position);
    int getComplexSize();
    bool checkCrossing(); // пересечение фигур
    Figure* getFirst();
private:
    Figure *first, *last;
    int complexSize;
};
