#include "mainwidget.h"
#include "signupwidget.h"
#include "globalvar.h"


mainWidget::mainWidget(QWidget *parent) : QWidget(parent)
{
    label0 = new QLabel("Username");
    label1 = new QLabel("Password");

    line0 = new QLineEdit();
    line1 = new QLineEdit();
    line1->setEchoMode(QLineEdit::Password);
    PB0 = new QPushButton("Sign in");
    PB1 = new QPushButton("Sign up");
    PB2 = new QPushButton("Play as guest");
    sup = new signupwidget();
    a = new account();
    messageBox = new QMessageBox();
    PB0->setStyleSheet("background-color:orange;");
    PB1->setStyleSheet("background-color:yellow;");
    PB2->setStyleSheet("background-color:brown;");
    VBox = new QVBoxLayout();
    VBox->addWidget(label0);
    VBox->addWidget(line0);
    VBox->addWidget(label1);
    VBox->addWidget(line1);
    VBox->addWidget(PB0);
    VBox->addWidget(PB1);
    VBox->addWidget(PB2);
    setLayout(VBox);
    this->setStyleSheet("background-color:lightgreen;");
    QObject::connect(PB0, SIGNAL(clicked(bool)), this, SLOT(signin()));
    QObject::connect(PB1, SIGNAL(clicked(bool)), this, SLOT(signup()));
    QObject::connect(PB2, SIGNAL(clicked(bool)), this, SLOT(playAsGuest()));
}



void mainWidget::signin()
{
    bool akal = false;
    QFile file("./accounts.txt");
    QString temp;
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    in >> temp;
    if(line0->text()==NULL||line1->text()==NULL )
    {
        messageBox->critical(0,"Error","Username or Password empty!");
        messageBox->setFixedSize(500,200);
        return;
    }
    sin = new signinwidget();
    sin->a->username = temp;
    QString line = temp;
    while (!line.isNull())
    {
        if(temp==line0->text())
        {

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
                temp = in.readLine();
                int i = 0;
                QString temp1;
                while (i < temp.size()-1)
                {
                    temp1[i] = temp[i+1];
                    i++;
                }
                sin->a->imageloc = temp1;

                sin->a->print();
                sin->getName();
                akal = true;
                sin->show();
                sin->checkBirthday();
                break;

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
        sin->a->username=temp;
    }
    if (akal == false)
    {
        messageBox->critical(0,"Error","Incorrect Username!");
        messageBox->setFixedSize(500,200);
        return;
    }
    file.close();
    this->close();
}

void mainWidget::signup()
{
    this->close();
    sup->show();

}

void mainWidget::playAsGuest()
{

    QString pathhh = QDir::currentPath();
    pathhh.append("/userHistory");
    if (!QDir(pathhh).exists())
    {
        QDir().mkdir(pathhh);
    }
    pathhh.append("/" + guest->username +".txt");
    if (QFile::exists(pathhh))
    {
        QFile::remove(pathhh);
    }
    QFile fileee(pathhh);
    fileee.open(QIODevice::WriteOnly);
    fileee.close();
    sin = new signinwidget();
    sin->a = guest;
    guest->print();
    qDebug()<<"seperator between AH and a";
    sin->a->print();

    this->close();
    sin->getName();
    sin->show();
}

