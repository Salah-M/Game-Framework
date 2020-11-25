#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include <QCalendarWidget>
#include <QRegExp>
#include "account.h"
#include "game1menu.h"
#include "game2menu.h"
#include "historywidget.h"
#include <QPixmap>
/**
* \file signinwidget.h
* \brief contains signin widget class defintion
*
*
* This class is responsible for constructing the signin widget
*/
/**
* \brief contains signin widget class defintion
*
*
*  This class is responsible for constructing the signin widget
*/

class signinwidget : public QWidget
{
    Q_OBJECT
public:
    /**
    * \brief signin widget constructor
    *
    *
    *  responsible for building the gui of signin widget and linking the buttons to their respective slots
    */
    explicit signinwidget(QWidget *parent = nullptr);
    account *a;//!<account of user who signed in
    game1menu *game1;//!<game1 menu
    game2menu *game2;//!<game2 menu
    historywidget *hw;//!<the history widget
    QLabel *pic;//!<picture label for profile picture
    QLabel *name;//!<name label for the user's name
    QMessageBox *messageBox;//!<message box to display birthday congratulations
    QPushButton *history;//!<history button
    QPushButton *play1;//!<game 1 button
    QPushButton *play2;//!<game 2 button
    QPushButton *logout;//!<logout button
    QVBoxLayout *VBox;//!<vertical box layout
    QImage *image;//!<image for profile pic
    /**
    * \brief get name function
    *
    *
    *  responsible for getting accounts information and displaying what is relevant on the widget
    */
    void getName();
    /**
    * \brief Checking birthday function
    *
    *
    *  responsible to check if it is the user's birthday and if so display congratulations message box
    */
    void checkBirthday();

    public slots:
    /**
    * \brief History button slot
    *
    *
    *  responsible for checking the users history and displaying the history widget
    */
    void History();
    /**
    * \brief Play game1 button
    *
    *
    *  opens game 1 menu for the user to play game 1
    */
    void playGame1();
    /**
    * \brief Play game 2 button
    *
    *
    *  opens game 2 menu for the user to play game 2
    */
    void playGame2();
    /**
    * \brief quit button
    *
    *
    *  goes back to main widget and closes sign in widget
    */
    void quit();


};

#endif // SIGNINWIDGET_H
