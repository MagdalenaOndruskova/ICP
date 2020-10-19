#include "myline.h"
#include <QDebug>

MyLine::MyLine(QObject *parent) : QObject(parent)
{

}

void MyLine::setId(int id)
{
    this->id = id;
}

int MyLine::getId()
{
    return this->id;
}

void MyLine::addStop(MyStop *stop)
{
    stops.append(stop);
}

QList<MyStop *> MyLine::getStops()
{
    return this->stops;
}

void MyLine::setPathByStops()
{
    int max = stops.size();
    for (int i=0; i < max -1; i++)
    {

        auto street1 = stops.value(i)->getStreet();
        MyCoordinate coor1_start = street1->getStartCoor();
        MyCoordinate coor1_end = street1->getEndCoor();
        auto street2 = stops.value(i+1)->getStreet();
        MyCoordinate coor2_start = street2->getStartCoor();
        MyCoordinate coor2_end = street2->getEndCoor();
        if ( (coor1_end == coor2_end || coor1_end == coor2_start)
            && (coor1_start == coor2_end || coor1_start == coor2_start))
            continue;

        if (coor1_end == coor2_start || coor1_end == coor2_end)
        {
            if (path.size() == 0)
                path.append(coor1_start);
            path.append(coor1_end);
        }
        else if ( coor1_start == coor2_start || coor1_start == coor2_end)
        {
            if (path.size() ==0)
                path.append(coor1_end);
            path.append(coor1_start);
        }
        streets.append(street1);
    }
    MyCoordinate last_coor = path.value(path.size()-1);
    MyCoordinate last_street_start = stops.value(max-1)->getStreet()->getStartCoor();
    MyCoordinate last_street_end = stops.value(max-1)->getStreet()->getEndCoor();
    streets.append(stops.value(max-1)->getStreet());
    if (last_coor == last_street_start)
        path.append(last_street_end);
    else path.append(last_street_start);
}

double MyLine::getPathLength()
{
    double size = 0;
    for (int i =0 ; i < path.size()-1; i++)
        size += (path.value(i).countVector(path.value(i), path.value(i+1)));
    return size;
}

MyStreet * MyLine::findCurrentStreet(MyCoordinate coor1, MyCoordinate coor2)
{
    foreach (auto street, streets)
    {
        MyCoordinate street_start = street->getStartCoor();
        MyCoordinate street_end = street->getEndCoor();
        if ((street_start == coor1 || street_start == coor2)
            && (street_end == coor1 || street_end == coor2))
            return street;
    }
}

QList<MyStreet *> MyLine::getPathStreets()
{
    return this->streets;
}

void MyLine::removeLastStreetFromPath()
{
    if (this->removedLastStreet == false )
    {
        path.removeLast();
        this->setRemovedLastStreet();
    }
}

void MyLine::setRemovedLastStreet()
{
    this->removedLastStreet =  true;
}


QList<MyCoordinate > MyLine::getPath()
{
    return this->path;
}
