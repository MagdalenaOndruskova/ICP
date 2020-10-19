#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @brief MainWindow class
 * @file mainwindow.h
 * @author Magdalena Ondruskova, Zuzana Hradilova
 *
 * This class represents the MainWindow class with its grafics objects,
 *  time editing and main settings.
 */

#include <QMainWindow>
#include <QTimeEdit>
#include <QGraphicsView>
#include <QTime>
#include <QMouseEvent>
#include <QWidget>

class MyScene;
class MyShow;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow constructor for main window
     * @param parent pointer to the parent, default is null
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /**
     * @brief zoom Function handles zooming of the scene
     * @param size the size of zooming
     */
    void zoom(int size);

    /**
     * @brief timer Function handles timer ticks - its called everytime timer ticks
     */
    void timer();

    /**
     * @brief timerSlower Function slows down timer by 100ms
     */
    void timerSlower();

    /**
     * @brief timerFaster Function makes timer go faster by 100ms
     */
    void timerFaster();

    /**
     * @brief timeChanged Function handles jumping in time
     */
    void timeChanged();

    /**
     * @brief resetTime Function handles reseting time to the begining of the day - to 08:00
     */
    void resetTime();

    /**
     * @brief resetLines Function resets colored lines and show that displays line
     */
    void resetLines();

    /**
     * @brief resetTraffic Function resets traffic of each street to the default value
     */
    void resetTraffic();

    /**
     * @brief resetDetours Function resets detours (opens all closed streets)
     */
    void resetDetours();


private:
    Ui::MainWindow *ui;
    MyScene * myScene;
    MyShow * myShow; // na vykreslenie linky
    QTimeEdit * timeEdit;
    QTimeEdit * displayClock;
    QTime timeClock{8,00};
    QTime newday{21,30};
    QTimer *timerClock;
    int time = 1000;

    void initScene();
    void initShow();
    void setStartTime();
    void setTimeEdit();

};
#endif // MAINWINDOW_H
