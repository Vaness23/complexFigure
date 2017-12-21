#include "complex.h"
#include <iostream>

Complex::Complex()
{
    first = last = NULL;
}

void Complex::addFigure(Coordinates coordinates, double volume, int position)
{
    Figure *curr = new Figure;
    Simple *info = new Simple;

    info->setCoordinates(coordinates);
    info->setVolume(volume);
    info->figureType = info->getType();
    curr->info = info;

    if (first)
    {
        if (position == 0)
        {
            curr->prev = last;
            curr->next = NULL;
            last->next = curr;
            last = curr;
        }
        else
        {
           curr->next = first;
           curr->prev = NULL;
           first->prev = curr;
           first = curr;
        }
    }
    else
    {
        first = last = curr;
        curr->next = curr->prev = NULL;
    }
}

void Complex::deleteFigure(int position)
{
    Figure *del;

    if (position == 0)
    {
        del = last;

        if (del->prev)
        {
            del->prev->next = NULL;
            last = del->prev;
        }
        else
        {
            first = NULL;
            last = NULL;
        }
    }
    else
    {
        del = first;

        if (del->next)
        {
            del->next->prev = NULL;
            first = del->next;
        }
        else
        {
            first = NULL;
            last = NULL;
        }
    }

    delete del;
}

int Complex::getComplexSize()
{
    return complexSize;
}

bool Complex::checkCrossing()
{
    // реализация пересечения фигур (пересекаются или нет)
}

Figure *Complex::getFirst()
{
    return first;
}
