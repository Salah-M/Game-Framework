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

class guestwidget : public QWidget
{
    Q_OBJECT
public:
    explicit guestwidget(QWidget *parent = nullptr);
    QLabel *pic;
    QLabel *name;
    game1menu *game;
    QPushButton *history;
    historywidget *hw;
    QPushButton *play;
    QVBoxLayout *VBox;
    QImage *image;
public slots:
    void playGame();
    void History();
    //void history_G();
};

#endif // GUESTWIDGET_H
