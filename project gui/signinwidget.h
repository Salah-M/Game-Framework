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


class signinwidget : public QWidget
{
    Q_OBJECT
public:
    explicit signinwidget(QWidget *parent = nullptr);
    account *a;
    game1menu *game1;
    game2menu *game2;
    historywidget *hw;
    QLabel *pic;
    QLabel *name;
    QMessageBox *messageBox;
    QPushButton *history;
    QPushButton *play1;
    QPushButton *play2;
    QPushButton *logout;
    QVBoxLayout *VBox;
    QImage *image;

    void getName();
    void checkBirthday();

    public slots:
    void History();
    void playGame1();
    void playGame2();
    void quit();


};

#endif // SIGNINWIDGET_H
