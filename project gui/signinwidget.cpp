#include "signinwidget.h"

signinwidget::signinwidget(QWidget *parent) : QWidget(parent)
{
    a = new account();
    game = new game1menu();
    pic = new QLabel();
    messageBox = new QMessageBox();
    history = new QPushButton("Score History");
    play = new QPushButton("Play");
    this->setStyleSheet("background-color:grey;");
    history->setStyleSheet("background-color:black; color:white;");
    play->setStyleSheet("background-color:black; color:white;");

    QObject::connect(play, SIGNAL(clicked(bool)), this, SLOT(playGame()));


}

void signinwidget::getName()
{
    QString fullname = a->firstName + " " + a->lastName;
    name = new QLabel(fullname);
    image = new QImage();
    qDebug()<<"username is in sign in"<<a->username;
    game->user=a->username;

    bool valid = image->load(a->imageloc);
    if (valid)
    {
        qDebug()<<"image is loaded"<<endl;
        pic->setPixmap((QPixmap(a->imageloc)).scaled(150,150));
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
    QString date_day = QDate::currentDate().toString("d");
    qDebug()<<date_day<<endl;
    qDebug()<<date_month<<endl;

    if (date_month == a->month && date_day == a->day)
    {
        messageBox->information(0,"Congratz","Happy Birthday!!");
        messageBox->setFixedSize(500,200);
    }
}

void signinwidget::playGame()
{
    this->close();


    game->show();
}
