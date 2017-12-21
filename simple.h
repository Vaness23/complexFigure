#include <QString>

struct Coordinates
{
    double x, y, z; // координаты центра фигуры
};

enum type{CUBE, SPHERE};

class Simple
{
public:
    Simple();
    Simple(Coordinates coordinates);
    Simple(const Simple &source);
    Coordinates getCoordinates();
    QString transformCoordinates();
    void setCoordinates(Coordinates coordinates);
    void setCoordinates(double x, double y, double z);
    double getVolume();
    void setVolume(double volume);
    virtual double countVolume();
    virtual type getType();
    void setType(type figureType);
    type figureType; // тип фигуры
protected:
    Coordinates coordinates; // координаты центра фигуры
    double volume; // объем фигуры
};
