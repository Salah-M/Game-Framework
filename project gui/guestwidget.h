#ifndef GUESTWIDGET_H
#define GUESTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include <QCalendarWidget>
#include <QRegExp>
#include "account.h"
#include <QPixmap>

class guestwidget : public QWidget
{
    Q_OBJECT
public:
    explicit guestwidget(QWidget *parent = nullptr);
    QLabel *pic;
    QLabel *name;
    QPushButton *history;
    QPushButton *play;
    QVBoxLayout *VBox;
    QImage *image;
};

#endif // GUESTWIDGET_H
