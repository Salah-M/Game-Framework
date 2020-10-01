#include "account.h"

account::account(QString f,QString l,QString user,QString pass,QString dob,QString imag)
{
    firstName=f;
    lastName=l;
    username=user;
    password=pass;
    imageloc=imag;
}

account::account()
{

}

void account::print()
{
    qDebug() << this->firstName <<endl;
    qDebug() << this->lastName <<endl;
    qDebug() << this->username <<endl;
    qDebug() << this->password <<endl;
    qDebug() << this->gender <<endl;
    qDebug() << this->imageloc <<endl;
    qDebug() << this->day <<endl;
    qDebug() << this->month <<endl;
    qDebug() << this->year <<endl;
}
