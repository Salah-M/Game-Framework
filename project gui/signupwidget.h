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

class signupwidget : public QWidget
{
    Q_OBJECT
public:
    explicit signupwidget(QWidget *parent = nullptr);
    QLabel *firstname_label;     //first name
    QLabel *lastname_label;     //last name
    QLabel *username_label;     //username
    QLabel *password_label;     //password
    QLabel *confirmpassword_label;     //confirm password
    QLabel *picture_label;     //picture
    QLabel *gender_label;     //gender
    QLabel *DateOfBirth_label;     //date of birth
    QLineEdit *firstname_line;   //first name
    QLineEdit *lastname_line;   //last name
    QLineEdit *username_line;   //username
    QLineEdit *password_line;   //password
    QLineEdit *comfirmpassword_line;   //confirm password
    QRadioButton *RB0;  //male RB
    QRadioButton *RB1;  //female RB
    QCalendarWidget *C;
    QPushButton *PB0;   //SIGN UP
    QPushButton *PB1;
    QPushButton *back;
    QGridLayout *grid;
    QVBoxLayout *VBox;
    QHBoxLayout *HBox;
    QGroupBox *G;
    QMessageBox *messageBox;
    QRegExp *password_RegEx;
    QString imageName="";
    signinwidget *sw;


    public slots:
    void signup();
    void image();
    void quit();




signals:


};

#endif // MAINWIDGET_H
