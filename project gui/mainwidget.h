#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include "signupwidget.h"
#include "signinwidget.h"
#include "account.h"
#include <QCryptographicHash>
/**
* \file mainwidget.h
* \brief contains main widget class defintion
*
*
* This class is responsible for constructing the main widget
*/
/**
* \brief contains main widget class defintion
*
*
*  This class is responsible for constructing the main widget
*/

class mainWidget : public QWidget
{
    Q_OBJECT
public:
    /**
    * \brief main widget constructor
    *
    *
    *  responsible for building the gui of main widget and linking the buttons to their respective slots
    */
    explicit mainWidget(QWidget *parent = nullptr);
    QLabel *label0;//!<user name label
    QLabel *label1;//!<password label
    QLineEdit *line0;//!<user name line
    QLineEdit *line1;//!<password line
    QPushButton *PB0;//!<sign in button
    QPushButton *PB1;//!<sign up button
    QPushButton *PB2;//!<play as guest button
    QVBoxLayout *VBox;//!<vertical box layout
    signupwidget *sup;//!<sign up widget
    account *a;//!<account
    signinwidget *sin;//!<sign in widget
    QMessageBox *messageBox;//!<messagebox to display errors

    public slots:
    /**
    * \brief signin slot
    *
    *
    *  responsible for checking if the user is in the database and if he typed the password correctly if so opens sign in widget
    */
    void signin();
    /**
    * \brief sign up slot
    *
    *
    *  open sign up widget and closes main widget
    */
    void signup();
    /**
    * \brief Play as guest slot
    *
    *
    *  opens sign in widget as a guest and closes main widget and adds guest to the list of users if it is not there.
    */
    void playAsGuest();




};

#endif // MAINWIDGET_H
