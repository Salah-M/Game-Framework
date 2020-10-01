#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include <QCalendarWidget>
#include <QRegExp>
#include "account.h"
#include <QPixmap>


class signinwidget : public QWidget
{
    Q_OBJECT
public:
    explicit signinwidget(QWidget *parent = nullptr);
    account *a;
    QLabel *pic;
    QLabel *name;
    QMessageBox *messageBox;
    QPushButton *history;
    QPushButton *play;
    QVBoxLayout *VBox;
    QImage *image;

    void getName();
    void checkBirthday();


};

#endif // SIGNINWIDGET_H
