#include "mystop.h"
#include <QDebug>
#include <QPainter>
#include <QPen>
#include "mystreet.h"

MyStop::MyStop(QGraphicsEllipseItem *parent) :
    QGraphicsEllipseItem(parent)
{
    setPen(QPen(Qt::darkBlue, 2, Qt::DashLine));
}

void MyStop::setCoordinate(MyCoordinate coor)
{
    this->coor = coor;
}

MyCoordinate MyStop::getCoordinate()
{
    return this->coor;
}

void MyStop::setStreet(MyStreet * street)
{
    this->street = street;
}

MyStreet * MyStop::getStreet()
{
    return this->street;
}

void MyStop::setName(QString name)
{
    this->name = name;
}

QString MyStop::getName()
{
    return this->name;
}


void MyStop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setRect(QRectF(coor.x()-7.5,coor.y()-7.5, 15, 15));
    painter->setPen(pen());
    painter-> drawEllipse(rect());
}

QRectF MyStop::boundingRect() const
{
    QPainterPath painterPath;
    painterPath.addRect(QGraphicsEllipseItem::boundingRect());
    return painterPath.boundingRect();
}

