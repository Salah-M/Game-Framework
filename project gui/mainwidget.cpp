#include "mainwidget.h"
#include "signupwidget.h"


mainWidget::mainWidget(QWidget *parent) : QWidget(parent)
{
    label0 = new QLabel("Username");
    label1 = new QLabel("Password");
    line0 = new QLineEdit();
    line1 = new QLineEdit();
    PB0 = new QPushButton("Sign in");
    PB1 = new QPushButton("Sign up");
    PB2 = new QPushButton("Play as guest");
    s = new signupwidget();

    VBox = new QVBoxLayout();
    VBox->addWidget(label0);
    VBox->addWidget(line0);
    VBox->addWidget(label1);
    VBox->addWidget(line1);
    VBox->addWidget(PB0);
    VBox->addWidget(PB1);
    VBox->addWidget(PB2);
    setLayout(VBox);

    QObject::connect(PB0, SIGNAL(clicked(bool)), this, SLOT(signin()));
    QObject::connect(PB1, SIGNAL(clicked(bool)), this, SLOT(signup()));
    QObject::connect(PB2, SIGNAL(clicked(bool)), this, SLOT(playAsGuest()));
}



void mainWidget::signin()
{
   return;
}

void mainWidget::signup()
{

    s->show();

}

void mainWidget::playAsGuest()
{
    return;
}

