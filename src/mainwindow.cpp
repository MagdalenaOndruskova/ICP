#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "myscene.h"
#include "myvehicle.h"
#include "mystreet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "myshow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStartTime();
    setTimeEdit();
    initScene();

    timerClock = new QTimer(this);
    timerClock->setInterval(time); // ako casto tikne
    timerClock->start();

    connect(ui->zoomSlider,&QSlider::valueChanged, this, &MainWindow::zoom);

    connect(timerClock, &QTimer::timeout, this, &MainWindow::timer);
    connect(ui->fasterButton, &QPushButton::clicked, this, &MainWindow::timerFaster);
    connect(ui->slowerButton, &QPushButton::clicked, this, &MainWindow::timerSlower);

    connect(ui->jumpButton, &QPushButton::clicked, this, &MainWindow::timeChanged);

    connect(ui->resetTimeButton, &QPushButton::clicked, this, &MainWindow::resetTime);
    connect(ui->resetLineButton, &QPushButton::clicked, this, &MainWindow::resetLines);
    connect(ui->resetTrafficButton, &QPushButton::clicked, this, &MainWindow::resetTraffic);
    connect(ui->resetDetoursButton, &QPushButton::clicked, this, &MainWindow::resetDetours);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::zoom(int size)
{
    auto org = ui->graphicsView->transform();
    qreal scale = size / 10;
    ui->graphicsView->setTransform(QTransform(scale, org.m12(), org.m21(), scale, org.dx(), org.dy()));
}

void MainWindow::timer()
{
    auto vehicles = myScene->getVehicles();
    foreach (auto * vehicle , vehicles)
    {
        if (timeClock == newday )
            this->resetTime();

        if (vehicle->getStartTime() == timeClock && !vehicle->getRemoved())
        {
            vehicle->findClosedStreetFirst();
            vehicle->setRect(QRectF(vehicle->getCurrentPosition().x()-5, vehicle->getCurrentPosition().y()-5, 10,10));
            vehicle->unsetRemoved();
            myScene->addItem(vehicle);
        }

        vehicle->checkTraffic(timeClock);
        vehicle->moveVehicle(timeClock);

        if(vehicle->getCurrentPosition() == vehicle->getLine()->getPath().value(vehicle->getLine()->getPath().size()-1) && !vehicle->getRemoved())
         {
             vehicle->setRemoved();
             myScene->removeItem(vehicle);
             vehicle->setCurrentPosition(vehicle->getStartPosition());
             vehicle->setDistance(0);
         }

        if (vehicle->getShowSchedule())
            myShow->drawLine(vehicle);
    }
    timeClock = timeClock.addSecs(30);
    displayClock->setTime(timeClock);
    myScene->updatedTimer();
}

void MainWindow::timerSlower()
{
    time += 100;
    timerClock->setInterval(time);
}

void MainWindow::timerFaster()
{
    time -= 100;
    if (time <= 0)
        time = 100;
    timerClock->setInterval(time);
}

void MainWindow::timeChanged()
{
    QTime new_time = timeEdit->time();
    timeClock = new_time;
    time = 1000;
    myScene->deleteVehiclesInScene();
    QList<MyVehicle *> vehicles= myScene->findVehiclesInTime(timeClock);
    foreach(auto vehicle, vehicles)
    {
        vehicle->updateCurrentPositionInTime(timeClock);
        if (vehicle->getStartTime() < timeClock &&
            vehicle->getTime_schedule().value(vehicle->getTime_schedule().size()-1) > timeClock)
        {
            vehicle->setRect(QRectF(vehicle->getCurrentPosition().x()-5, vehicle->getCurrentPosition().y()-5, 10,10));
            myScene->addItem(vehicle);
        }

    }
}

void MainWindow::resetTime()
{
    myScene->deleteVehiclesInScene();
    timeClock = QTime(8,00);
    time= 1000;
}

void MainWindow::resetLines()
{
    auto streets = myScene->getStreets();
    foreach (auto street , streets)

    {   QColor street_color = QColor(35, 61, 77);
        if (street->pen() == (QPen({street_color},4)))
            street->setPen(QPen({QColor(Qt::blue)},2));
        street_color = QColor(254, 127, 45);
        if (street->pen() == (QPen({street_color},4)))
            street->setPen(QPen({QColor(Qt::blue)},2));
        street_color = QColor(252, 202, 70);
        if (street->pen() == (QPen({street_color},4)))
            street->setPen(QPen({QColor(Qt::blue)},2));
        street_color = QColor(161, 193, 129);
        if (street->pen() == (QPen({street_color},4)))
            street->setPen(QPen({QColor(Qt::blue)},2));
       foreach (auto vehicle, myScene->getVehicles())
            vehicle->unsetShowSchedule();

        myShow->deleteLine();
    }
}

void MainWindow::resetTraffic()
{
    foreach (auto street, myScene->getStreets())
    {
        if (street->pen() == QPen({Qt::red},4))
        {
            street->setTraffic(0);
            street->setPen(QPen({Qt::blue},2));
        }
    }
}

void MainWindow::resetDetours()
{
    foreach (auto street, myScene->getStreets())
    {
        if (street->pen() == QPen({Qt::black},4))
        {
            street->setOpen();
            street->setPen(QPen({Qt::blue},2));
        }
    }
}

void MainWindow::initScene()
{
    myScene = new MyScene(ui->graphicsView);
    ui->graphicsView->setScene(myScene);
    myScene->drawScene();
    initShow();
    myScene->setShow(myShow);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}


void MainWindow::initShow()
{
    myShow = new MyShow(ui->graphicsView_2);
    ui->graphicsView_2->setScene(myShow);
    myShow->setSceneRect(-170,130,230,300);
    ui->graphicsView_2->setRenderHint(QPainter::Antialiasing);

}

void MainWindow::setStartTime()
{
    displayClock = ui->timeClock;
    displayClock->setDisplayFormat("hh:mm:ss");
    displayClock->setTime(QTime(8,00));
}

void MainWindow::setTimeEdit()
{
    timeEdit = ui->timeEdit;
    timeEdit->setDisplayFormat("hh:mm:ss");
    timeEdit->setTime(QTime(8,00));
}
