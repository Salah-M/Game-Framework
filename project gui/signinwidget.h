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
#include "historywidget.h"
#include <QPixmap>


class signinwidget : public QWidget
{
    Q_OBJECT
public:
    explicit signinwidget(QWidget *parent = nullptr);
    account *a;
    game1menu *game;
    historywidget *hw;
    QLabel *pic;
    QLabel *name;
    QMessageBox *messageBox;
    QPushButton *history;
    QPushButton *play;
    QPushButton *logout;
    QVBoxLayout *VBox;
    QImage *image;

    void getName();
    void checkBirthday();

    public slots:
    void History();
    void playGame();
    void quit();


};

#endif // SIGNINWIDGET_H
