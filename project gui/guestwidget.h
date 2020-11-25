#ifndef GUESTWIDGET_H
#define GUESTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include <QCalendarWidget>
#include <QRegExp>
#include "account.h"
#include "historywidget.h"
#include "game1menu.h"
#include <QPixmap>
/**
* \file historywidget.h
* \brief contains history widget class defintion
*
*
* This class is responsible for constructing the history widget
*/
/**
* \brief contains history widget class defintion
*
*
*  This class is responsible for constructing the history widget
*/
class guestwidget : public QWidget
{
    Q_OBJECT
public:
    /**
    * \brief history widget constructor
    *
    *
    *  responsible for setting up the gui for history widget and linking the button to its slot
    */
    explicit guestwidget(QWidget *parent = nullptr);
    QLabel *pic;//!<user name string
    QLabel *name;//!<user name string
    game1menu *game;//!<user name string
    QPushButton *history;//!<user name string
    QPushButton *logout;//!<user name string
    historywidget *hw;//!<
    QPushButton *play;//!<play button
    QVBoxLayout *VBox;//!<vertical box layout
    QImage *image;//!<profile image for guest
public slots:
    /**
    * \brief guest widget constructor
    *
    *
    *  responsible for setting up the gui for history widget and linking the button to its slot
    */
    void playGame();
    /**
    * \brief history widget constructor
    *
    *
    *  responsible for setting up the gui for history widget and linking the button to its slot
    */
    void History();
    /**
    * \brief history widget constructor
    *
    *
    *  responsible for setting up the gui for history widget and linking the button to its slot
    */
    void quit();


};

#endif // GUESTWIDGET_H
