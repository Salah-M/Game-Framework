#include "game1menu.h"

game1menu::game1menu(QWidget *parent) : QWidget(parent)
{
    title = new QLabel;

    title->setPixmap((QPixmap(":/images/killcovid.PNG")));
    play = new QPushButton("play!");
    play->setStyleSheet("background-color:yellow;");
    this->setStyleSheet("background-color:darkred;");
    Vbox = new QVBoxLayout();
    Vbox->addWidget(title);
    Vbox->addWidget(play);
    setLayout(Vbox);
    QObject::connect(play, SIGNAL(clicked(bool)), this, SLOT(playb()));
}
void game1menu::playb()
{   scene1 = new game1scene;
    QPixmap cpixmap=QPixmap(":/images/needle.png").scaled(60,60);
    QCursor cursor = QCursor(cpixmap,0,0);
    view = new QGraphicsView();
    view->setCursor(cursor);
    view->setFixedSize(988,412);
    view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setScene(scene1);
    view->show();
    this->close();

}
