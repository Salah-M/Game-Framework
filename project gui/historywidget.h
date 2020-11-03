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
#include "account.h"
class historywidget : public QWidget
{
     Q_OBJECT
public:
    explicit historywidget(QWidget *parent = nullptr);
    QString username;
    account *AH;
    QPushButton *back;
    QVBoxLayout *VBox;
    void getHistory();

public slots:
    void Back1();


};

#endif // HISTORYWIDGET_H
