#include "myscene.h"
#include <QDebug>
#include <QFile>
#include <QGraphicsSceneMouseEvent>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QColor>
#include "myshow.h"

MyScene::MyScene(QObject *parent) :
    QGraphicsScene(parent)
{

}

void MyScene::drawScene()
{
    this->loadStops();
    this->loadStreets();
    foreach (auto  mystreet, streets)
        addItem(mystreet);
    foreach (auto  mystop, stops)
        addItem(mystop);
    this->loadLines();
    this->loadVehicles();
}

void MyScene::updatedTimer()
{
    update();
}

QString MyScene::readJson(QString name)
{
    QString val;
    QFile file;
    file.setFileName(name); // musi byt v build subore inak nejde
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    return val;
}

//nacteni ulic ze souboru
void MyScene::loadStreets()
{
    QString file_content = readJson(":/streets.json");
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(file_content.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError)
        qDebug() << error.errorString();
    QJsonObject streetObj = doc.object();
    QJsonArray streetArr = streetObj["streets"].toArray();
    foreach ( const QJsonValue &val, streetArr)
    {
        QJsonObject obj = val.toObject();
        QString streetName = obj["name"].toString();
        QString stopName = obj["stop"].toString();

        QJsonObject startObj = val.toObject().value("start").toObject();
        auto * start_coor = new MyCoordinate;
        start_coor->setX(startObj["x"].toDouble());
        start_coor->setY(startObj["y"].toDouble());

        QJsonObject endObj = val.toObject().value("end").toObject();
        auto * end_coor = new MyCoordinate;
        end_coor->setX(endObj["x"].toDouble());
        end_coor->setY(endObj["y"].toDouble());

        auto street = new MyStreet;
        street->setName(streetName);
        street->setStartCoor(*start_coor);
        street->setEndCoor(*end_coor);

        for (int i = 0; i < stops.size(); i++)
        {
            if (stops.value(i)->getName() == stopName)
            {
                street->setStopOnStreet(stops.value(i));
                stops.value(i)->setStreet(street);
            }
        }

        streets.append(street);
    }
}

//nacteni zastavek ze souboru
void MyScene::loadStops()
{
    QString file_content = readJson(":/stops.json");
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(file_content.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError)
        qDebug() << error.errorString();
    QJsonObject stopObj = doc.object();
    QJsonArray stopArr = stopObj["stops"].toArray();
    foreach ( const QJsonValue &val, stopArr)
    {
        QJsonObject obj = val.toObject();
        QString stopName = obj["name"].toString();
        QJsonObject coorObj = val.toObject().value("coor").toObject();
        auto * coor_start = new MyCoordinate;
        coor_start->setX(coorObj["x"].toDouble());
        coor_start->setY(coorObj["y"].toDouble());

        // creates object stop and sets its parameters
        auto stop = new MyStop;
        stop->setCoordinate(*coor_start);
        stop->setName(stopName);
        stops.append(stop);
    }
}

//nacteni linek ze souboru
void MyScene::loadLines()
{
    QString file_content = readJson(":/lines.json");
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(file_content.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError)
        qDebug() << error.errorString();
    QJsonObject linesObject = doc.object();
    QJsonArray linesArray = linesObject["lines"].toArray();
    foreach (const QJsonValue & value, linesArray)
    {
        QJsonObject obj = value.toObject();
        int line_id = obj["id"].toInt();
        QJsonArray stopsArray = obj["stops"].toArray();
        auto line = new MyLine;
        line->setId(line_id);
        foreach (const QJsonValue &val, stopsArray)
        {
            for (int i = 0; i < stops.size(); i++)
            {
                if (stops.value(i)->getName() == val.toString())
                    line->addStop(stops.value(i));
            }
        }
        line->setPathByStops();
        lines.append(line);
    }
}

//nacteni vozidla ze souboru
void MyScene::loadVehicles()
{
    QString file_content = readJson(":/vehicles.json");
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(file_content.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError)
        qDebug() << error.errorString();
    QJsonObject vehicleObject = doc.object();
    QJsonArray vehiclesArray = vehicleObject["vehicles"].toArray();
    foreach (const QJsonValue & value, vehiclesArray)
    {
        QJsonObject obj = value.toObject();
        int vehicle_id = obj["id"].toInt();
        int vehicle_line = obj["line"].toInt();
        double vehicle_speed = obj["speed"].toDouble();
        QJsonArray timeArray = obj["time"].toArray();
        QList<QString> time;
        auto vehicle = new MyVehicle;
        vehicle->setId(vehicle_id);
        vehicle->setSpeed(vehicle_speed);
        vehicle->setDefaultSpeed(vehicle_speed);
        foreach (const QJsonValue &val, timeArray)
            time.append(val.toString());
        vehicle->setTime_schedule(time);
        foreach (auto myline , lines)
        {
            if ( myline->getId() == vehicle_line)
            {
                vehicle->setLine(myline);
                break;
            }
        }
        vehicle->setCurrentPosition(vehicle->getLine()->getPath().value(0));
        vehicle->setStartPosition(vehicle->getCurrentPosition());
        vehicle->setStartTime();
        vehicle->setCurrentStreet(vehicle->getLine()->findCurrentStreet(vehicle->getLine()->getPath().value(0),
                                                                        vehicle->getLine()->getPath().value(1)));
        vehicles.append(vehicle);
    }
}


//kliknuti na objekty mysi
void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    for (auto item : items(event->scenePos()))
    {
        auto street = dynamic_cast<MyStreet *>(item);
        auto vehicle = dynamic_cast<MyVehicle *>(item);
        if (vehicle)
        {
            foreach (auto street , vehicle->getLine()->getPathStreets())
            {

                if (street->pen() == QPen({Qt::blue},2))
                {
                    if (vehicle->getLine()->getId() == 10)
                        {
                        QColor street_color = QColor(35, 61, 77);
                        street->setPen(QPen({street_color},4));
                    }
                    else if (vehicle->getLine()->getId() == 20)
                        {
                        QColor street_color = QColor(254, 127, 45);
                        street->setPen(QPen({street_color},4));
                    }
                    else if (vehicle->getLine()->getId() == 30)
                        {
                        QColor street_color = QColor(252, 202, 70);
                        street->setPen(QPen({street_color},4));
                    }
                    else if (vehicle->getLine()->getId() == 40)
                        {
                        QColor street_color = QColor(161, 193, 129);
                        street->setPen(QPen({street_color},4));
                    }
                }
            }
            myShow->drawLine(vehicle);
            foreach(auto vehicle, this->getVehicles())
               vehicle->unsetShowSchedule();

            vehicle->setShowSchedule();
        }
        if (street && (event->button() == Qt::RightButton))
        {
            street->riseTraffic();
            street->setPen(QPen({Qt::red},4));
        }
    }
    QGraphicsScene::mousePressEvent(event);
}


void MyScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    for (auto item : items(event->scenePos()))
    {
        auto street = dynamic_cast<MyStreet *>(item);
        if (street && (event->button() == Qt::LeftButton))
        {
            street->setPen(QPen({Qt::black},4));
            street->setClosed();
        }
    }
    QGraphicsScene::mouseDoubleClickEvent(event);
}

QList<MyVehicle *> MyScene::getVehicles()
{
    return vehicles;
}

QList<MyStreet *> MyScene::getStreets()
{
    return streets;
}


void MyScene::setShow(MyShow *show)
{
    this->myShow = show;
}

void MyScene::deleteVehiclesInScene()
{

    foreach( auto item, items())
    {
        auto vehicle = dynamic_cast<MyVehicle *>(item);
        if (vehicle)
            removeItem(vehicle);

    }
    foreach (auto myvehicle, getVehicles())
    {
        myvehicle->unsetRemoved();
        myvehicle->setDistance(0);
        myvehicle->setVisitedStopsToNone();
        myvehicle->setCurrentPosition(myvehicle->getStartPosition());
    }
}

QList<MyVehicle *> MyScene::findVehiclesInTime(QTime time)
{
    foreach (auto vehicle, getVehicles())
    {
        QTime vehicleStart = vehicle->getStartTime();
        QTime vehicleEnd = vehicle->getTime_schedule().value(vehicle->getTime_schedule().size()-1);
        if (vehicleStart < time && vehicleEnd> time)
            vehiclesInTime.append(vehicle);
    }
    return vehiclesInTime;
}

