#ifndef HISTORYWIDGET_H
#define HISTORYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include <QCalendarWidget>
#include <QRegExp>
#include "account.h"
#include "game1menu.h"
#include <QPixmap>

class historywidget : public QWidget
{
public:
    explicit historywidget(QWidget *parent = nullptr);
    QString username;
    QPushButton *back;
    QVBoxLayout *VBox;

    void getHistory();

public slots:

    void Back();


};

#endif // HISTORYWIDGET_H
