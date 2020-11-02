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
    explicit game1menu(QWidget *parent = nullptr);
    QLabel *title;
    QPushButton *play;
    QLabel *l;
    QRadioButton *lvl1;
    QRadioButton *lvl2;
    QRadioButton *lvl3;
   // QMediaPlayer *audio;
    //game1scene *scene1;
    QVBoxLayout *Vbox;

    QCursor *c;
    QTimer *ti;

public slots:
    void playb();
    void quit();


};

#endif // GAME1MENU_H
