#include "signinwidget.h"

signinwidget::signinwidget(QWidget *parent) : QWidget(parent)
{
    a = new account();
    pic = new QLabel();
    messageBox = new QMessageBox();
    history = new QPushButton("Score History");
    play = new QPushButton("Play");

}

void signinwidget::getName()
{
    QString fullname = a->firstName + " " + a->lastName;
    name = new QLabel(fullname);
    image = new QImage();



    bool valid = image->load(a->imageloc);
    if (valid)
    {
        pic->setPixmap(a->imageloc);
    }
    else
    {

    }
    VBox = new QVBoxLayout();
    VBox->addWidget(pic);
    VBox->addWidget(name);
    VBox->addWidget(history);
    VBox->addWidget(play);
    setLayout(VBox);
}

void signinwidget::checkBirthday()
{
    QString date_month = QDate::currentDate().toString("MMM");
    QString date_day = QDate::currentDate().toString("dd");

    if (date_month == a->month && date_day == a->day)
    {
        messageBox->information(0,"Congratz","Happy Birthday!!");
        messageBox->setFixedSize(500,200);
    }
}
