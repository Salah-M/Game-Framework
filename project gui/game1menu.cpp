#include "game1menu.h"
#include "game1scene.h"
#include "globalvar.h"
#include "signinwidget.h"

game1menu::game1menu(QWidget *parent) : QWidget(parent)
{
    title = new QLabel;
    l = new QLabel("Select Level:");
    lvl1 = new QRadioButton("Level 1 (Easy)");
    lvl2 = new QRadioButton("Level 2 (medium)");
    lvl3 = new QRadioButton("Level 3 (hard)");

    title->setPixmap((QPixmap(":/images/killcovid.PNG")));
    play = new QPushButton("play!");
    back = new QPushButton("exit");
    play->setStyleSheet("background-color:yellow;");
    this->setStyleSheet("background-color:darkred;");
    Vbox = new QVBoxLayout();
    Vbox->addWidget(title);
    Vbox->addWidget(l);
    Vbox->addWidget(lvl1);
    Vbox->addWidget(lvl2);
    Vbox->addWidget(lvl3);
    Vbox->addWidget(play);
    Vbox->addWidget(back);
    setLayout(Vbox);
    QObject::connect(play, SIGNAL(clicked(bool)), this, SLOT(playb()));
    QObject::connect(back, SIGNAL(clicked(bool)), this, SLOT(Backk()));

}
void game1menu::playb()
{
    qDebug()<<"in playb"<<this->user;
    if (lvl1->isChecked())
    {
        aud="qrc:/music/06 Moongrains.mp3";
        textf=":/level1.txt";
        speedowagon = 1;
    }
    else if (lvl2->isChecked())
    {
        aud="qrc:/music/05 Loonboon.mp3";
        textf=":/level2.txt";
        speedowagon = 2;
    }
    else if (lvl3->isChecked())
    {
        aud="qrc:/music/10 Ultimate Battle.mp3";
        textf=":/level3.txt";
        speedowagon = 4;
    }

    game1scene *scene1;
    scene1= new game1scene;
    scene1->userscene = this->user;
    this->close();
}
void game1menu::Backk()
{
    signinwidget *s= new signinwidget;
    s->a=user;
    user->print();
    qDebug()<<"seperator between AH and a";
    s->a->print();

    this->close();
    s->getName();
    s->show();
}
