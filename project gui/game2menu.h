#ifndef GAME2MENU_H
#define GAME2MENU_H



#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include <QCalendarWidget>
#include <QRegExp>
#include <QGraphicsView>
#include "account.h"
//#include "game1scene.h"
#include <QMediaPlayer>
#include <QPixmap>
#include <QTimer>
#include <QCursor>

/**
* \file game2menu.h
* \brief contains game 2 menu class definition
*
*
*  This class is responsible for creating the main menu of game 2
*/

/**
* \brief contains game 2 menu class definition
*
*
*  This class is responsible for creating the main menu of game 2
*/
class game2menu : public QWidget
{
    Q_OBJECT
public:
    /**
    * \brief game 1 menu constructor.
    *
    * constructs the class and sets up the layout. also links signals to slots.
    */
    explicit game2menu(QWidget *parent = nullptr);
    QLabel *title;//!< Othello title image
    QPushButton *play;//!< Play button
    QPushButton *back;//!< Back button
    QVBoxLayout *Vbox;//!< Vertical box used for layout
    account *user;//!< passed down user from sign in widget

public slots:
    /**
    * \brief function to be called when play is pressed.
    *
    * checks goes to game 2 scene.
    */
    void playb();
    /**
    * \brief function to be called when back is pressed.
    *
    * exits the game menu and goes back to sign in widget
    */
    void Backk();


};

#endif // GAME2MENU_H
