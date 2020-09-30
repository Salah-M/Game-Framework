#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include <QCalendarWidget>
#include <QRegExp>


class signinwidget : public QWidget
{
    Q_OBJECT
public:
    explicit signinwidget(QWidget *parent = nullptr);
};

#endif // SIGNINWIDGET_H
