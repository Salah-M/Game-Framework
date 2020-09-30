#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class account
{
public:
    QString firstName;
    QString lastName;
    QString username;
    QString password;
    QString dateOfBirth;
    QString imageloc;
    account(QString f,QString l,QString user,QString pass,QString dob,QString imag);


};

#endif // ACCOUNT_H
