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
    QString firstName;//!< Stores the first name of the user
    QString lastName;//!< Stores the last name of the user
    QString gender;//!< Stores the gender of the user
    QString username;//!< Stores the username of the user
    QString password;//!< Stores the password of the user
    QString day;//!< Stores the day of birth of the user
    QString month;//!< Stores the month of birth of the user
    QString year;//!< Stores the year of birth of the user
    QString imageloc;//!< Stores the path to the user's profile picture
    /**
    * \brief account constructor that takes parameters.
    *
    * account constructor that takes first name, last name, username, password and image path as parameters.
    */
    account(QString f,QString l,QString user,QString pass,QString imag);
    /**
    * \brief account constructor that does not takes parameters.
    *
    * account constructor that doesn't take any parameters.
    */
    account();
    /**
    * \brief prints account details.
    *
    * prints account's first name, last name, username, password, gender, date of birth and image location.
    */
    void print();


};

#endif // ACCOUNT_H
