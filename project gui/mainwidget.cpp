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
    sup = new signupwidget();
    guest = new guestwidget();
    a = new account();
    messageBox = new QMessageBox();

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
    bool akal = false;
    QFile file("/home/eece435l/lab3/repo/project repo/game-platform-group-5/game-platform-group-5/project gui/accounts.txt");
    QString temp;
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    in >> temp;
    sin = new signinwidget();
    sin->a->username = temp;
    QString line = temp;
    while (!line.isNull())
    {
        if(temp==line0->text())
        {
            //QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha1);
            //hash->addData(line1->text().toUtf8());
            QString pass;
            pass = line1->text();
            in >> temp;
            qDebug() << temp <<endl;
            sin->a->password=temp;
            if(pass==temp)
            {
                in >> temp;
                sin->a->firstName = temp;
                in >> temp;
                sin->a->lastName = temp;
                in >> temp;
                sin->a->gender = temp;
                in >> temp;
                in >> temp;
                sin->a->month = temp;
                in >> temp;
                sin->a->day = temp;
                in >> temp;
                sin->a->year = temp;
                in >> temp;
                sin->a->imageloc = temp;

                sin->a->print();
                sin->getName();
                akal = true;
                sin->show();
                sin->checkBirthday();

                // we show the widget
                //create account to store the info from text file and then display on signinwidget
            }
            else
            {
                messageBox->critical(0,"Error","Incorrect Password!");
                messageBox->setFixedSize(500,200);
                return;
            }
        }
        line = in.readLine();
        in >> temp;
        a->username=temp;
    }
    if (akal == false)
    {
        messageBox->critical(0,"Error","Incorrect Username!");
        messageBox->setFixedSize(500,200);
    }
    file.close();
}

void mainWidget::signup()
{

    sup->show();

}

void mainWidget::playAsGuest()
{
    guest->show();
}

