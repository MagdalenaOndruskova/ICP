#ifndef MYVEHICLE_H
#define MYVEHICLE_H

/**
 * @brief The MyVehicle class
 * @file myvehicle.h
 * @authors Magdalena Ondruskova, Zuzana Hradilova
 *
 * This file represent MyVehicle class and its functions like moving vehicle, stoping at the stop and so on
 */
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QTime>
#include "mycoordinate.h"
#include "myline.h"
#include <QVariantAnimation>
#include <QTime>

class MyStreet;
class MyStop;

class MyVehicle : public QObject,  public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    /**
     * @brief MyVehicle Constructor for MyVehicle class
     * @param parent parent of the object, default its nullptr
     */
    MyVehicle(QGraphicsEllipseItem *parent = nullptr);

    /**
     * @brief setId Function sets ID of the vehicle
     * @param id vehicles id
     */
    void setId(int id);

    /**
     * @brief getId Returns vehicles ID
     * @return ID of vehicle
     */
    int getId();

    /**
     * @brief setSpeed Function sets speed of vehicle
     * @param speed How fast the vehicle is moving
     */
    void setSpeed(double speed);

    /**
     * @brief getSpeed Function returns speed of vehicle
     * @return Speed of vehicle
     */
    double getSpeed();

    /**
     * @brief setLine Function sets vehicles line
     * @param line by which vehicle is moving
     */
    void setLine(MyLine *line);

    /**
     * @brief getLine Function returns vehicles line
     * @return line of vehicle
     */
    MyLine* getLine();

    /**
     * @brief setCurrentPosition Function sets current position of vehicle
     * @param coor New Position of vehicle
     */
    void setCurrentPosition(MyCoordinate coor);

    /**
     * @brief getCurrentPosition Function returns current position of vehicle
     * @return current position
     */
    MyCoordinate getCurrentPosition();

    /**
     * @brief setStartPosition Function sets start position of vehicle to the coor
     * @param coor Start Position of vehicle
     */
    void setStartPosition(MyCoordinate coor);

    /**
     * @brief getStartPosition Function returns start position of vehicle
     * @return Start position
     */
    MyCoordinate getStartPosition();

    /**
     * @brief getTime_schedule Function returns list that represents time schedule of vehicle
     * @return List of times
     */
    QList<QTime> getTime_schedule();

    /**
     * @brief setTime_schedule Function transform list of string to the list of time, both lists represents time schedule
     * @param value List in string
     */
    void setTime_schedule(QList<QString> value);

    /**
     * @brief updatePositionInTime Function moves vehicle in time - this function is called everytime timer ticks
     *  If distance is bigger than path length, it sets the last coordinates to the end point
     *  Else the vehicle is moved
     */
    void updatePositionInTime();

    /**
     * @brief countNewCurrentPosition Function counts new current position of vehicle
     * @param distance Distance which vehicle has already passed
     * @return New Coordinates that will be the new current position
     */
    MyCoordinate countNewCurrentPosition(double distance);

    /**
     * @brief setCurrentStreet Function sets current street on which is the vehicle at the time
     * @param street Street on which the vehicle is located on
     */
    void setCurrentStreet(MyStreet * street);

    /**
     * @brief getCurrentStreet Function returns current street of vehicle
     * @return Current street on which the vehicle is located on
     */
    MyStreet * getCurrentStreet();

    /**
     * @brief slowDown Function slows down the vehicle by given traffic, one point of traffic slows down the vehicle by 0.5speed
     * @param traffic Size of traffic on the street
     */
    void slowDown(int traffic);

    /**
     * @brief setDefaultSpeed Function sets default street of vehicle (gotten from JSON)
     * @param default_speed Default speed of vehicle
     */
    void setDefaultSpeed(double default_speed);

    /**
     * @brief getDefaultSpeed Function returns default speed of vehicle
     * @return Default speed
     */
    double getDefaultSpeed();

    /**
     * @brief setStartTime Function sets start time of the vehicle (time when it is supposed to go to the streets)
     */
    void setStartTime();

    /**
     * @brief getStartTime Function returns start time of vehicle
     * @return Start Time when vehicle is going on route
     */
    QTime getStartTime();

    /**
     * @brief setRemoved Function sets that vehicle was remvoved from scene (it was at the end of his route)
     */
    void setRemoved();

    /**
     * @brief getRemoved Function returns the state of the vehicle (if it is in the scene or not)
     * @return True if vehicle is not in the scene, false if it is there
     */
    bool getRemoved();

    /**
     * @brief unsetRemoved Function sets removed to false - vehicle is in the scene
     */
    void unsetRemoved();

    /**
     * @brief setShowSchedule Function is called when vehicle is being clicked on and its route is shown
     */
    void setShowSchedule();

    /**
     * @brief getShowSchedule Function gets the state if vehicle is being shown or not
     * @return True if vehicle is being shown in MyShow, false otherwise
     */
    bool getShowSchedule();

    /**
     * @brief unsetShowSchedule Function is called to signalize, that vehicle is no longer shown in MyShow
     */
    void unsetShowSchedule();

    /**
     * @brief setDistance Function sets distance that vehicle has already passed
     * @param distance Distance from the start point
     */
    void setDistance(double distance);


    /**
     * @brief getVisitedStops Function returns list of visited stops of vehicle
     * @return List of stops vehicle has passed already
     */
    QList<MyStop * > getVisitedStops();

    /**
     * @brief updateCurrentPositionInTime Function is called when user jumps in the time to count the current position in new time
     * @param time New time, to which user jumped
     */
    void updateCurrentPositionInTime(QTime time);

    /**
     * @brief setVisitedStopsToNone Function clears list of visited stops
     */
    void setVisitedStopsToNone();

    /**
     * @brief findClosedStreetFirst Function finds if first street was closed, if yes it starts from the second street
     */
    void findClosedStreetFirst();

    /**
     * @brief checkTraffic Function checks the traffic of current street on which is vehicle located on
     * @param time  At which time is function called
     */
    void checkTraffic(QTime time);

    /**
     * @brief isAtStop Function sets timerstick if vehicle is at stop, or if already timer stick was set it unsets it
     */
    void isAtStop();

    /**
     * @brief moveVehicle Function moves vehicle everytime timer ticks
     * @param time
     */
    void moveVehicle(QTime time);
    void findClosedStreetLast();


protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual QRectF boundingRect() const override;

private:
    int id;
    MyLine *line;
    MyStreet* current_street;
    double speed{1};
    double default_speed{1};
    MyCoordinate current_position;
    MyCoordinate start_position;
    double distance{0};
    QList<QTime> time_schedule;
    QTime start_time;
    MyStop * last_stop;
    QList<MyStreet *> detour;
    QList<MyCoordinate *> detour_path;
    QList<MyStop *> visited_stops;
    QList<QGraphicsLineItem> lines;
    bool removed{false};
    bool showSchedule{false};
    int timer_stick{0};
};

#endif // MYVEHICLE_H
