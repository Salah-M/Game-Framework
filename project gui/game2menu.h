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

class game2menu : public QWidget
{
    Q_OBJECT
public:
    explicit game2menu(QWidget *parent = nullptr);
    QLabel *title;
    QPushButton *play;
    QPushButton *back;
    QLabel *l;
    QRadioButton *colorw;
    QRadioButton *colorb;
    QVBoxLayout *Vbox;
    account *user;
    QCursor *c;
    QTimer *ti;

public slots:
    void playb();
    void Backk();


};

#endif // GAME2MENU_H
