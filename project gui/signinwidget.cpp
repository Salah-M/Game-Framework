#include "signinwidget.h"
#include "mainwidget.h"

signinwidget::signinwidget(QWidget *parent) : QWidget(parent)
{
    a = new account();
    game1 = new game1menu();
    game2 = new game2menu();
    hw = new historywidget();
    pic = new QLabel();
    messageBox = new QMessageBox();
    history = new QPushButton("Score History");
    play1 = new QPushButton("Play Game 1");
    play2 = new QPushButton("Play Game 2");
    logout = new QPushButton("Logout");
    this->setStyleSheet("background-color:grey;");
    history->setStyleSheet("background-color:black; color:white;");
    play1->setStyleSheet("background-color:black; color:white;");
    play2->setStyleSheet("background-color:black; color:white;");

    QObject::connect(play1, SIGNAL(clicked(bool)), this, SLOT(playGame1()));
    QObject::connect(play2, SIGNAL(clicked(bool)), this, SLOT(playGame2()));
    QObject::connect(history, SIGNAL(clicked(bool)), this, SLOT(History()));
    QObject::connect(logout, SIGNAL(clicked(bool)), this, SLOT(quit()));




}

void signinwidget::getName()
{
    QString fullname = a->firstName + " " + a->lastName;
    name = new QLabel(fullname);
    image = new QImage();
    qDebug()<<"username is in sign in"<<a->username;
    game1->user = a;
    game2->user = a;
    hw->username = a->username;

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
    VBox->addWidget(play1);
    VBox->addWidget(play2);
    VBox->addWidget(logout);
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

void signinwidget::playGame1()
{
    this->close();

    game1->show();
}

void signinwidget::playGame2()
{
    this->close();

    game2->show();
}


void signinwidget::History()
{
    a->print();
    qDebug()<<"this was a in signinwid";
    hw->AH=a;
    hw->AH->print();
    qDebug()<<"this was AH in signinwid";

    this->close();
    hw->show();
    hw->getHistory();
}

void signinwidget::quit()
{
    mainWidget *m = new mainWidget();
    this->close();
    m->show();
}
