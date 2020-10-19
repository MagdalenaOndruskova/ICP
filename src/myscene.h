#ifndef MYSCENE_H
#define MYSCENE_H
/**
 * @brief The MyScene class
 * @file    myscene.h
 * @authors  Magdalena Ondruskova, Zuzana Hradilova
 *
 * This file represents the MyScene class and its functions which are used for
 * loading object from .json files, drawing them and cathing interactive activities.
 */
#include "myvehicle.h"
#include <QGraphicsScene>
#include "myline.h"
#include "mycoordinate.h"
#include "mystreet.h"
#include "mystop.h"

class MyShow;

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
     * @brief MyScene Constructor for class MyScene
     * @param parent default null
     */
    explicit MyScene(QObject *parent = nullptr);

    /**
     * @brief drawScene Function draws the basic scene (streets + stops) and loads all lines and vehicles
     */
    void drawScene();

    /**
     * @brief goFaster Function makes timer ticks faster by 100ms
     */
    void goFaster();

    /**
     * @brief goSlower Function makes timer ticks slower by 100ms
     */
    void goSlower();

    /**
     * @brief updatedTimer Function calls update on all objects in scene (it moves the vehicles)
     */
    void updatedTimer();

    /**
     * @brief getVehicles Function returns list all the vehicles in the scene (at some point of the time)
     * @return
     */
    QList<MyVehicle*> getVehicles();

    /**
     * @brief getStreets Function returns list of all streets in the scene
     * @return
     */
    QList<MyStreet*> getStreets();

    /**
     * @brief setShow Function sets show for drawing the line
     * @param show Pointer to the graphics view representing show
     */
    void setShow(MyShow * show);

    /**
     * @brief deleteVehiclesInScene Function delets all the vehicles in the scene and sets its parameter to the default settings
     */
    void deleteVehiclesInScene();

    /**
     * @brief findVehiclesInTime Function returns list of vehicles that are supposed to be in the scene at given time
     * @param time Time in which we are finding out which vehicles are supposed to be there
     * @return List of vehicles
     */
    QList<MyVehicle *> findVehiclesInTime(QTime time);

protected:
    /**
     * @brief mousePressEvent Function sets action when clicked on object in scene
     * If object clicked was vehicle, it colors its line to the given color and draws it in my show
     * If object was street, and button was right, it rise traffic by one point
     * @param event Mouse event that we use to find which object was clicked
     */
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    /**
     * @brief mouseDoubleClickEvent Function sets action when user clicks two times at object in scene
     * If object clicked was street, it closes it
     * @param event  Mouse event that we use to find which object was clicked
     */
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QList<MyStop* > stops;
    QList<MyLine*> lines;
    QList<MyStreet*> streets;
    QList<MyVehicle*> vehicles;
    MyShow * myShow;
    QList<MyVehicle *> vehiclesInTime;

    /**
     * @brief readJson Function reads JsonFile given by name and returns it as string
     * @param name  Name of the file
     * @return String representation of file
     */
    QString readJson(QString name);

    /**
     * @brief loadStreets Function handles loading streets from json file
     */
    void loadStreets();

    /**
     * @brief loadStops Function handles loading stops from json file
     */
    void loadStops();

    /**
     * @brief loadLines Function handles loading lines from json file
     */
    void loadLines();

    /**
     * @brief loadVehicles Function handles loading vehicles from json file
     */
    void loadVehicles();
};

#endif // MYSCENE_H
