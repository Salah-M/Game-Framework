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
    QFile file("/home/eece435l/Desktop/repos/game-platform-group-5/project gui/accounts.txt");
    QString temp;
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    in >> temp;
    qDebug() << temp<<endl;
    QString line = in.readLine();
    qDebug() << line<<endl;
    while (!line.isNull())

    {
        if(temp==line0->text()){
            QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha1);
                hash->addData(line1->text().toUtf8());
                QString pass;
               pass = hash->result();
             in>>temp;
           if(pass==temp){
               // we show the widget
               //create account to store the info from text file and then display on signinwidget
           }
        }
        in>>temp;

        line = in.readLine();
        qDebug() << line<<endl;

    }
    file.close();
}

void mainWidget::signup()
{

    s->show();

}

void mainWidget::playAsGuest()
{
    return;
}

