#include "game1menu.h"

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
}
void game1menu::playb()
{   scene1 = new game1scene;
    if (lvl1->isChecked())
    {
        scene1->level = 1;
    }
    else if (lvl2->isChecked())
    {
        scene1->level = 2;
    }
    else if (lvl3->isChecked())
    {
        scene1->level = 3;
    }
    audio = new QMediaPlayer;
    audio->setMedia(QUrl("qrc:/music/05 Loonboon.mp3"));
    QPixmap cpixmap=QPixmap(":/images/needle.png").scaled(30,30);
    QCursor cursor = QCursor(cpixmap,0,0);
    view = new QGraphicsView();
    view->setCursor(cursor);
    view->setFixedSize(988,412);
    view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setScene(scene1);
    view->show();
    audio->play();
    this->close();
}
