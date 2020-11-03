#include "historywidget.h"
#include "signinwidget.h"
#include "guestwidget.h"

historywidget::historywidget(QWidget *parent) : QWidget(parent)
{
    back = new QPushButton("back");
    VBox = new QVBoxLayout();
    QObject::connect(back,SIGNAL(clicked(bool)),this,SLOT(Back1()));
}

void historywidget::getHistory()
{
    qDebug() << username << endl;
    QString path = "./userHistory";
    path.append("/" + username + ".txt");
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString line = in.readLine();
    qDebug() << line << endl;
    while (!line.isNull())
    {
        QLabel *l = new QLabel(line);
        VBox->addWidget(l);
        line = in.readLine();
        qDebug() << line << endl;
    }
    VBox->addWidget(back);
    setLayout(VBox);
}

void historywidget::Back1()
{
    if(username==""){
        this->close();
        guestwidget *g= new guestwidget;
        g->show();
    }
   else{//this doesn't work well since we need to know account to find the sign in
        signinwidget *s= new signinwidget;
        s->a=AH;
        AH->print();
        qDebug()<<"seperator between AH and a";
        s->a->print();

        this->close();
        s->getName();
        s->show();
    }

}
