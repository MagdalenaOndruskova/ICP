#ifndef MYSTOP_H
#define MYSTOP_H
/**
 * @brief The MyStop class
 * @file mystop.h
 * @authors Magdalena Ondruskova, Zuzana Hradilova
 *
 * This file content the MyStop class whith setting and getting stops
 * and editing its properties.
 */
#include <QGraphicsEllipseItem>
#include "mycoordinate.h"
class MyStreet;

class MyStop : public QGraphicsEllipseItem
{
public:
    /**
     * @brief MyStop constructor and setting pen color
     * @param parent
     */
    MyStop(QGraphicsEllipseItem *parent = nullptr);

    /**
     * @brief setCoordinate function sets stop position
     * @param coor marks coordinates which determine the position of stop
     */
    void setCoordinate(MyCoordinate coor);

    /**
     * @brief getCoordinate function gets stop position
     * @return position of stop
     */
    MyCoordinate getCoordinate();

    /**
     * @brief setStreet function sets street on which is stop located
     * @param street of stop
     */
    void setStreet(MyStreet * street);

    /**
     * @brief getStreet function returns street on which is stop located
     * @return street
     */
    MyStreet * getStreet();

    /**
     * @brief setName function sets street name
     * @param name of the street
     */
    void setName(QString name);

    /**
     * @brief getName function gets name of the street
     * @return name of  the street
     */
    QString getName();


protected:
    /**
     * @brief paint draw stops in map
     * @param painter
     * @param option
     * @param widget
     */
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

    /**
     * @brief boundingRect Function sets rectangle for drawing object
     * @return rectangle
     */
    virtual QRectF boundingRect() const override;

private:
    MyCoordinate  coor;
    MyStreet * street;
    QString name;
};

#endif // MYSTOP_H
