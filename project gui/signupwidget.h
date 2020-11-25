#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

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
#include "signinwidget.h"
/**
* \file signupwidget.h
* \brief contains signup widget class defintion
*
*
* This class is responsible for constructing the sign up widget
*/
/**
* \brief contains signup widget class defintion
*
*
*  This class is responsible for constructing the sign up widget
*/
class signupwidget : public QWidget
{
    Q_OBJECT
public:
    /**
    * \brief class constructor
    *
    * responsible for constructing the gui and linking the buttons to their respective slot functions
    */
    explicit signupwidget(QWidget *parent = nullptr);
    QLabel *firstname_label;//!<first name
    QLabel *lastname_label;     //!<last name
    QLabel *username_label;     //!<username
    QLabel *password_label;     //!<password
    QLabel *confirmpassword_label;     //!<confirm password
    QLabel *picture_label;     //!<picture
    QLabel *gender_label;     //!<gender
    QLabel *DateOfBirth_label;     //!<date of birth
    QLineEdit *firstname_line;   //!<first name
    QLineEdit *lastname_line;   //!<last name
    QLineEdit *username_line;   //!<username
    QLineEdit *password_line;   //!<password
    QLineEdit *comfirmpassword_line;   //!<confirm password
    QRadioButton *RB0;  //!<male RB
    QRadioButton *RB1;  //!<female RB
    QCalendarWidget *C;//!<calender widget
    QPushButton *PB0;   //!<sign up
    QPushButton *PB1;//!<sign up
    QPushButton *back;//!<back button
    QGridLayout *grid;//!<gridlayout
    QVBoxLayout *VBox;//!<vertical box layout
    QHBoxLayout *HBox;//!<horizontal box layout
    QGroupBox *G;//!<group box
    QMessageBox *messageBox;//!<message box displaying errors
    QRegExp *password_RegEx;//!<regular expression used to define the password limits
    QString imageName="";//!<filepath as a string for image of user initialized to null
    signinwidget *sw;//!<sign in widget to take the user to sign in directly after sign up


    public slots:
    /**
    * \brief sign up button slot
    *
    * responsible for checking if all information is valid and saving the user in the database and signing them in
    */
    void signup();
    /**
    * \brief image function
    *
    * saves the image to our build directory to have it on next launch
    */
    void image();
    /**
    * \brief quit signup
    *
    * takes the user back from sign up widget to main widget
    */
    void quit();






};

#endif // MAINWIDGET_H
