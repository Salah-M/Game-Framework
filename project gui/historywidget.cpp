#include "historywidget.h"
#include "signinwidget.h"

historywidget::historywidget(QWidget *parent) : QWidget(parent)
{
    back = new QPushButton("back");
    VBox = new QVBoxLayout();
    this->setStyleSheet("background-color:cyan;");
    QObject::connect(back,SIGNAL(clicked(bool)),this,SLOT(Back1()));
}

void historywidget::getHistory()
{
    qDebug() << AH->username << endl;
    QString path = "./userHistory";
    path.append("/" + AH->username + ".txt");
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
        signinwidget *s= new signinwidget;
        s->a=AH;
        AH->print();
        qDebug()<<"seperator between AH and a";
        s->a->print();

        this->close();
        s->getName();
        s->show();
}
