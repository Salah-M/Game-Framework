#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include <QCalendarWidget>
#include <QRegExp>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>

class account
{
public:
    QString firstName;
    QString lastName;
    QString gender;
    QString username;
    QString password;
    QString day;
    QString month;
    QString year;
    QString imageloc;
    account(QString f,QString l,QString user,QString pass,QString dob,QString imag);
    account();

    void print();


};

#endif // ACCOUNT_H
