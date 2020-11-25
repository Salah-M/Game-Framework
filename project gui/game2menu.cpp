#include "game2menu.h"
#include "game2scene.h"
#include "globalvar.h"
#include "signinwidget.h"

game2menu::game2menu(QWidget *parent) : QWidget(parent)
{
    title = new QLabel;
    title->setPixmap((QPixmap(":/images/Othello.jpeg")));
    play = new QPushButton("play!");
    back = new QPushButton("exit");
    play->setStyleSheet("background-color:yellow;");
    this->setStyleSheet("background-color:darkgreen;");
    Vbox = new QVBoxLayout();
    Vbox->addWidget(title);
    Vbox->addWidget(play);
    Vbox->addWidget(back);
    setLayout(Vbox);
    QObject::connect(play, SIGNAL(clicked(bool)), this, SLOT(playb()));
    QObject::connect(back, SIGNAL(clicked(bool)), this, SLOT(Backk()));

}
void game2menu::playb()
{
    game2scene *scene2;
    scene2= new game2scene;
    scene2->userscene = this->user;
    this->close();
}
void game2menu::Backk()
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
