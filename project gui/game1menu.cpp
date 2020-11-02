#include "game1menu.h"
#include "game1scene.h"
#include "globalvar.h"
game1menu::game1menu(QWidget *parent) : QWidget(parent)
{
    title = new QLabel;
    l = new QLabel("Select Level:");
    lvl1 = new QRadioButton("Level 1 (Easy)");
    lvl2 = new QRadioButton("Level 2 (medium)");
    lvl3 = new QRadioButton("Level 3 (hard)");

    title->setPixmap((QPixmap(":/images/killcovid.PNG")));
    play = new QPushButton("play!");
    play->setStyleSheet("background-color:yellow;");
    this->setStyleSheet("background-color:darkred;");
    Vbox = new QVBoxLayout();
    Vbox->addWidget(title);
    Vbox->addWidget(l);
    Vbox->addWidget(lvl1);
    Vbox->addWidget(lvl2);
    Vbox->addWidget(lvl3);
    Vbox->addWidget(play);

    setLayout(Vbox);
    QObject::connect(play, SIGNAL(clicked(bool)), this, SLOT(playb()));
    //QObject::connect(scene1, SIGNAL(quit_g()), this, SLOT(quit()));

   /* ti = new QTimer;
    connect(ti,SIGNAL(timeout()),this,SLOT(quit()));
    ti->start(1); */

}
void game1menu::playb()
{
    qDebug()<<"in playb"<<this->user;
    if (lvl1->isChecked())
    {
        aud="qrc:/music/06 Moongrains.mp3";
        //textf="level1.txt";
    }
    else if (lvl2->isChecked())
    {
        aud="qrc:/music/05 Loonboon.mp3";
    }
    else if (lvl3->isChecked())
    {
        aud="qrc:/music/10 Ultimate Battle.mp3";
    }

    game1scene *scene1;
    scene1= new game1scene;
    scene1->userscene=this->user;
    this->close();
}
void game1menu::quit(){


        //this->show();

}
