#ifndef MYSHOW_H
#define MYSHOW_H

/**
 * @brief The MyShow class
 * @file    myshow.h
 * @authors  Magdalena Ondruskova, Zuzana Hradilova
 *
 * This file represents the MyShow class and second scene, where is time schedule showed.
 */
#include "myvehicle.h"
#include <QGraphicsScene>
#include "myline.h"
#include "mycoordinate.h"
#include "mystreet.h"

#include "mystop.h"

class MyShow : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
     * @brief MyShow Constructor for class MyShow
     * @param parent Default null
     */
    explicit MyShow(QObject *parent = nullptr);

    /**
     * @brief drawLine Function draws current line of given vehicle
     * @param vehicle Vehicle which line is being drawn
     */
    void drawLine(MyVehicle * vehicle);

    /**
     * @brief deleteLine Function deletes all the items already drawn in MyShow
     */
    void deleteLine();

};

#endif // MYSHOW_H
