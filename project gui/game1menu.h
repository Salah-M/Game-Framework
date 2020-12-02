#ifndef GAME1MENU_H
#define GAME1MENU_H

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

class game1menu : public QWidget
{
    Q_OBJECT
public:
    /**
    * \brief game 1 menu constructor.
    *
    * constructs the class and sets up the layout. also links signals to slots.
    */
    explicit game1menu(QWidget *parent = nullptr);
    QLabel *title;//!< Kill covid 19 image
    QPushButton *play;//!< Play button
    QPushButton *back;//!< Back button
    QLabel *l;//!< label asking to select game level
    QRadioButton *lvl1;//!< level 1 radio button
    QRadioButton *lvl2;//!< level 2 radio button
    QRadioButton *lvl3;//!< level 3 radio button
    QVBoxLayout *Vbox;//!< Vertical box used for layout
    account *user;//!< passed down user from sign in widget

public slots:
    /**
    * \brief function to be called when play is pressed.
    *
    * checks which level is selected and goes to game 1 scene. each level has it's own difficulty and music audio
    */
    void playb();
    /**
    * \brief function to be called when back is pressed.
    *
    * exits the game menu and goes back to sign in widget
    */
    void Backk();


};

#endif // GAME1MENU_H
