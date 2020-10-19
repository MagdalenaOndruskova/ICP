#include "myshow.h"
#include <QDebug>
#include <QFile>
#include <QGraphicsSceneMouseEvent>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QColor>

MyShow::MyShow(QObject *parent):
    QGraphicsScene(parent)
{

}

void MyShow::drawLine(MyVehicle * vehicle)
{
    deleteLine();
    auto coor1 = new MyCoordinate;
    coor1->setX(5);
    coor1->setY(150);
    int i = 0;
    int line_lenth = 135;
    foreach (auto stop, vehicle->getLine()->getStops()){
        auto ellipse = new QGraphicsEllipseItem(-15,coor1->y(),15,15);
        ellipse->setPen(QPen({Qt::darkBlue}, 2));
        if (vehicle->getVisitedStops().contains(stop))
            ellipse->setBrush(QBrush(Qt::darkBlue));
        addItem(ellipse);
        auto text = new QGraphicsTextItem(vehicle->getLine()->getStops().value(i)->getName());
        text->setPos(-160,coor1->y()-5);
        text->setFont(QFont("Helvetica", 9));
        addItem(text);
        auto text2 = new QGraphicsTextItem(vehicle->getTime_schedule().value(i+1).toString("hh:mm"));
        text2->setPos(10,coor1->y()-5);
        text2->setFont(QFont("Helvetica", 9));
        addItem(text2);
        coor1->setY(((coor1->y())+30));
        i++;
        line_lenth = line_lenth+30;
    }
    auto line = new QGraphicsLineItem(-7.5,150,-7.5,line_lenth);
    line->setPen(QPen({Qt::darkBlue},2));
    addItem(line);
}

void MyShow::deleteLine()
{
    foreach(auto item, items())
        delete item;
}
