#include "mystreet.h"
#include <QDebug>
#include <QPen>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include "mystop.h"

MyStreet::MyStreet(QGraphicsLineItem *parent) :
    QGraphicsLineItem(parent)
{
    //konstruktor
    setPen(QPen({Qt::blue},2));
    setFlag(QGraphicsItem::ItemIsSelectable);
}

void MyStreet::setName(QString name)
{
    this->name = name;
}

QString MyStreet::getName()
{
    return this->name;
}

void MyStreet::setStartCoor(MyCoordinate start)
{
    this->start_coor = start;
}

MyCoordinate MyStreet::getStartCoor()
{
    return this->start_coor;
}

void MyStreet::setEndCoor(MyCoordinate end)
{
    this->end_coor = end;
}

MyCoordinate MyStreet::getEndCoor()
{
    return this->end_coor;
}

void MyStreet::setStopOnStreet(MyStop *stop){
    this->StopOnStreet = stop;
}

MyStop* MyStreet::getStopOnStreet(){
    return this->StopOnStreet;
}

void MyStreet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setLine(QLineF(start_coor.x(),start_coor.y(),end_coor.x(),end_coor.y()));
    painter->setPen(pen());
    painter->drawLine(line());
}

QRectF MyStreet::boundingRect() const
{
    QPainterPath painterPath;
    painterPath.addRect(QGraphicsLineItem::boundingRect());
    return painterPath.boundingRect();
}

void MyStreet::setClosed()
{
    this->closed = true;
}

void MyStreet::setOpen()
{
    this->closed = false;
}

void MyStreet::setTraffic(int traffic)
{
    this->traffic = traffic;
}

void MyStreet::riseTraffic()
{
    traffic += 1;
}

int MyStreet::getTraffic()
{
    return this->traffic;
}

bool MyStreet::getClosed()
{
    return closed;
}

