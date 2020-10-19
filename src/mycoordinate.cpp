#include "mycoordinate.h"
#include <QtMath>

#include <QDebug>

MyCoordinate::MyCoordinate() :
    QPointF ()
{

}

double MyCoordinate::diffX(MyCoordinate coor)
{
    double diff = this->x() - coor.x();
    return diff;
}

double MyCoordinate::diffY(MyCoordinate coor)
{
    double diff = this->y() - coor.y();
    return diff;
}

double MyCoordinate::countVector(MyCoordinate start, MyCoordinate end)
{
    double size = qPow(start.diffX(end), 2) + qPow(start.diffY(end), 2);
    return sqrt(size);
}
