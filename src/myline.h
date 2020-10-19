#ifndef MYLINE_H
#define MYLINE_H
/**
 * @brief The MyLine class
 * @file myline.h
 * @authors Zuzana Hradilova, Magdalena Ondruskova
 *
 * This file represents MyLine class and its functions whith setting and getting lines
 * and editing its properties.
 */
#include <QObject>
#include "mycoordinate.h"
#include "mystop.h"
#include "mystreet.h"

class MyLine : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief MyLine Constructor for class MyLine
     * @param parent default nullptr
     */
    explicit MyLine(QObject *parent = nullptr);

    /**
     * @brief setId Function sets line id
     * @param id id of line
     */
    void setId(int id);

    /**
     * @brief getId Function returns line id
     * @return id
     */
    int getId();

    /**
     * @brief addStop Function adds stop to the list of stops that represents the path
     * @param stop stop to be added
     */
    void addStop(MyStop * stop);

    /**
     * @brief getStops Function returns list of stops that represents the line
     * @return List of stops
     */
    QList<MyStop*> getStops();

    /**
     * @brief setPathByStops Function sets path (list of coordinates) by given stops
     */
    void setPathByStops();

    /**
     * @brief getPath Function returns path (list of coordinates)
     * @return  List of coordinates that represents the path
     */
    QList<MyCoordinate > getPath();

    /**
     * @brief getPathLength Function counts and returns path length
     * @return length of path
     */
    double getPathLength();

    /**
     * @brief findCurrentStreet Function finds current street by given two coordinates
     * @param coor1 One coordinate of street
     * @param coor2 Second coordinate of the street
     * @return Street that has given coordinates like end coordinates
     */
    MyStreet * findCurrentStreet(MyCoordinate coor1, MyCoordinate coor2);

    /**
     * @brief getPathStreets Function returns list of streets that represent the path (all street through which vehicle will be going)
     * @return List of streets
     */
    QList<MyStreet*> getPathStreets();

    /**
     * @brief removeLastStreetFromPath Function removes last street from path
     */
    void removeLastStreetFromPath();

    /**
     * @brief setRemovedLastStreet Function to hold the information, if the last street was removed
     */
    void setRemovedLastStreet();

signals:

private:
    int id;
    QList<MyStop *> stops;
    QList<MyStreet*> streets;
    QList<MyCoordinate > path;
    bool removedLastStreet{false};
};

#endif // MYLINE_H
