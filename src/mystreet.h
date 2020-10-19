#ifndef MYSTREET_H
#define MYSTREET_H

/**
 * @brief The Mytreet class
 * @file mystreet.h
 * @authors Magdalena Ondruskova, Zuzana Hradilova
 *
 * This file represents the MyStreet class whith setting and getting street
 * and editing its properties.
 */

#include "mycoordinate.h"
#include <QGraphicsLineItem>
class MyStop;

class MyStreet : public  QGraphicsLineItem
{
public:
    /**
     * @brief MyStreet constructor and setting pen color
     * @param parent
     */
    MyStreet(QGraphicsLineItem *parent = nullptr);

    /**
     * @brief setName sets name of street
     * @param name name in QString format
     */
    void setName(QString name);

    /**
     * @brief getName returns name of street
     * @return name in QString format
     */
    QString getName();

    /**
     * @brief setStartCoor sets coordinates of place where street starts
     * @param start coordinates of street start
     */
    void setStartCoor(MyCoordinate start);

    /**
     * @brief getStartCoor returns coordinates of place where street starts
     * @return Coordinates start coordinates of the street
     */
    MyCoordinate getStartCoor();

    /**
     * @brief setEndCoor sets coordinates of place where street ends
     * @param end coordinates of street end
     */
    void setEndCoor(MyCoordinate end);

    /**
     * @brief getEndCoor returns coordinates of place where street ends
     * @return Coordinates end coordinates of the street
     */
    MyCoordinate getEndCoor();

    /**
     * @brief setStopOnStreet sets stop which is located on the street
     * @param stop that is located on the street
     */
    void setStopOnStreet(MyStop *stop);

    /**
     * @brief getStopOnStreet returns stop which is located on the street
     * @return stop in MyStop class
     */
    MyStop* getStopOnStreet();

    /**
     * @brief setTraffic sets traffic of the street (default value of trafic is 0).
     *        The higher number, the slower vehicle pass the street.
     * @param traffic value of traffic
     */
    void setTraffic(int traffic);

    /**
     * @brief riseTraffic add one point more to traffic of  street
     */
    void riseTraffic();

    /**
     * @brief getTraffic returns traffic of the  street
     * @return value of traffic
     */
    int getTraffic();

    /**
     * @brief setClosed Sets street closed
     */
    void setClosed();

    /**
     * @brief getClosed returns if street is closed
     * @return true if street is closed, or false if its not closed
     */
    bool getClosed();

    /**
     * @brief setOpen opens closed street
     */
    void setOpen();

protected:
    /**
     * @brief paint draw streets on map
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
    QString name;
    MyCoordinate  start_coor;
    MyCoordinate end_coor;
    MyStop *StopOnStreet;
    int traffic{0};
    bool closed{false};
};

#endif // MYSTREET_H
