#include "historywidget.h"
#include "signinwidget.h"

historywidget::historywidget(QWidget *parent) : QWidget(parent)
{
    back = new QPushButton("back");
    VBox = new QVBoxLayout();
    QObject::connect(back, SIGNAL(clicked(bool)), this, SLOT(Back()));
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

void historywidget::Back()
{

}
