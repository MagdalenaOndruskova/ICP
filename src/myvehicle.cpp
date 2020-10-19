#include "myvehicle.h"
#include <QPen>
#include <QBrush>
#include <QDebug>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>
#include "mystreet.h"
#include "mystop.h"


MyVehicle::MyVehicle(QGraphicsEllipseItem *parent):
    QObject(),
    QGraphicsEllipseItem(parent)
{
    setFlag(QGraphicsItem::ItemIsSelectable);
}

void MyVehicle::setId(int id)
{
    this->id = id;
}

int MyVehicle::getId()
{
    return this->id;
}

void MyVehicle::setSpeed(double speed)
{
    this->speed = speed;
}

double MyVehicle::getSpeed()
{
    return this->speed;
}

void MyVehicle::setLine(MyLine *line)
{
    this->line = line;
}

MyLine* MyVehicle::getLine()
{
    return this->line;
}

void MyVehicle::setCurrentPosition(MyCoordinate coor)
{
    this->current_position = coor;
}

MyCoordinate MyVehicle::getCurrentPosition()
{
    return this->current_position;
}

void MyVehicle::setStartPosition(MyCoordinate coor)
{
    this->start_position = coor;
}

MyCoordinate MyVehicle::getStartPosition()
{
    return start_position;
}

MyCoordinate MyVehicle::countNewCurrentPosition(double distance)
{
    double length = 0;
    MyCoordinate coor1;
    MyCoordinate coor2;

    for (int i = 0 ; i < line->getPath().size()-1; i++)
    {
        coor1 = line->getPath().value(i);
        coor2 = line->getPath().value(i+1);
        if (length + coor1.countVector(coor1, coor2) > distance)
            break;
        length += coor1.countVector(coor1, coor2);
    }
    current_street = line->findCurrentStreet(coor1, coor2);
    double driven = (distance-length )/ coor1.countVector(coor1, coor2);
    MyCoordinate new_coor;
    new_coor.setX(coor1.x() + (coor2.x() - coor1.x())*driven);
    new_coor.setY(coor1.y() + (coor2.y() - coor1.y())*driven);
    return new_coor;
}

void MyVehicle::updatePositionInTime()
{
    distance += speed;
    double length = line->getPathLength();
    if (length < distance)
    {
       auto new_coor = line->getPath().value(line->getPath().size()-1);
       setCurrentPosition(new_coor);
       setRect(QRectF(current_position.x()-5, current_position.y()-5, 10,10));
    } else
    {
        auto new_coor = countNewCurrentPosition(distance);
        setCurrentPosition(new_coor);
        setRect(QRectF(current_position.x()-5, current_position.y()-5, 10,10));
    }
}

void MyVehicle::setCurrentStreet(MyStreet *street)
{
    this->current_street = street;
}

MyStreet *MyVehicle::getCurrentStreet()
{
    return this->current_street;
}

void MyVehicle::setDefaultSpeed(double default_speed)
{
    this->default_speed = default_speed;
}

double MyVehicle::getDefaultSpeed()
{
    return this->default_speed;
}

void MyVehicle::setStartTime()
{
    this->start_time = time_schedule.value(0);
}

QTime MyVehicle::getStartTime()
{
    return start_time;
}

void MyVehicle::setRemoved()
{
    this->removed = true;
}

bool MyVehicle::getRemoved()
{
    return this->removed;
}

void MyVehicle::unsetRemoved()
{
    this->removed = false;
}

void MyVehicle::setShowSchedule()
{
    this->showSchedule = true;
}

bool MyVehicle::getShowSchedule()
{
    return this->showSchedule;
}

void MyVehicle::unsetShowSchedule()
{
    this->showSchedule = false;
}

void MyVehicle::setDistance(double distance)
{
    this->distance = distance;
}

void MyVehicle::slowDown(int traffic)
{
    double vehicle_speed = this->speed;
    while ( traffic > 0)
    {
        vehicle_speed -= 0.5;
        if (vehicle_speed < 0.5)
        {
            vehicle_speed = 0.5; // najpomalsia rychlost
            break;
        }
        traffic -= 1;
    }
    this->speed = vehicle_speed;
}

QList<MyStop *> MyVehicle::getVisitedStops()
{
    return this->visited_stops;
}

void MyVehicle::updateCurrentPositionInTime(QTime time)
{

    int numberStops = 0;
    foreach (auto time_sche, time_schedule) {
        if (time_sche < time)
            numberStops++;
    }
    for (int i = 0; i < numberStops-1; ++i) {
        visited_stops.append(line->getStops().value(i));
        time = time.addSecs(-30);
    }

    time = time.addSecs(30);

    while (time > start_time)
    {
        time = time.addSecs(-30);
        updatePositionInTime();
    }
}

void MyVehicle::setVisitedStopsToNone()
{
    visited_stops.clear();
}

void MyVehicle::findClosedStreetFirst()
{
    if (current_street->getClosed())
    {
        current_position = line->getPath().value(1);
        distance = current_street->getStartCoor().countVector(current_street->getStartCoor(), current_street->getEndCoor());
    }
    else current_position = start_position;
}

void MyVehicle::checkTraffic(QTime time)
{
    if (current_street->getTraffic() != 1 &&  start_time < time && !removed)
    {
        speed = default_speed;
        slowDown(current_street->getTraffic());
    } else speed = default_speed;
}

void MyVehicle::isAtStop()
{

        if (std::abs(((std::abs(current_street->getStopOnStreet()->getCoordinate().x())) - std::abs((current_position.x())))) < 2)
        {
            if (std::abs(((std::abs(current_street->getStopOnStreet()->getCoordinate().y())) - std::abs((current_position.y())))) < 2)
            {
                if (timer_stick == 0)
                {
                    visited_stops.append(current_street->getStopOnStreet());
                    timer_stick = 1;
                }
                else
                {
                    timer_stick = 0;
                    speed = default_speed;
                }
            }
        }
        if (timer_stick != 0)
            speed =0;

}

void MyVehicle::moveVehicle(QTime time)
{
    if (start_time <= time && !removed )
    {
        isAtStop();
        findClosedStreetLast();
        updatePositionInTime();
    }
}

void MyVehicle::findClosedStreetLast()
{
    if (line->getPathStreets().value(line->getPathStreets().size()-1)->getClosed())
        line->removeLastStreetFromPath();
}

QList<QTime> MyVehicle::getTime_schedule()
{
    return time_schedule;
}

void MyVehicle::setTime_schedule(QList<QString> value)
{
    const QString format = "hh:mm:ss";
    foreach (auto time, value)
        time_schedule.append(QTime::fromString(time, format));
}

void MyVehicle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QColor vehicle_color;
    if (this->getLine()->getId() == 10)
        vehicle_color = QColor (Qt::yellow);
    else if (this->getLine()->getId() == 20)
        vehicle_color = QColor (Qt::blue);
    else if (this->getLine()->getId() == 30)
        vehicle_color = QColor (Qt::red);
    else if (this->getLine()->getId() == 40)
        vehicle_color = QColor (Qt::green);

    painter->setPen(QPen({vehicle_color}, 2));
    painter->setBrush(QBrush(vehicle_color));
    painter->drawEllipse(QPointF(current_position),5,5);
}

QRectF MyVehicle::boundingRect() const
{
    QPainterPath painterPath;
    painterPath.addRect(QGraphicsEllipseItem::boundingRect());
    return painterPath.boundingRect();
}


