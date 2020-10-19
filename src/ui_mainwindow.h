/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_6;
    QTimeEdit *timeClock;
    QSpacerItem *horizontalSpacer_3;
    QLabel *zoom;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QGraphicsView *graphicsView;
    QSlider *zoomSlider;
    QSpacerItem *verticalSpacer_2;
    QLabel *time;
    QTimeEdit *timeEdit;
    QPushButton *jumpButton;
    QPushButton *fasterButton;
    QPushButton *slowerButton;
    QLabel *setting;
    QPushButton *resetTimeButton;
    QPushButton *resetLineButton;
    QPushButton *resetTrafficButton;
    QPushButton *resetDetoursButton;
    QGraphicsView *graphicsView_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1137, 681);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalSpacer_2 = new QSpacerItem(5, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 7, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_6, 18, 4, 1, 1);

        timeClock = new QTimeEdit(centralwidget);
        timeClock->setObjectName(QStringLiteral("timeClock"));
        timeClock->setFocusPolicy(Qt::NoFocus);
        timeClock->setContextMenuPolicy(Qt::NoContextMenu);
        timeClock->setLayoutDirection(Qt::LeftToRight);
        timeClock->setButtonSymbols(QAbstractSpinBox::NoButtons);
        timeClock->setCalendarPopup(false);

        gridLayout->addWidget(timeClock, 2, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        zoom = new QLabel(centralwidget);
        zoom->setObjectName(QStringLiteral("zoom"));
        zoom->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(zoom->sizePolicy().hasHeightForWidth());
        zoom->setSizePolicy(sizePolicy);
        zoom->setMaximumSize(QSize(800, 40));
        zoom->setSizeIncrement(QSize(50, 0));
        zoom->setBaseSize(QSize(50, 20));

        gridLayout->addWidget(zoom, 3, 4, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 18, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 9, 5, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setContextMenuPolicy(Qt::DefaultContextMenu);

        gridLayout->addWidget(graphicsView, 2, 1, 16, 1);

        zoomSlider = new QSlider(centralwidget);
        zoomSlider->setObjectName(QStringLiteral("zoomSlider"));
        zoomSlider->setMaximumSize(QSize(120, 22));
        zoomSlider->setMinimum(1);
        zoomSlider->setMaximum(50);
        zoomSlider->setValue(10);
        zoomSlider->setSliderPosition(10);
        zoomSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(zoomSlider, 4, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 4, 1, 1);

        time = new QLabel(centralwidget);
        time->setObjectName(QStringLiteral("time"));
        time->setMaximumSize(QSize(50, 20));
        time->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(time, 5, 4, 1, 1);

        timeEdit = new QTimeEdit(centralwidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        timeEdit->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        timeEdit->setKeyboardTracking(false);
        timeEdit->setCalendarPopup(false);

        gridLayout->addWidget(timeEdit, 6, 4, 1, 1);

        jumpButton = new QPushButton(centralwidget);
        jumpButton->setObjectName(QStringLiteral("jumpButton"));

        gridLayout->addWidget(jumpButton, 7, 4, 1, 1);

        fasterButton = new QPushButton(centralwidget);
        fasterButton->setObjectName(QStringLiteral("fasterButton"));
        fasterButton->setMouseTracking(false);

        gridLayout->addWidget(fasterButton, 8, 4, 1, 1);

        slowerButton = new QPushButton(centralwidget);
        slowerButton->setObjectName(QStringLiteral("slowerButton"));
        slowerButton->setMouseTracking(false);
        slowerButton->setCheckable(false);

        gridLayout->addWidget(slowerButton, 9, 4, 1, 1);

        setting = new QLabel(centralwidget);
        setting->setObjectName(QStringLiteral("setting"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(setting->sizePolicy().hasHeightForWidth());
        setting->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(setting, 10, 4, 1, 1);

        resetTimeButton = new QPushButton(centralwidget);
        resetTimeButton->setObjectName(QStringLiteral("resetTimeButton"));
        resetTimeButton->setMouseTracking(false);

        gridLayout->addWidget(resetTimeButton, 11, 4, 1, 1);

        resetLineButton = new QPushButton(centralwidget);
        resetLineButton->setObjectName(QStringLiteral("resetLineButton"));
        resetLineButton->setAutoDefault(false);

        gridLayout->addWidget(resetLineButton, 12, 4, 1, 1);

        resetTrafficButton = new QPushButton(centralwidget);
        resetTrafficButton->setObjectName(QStringLiteral("resetTrafficButton"));

        gridLayout->addWidget(resetTrafficButton, 13, 4, 1, 1);

        resetDetoursButton = new QPushButton(centralwidget);
        resetDetoursButton->setObjectName(QStringLiteral("resetDetoursButton"));

        gridLayout->addWidget(resetDetoursButton, 14, 4, 1, 1);

        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        sizePolicy1.setHeightForWidth(graphicsView_2->sizePolicy().hasHeightForWidth());
        graphicsView_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(graphicsView_2, 15, 4, 3, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1137, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        zoom->setText(QApplication::translate("MainWindow", "ZoomIn/ZoomOut", Q_NULLPTR));
        time->setText(QApplication::translate("MainWindow", "Time Edit", Q_NULLPTR));
        jumpButton->setText(QApplication::translate("MainWindow", "Jump in time", Q_NULLPTR));
        fasterButton->setText(QApplication::translate("MainWindow", "Faster", Q_NULLPTR));
        slowerButton->setText(QApplication::translate("MainWindow", "Slower", Q_NULLPTR));
        setting->setText(QApplication::translate("MainWindow", "Setting", Q_NULLPTR));
        resetTimeButton->setText(QApplication::translate("MainWindow", "Reset Time", Q_NULLPTR));
        resetLineButton->setText(QApplication::translate("MainWindow", "Reset Lines", Q_NULLPTR));
        resetTrafficButton->setText(QApplication::translate("MainWindow", "Reset Traffic", Q_NULLPTR));
        resetDetoursButton->setText(QApplication::translate("MainWindow", "Reset Detours", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
