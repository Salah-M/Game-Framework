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
#include "game1scene.h"
#include <QPixmap>
#include <QCursor>

class game1menu : public QWidget
{
    Q_OBJECT
public:
    explicit game1menu(QWidget *parent = nullptr);
    QLabel *title;
    QPushButton *play;
    game1scene *scene1;
    QVBoxLayout *Vbox;
    QGraphicsView *view;
    QCursor *c;

public slots:
    void playb();


};

#endif // GAME1MENU_H
