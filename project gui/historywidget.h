#ifndef HISTORYWIDGET_H
#define HISTORYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include <QCalendarWidget>
#include <QRegExp>
#include "account.h"
#include "game1menu.h"
#include <QPixmap>
#include "account.h"
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
class historywidget : public QWidget
{
     Q_OBJECT
public:
    /**
    * \brief history widget constructor
    *
    *
    *  responsible for setting up the gui for history widget and linking the button to its slot
    */
    explicit historywidget(QWidget *parent = nullptr);
    QString username;//!<user name string
    account *AH;//!<account
    QPushButton *back;//!<back button
    QVBoxLayout *VBox;//!<vertical box layout
    /**
    * \brief Get history function
    *
    *
    *  gets the history of the user by checking the database text file of that user under /userhistory path and displays that information
    */
    void getHistory();

public slots:
    /**
    * \brief back slot
    *
    *
    *  if user is guest goes back to sign in widget as guest but if user has a username goes back to sign in widget
    */
    void Back1();


};

#endif // HISTORYWIDGET_H
