#include "guestwidget.h"

guestwidget::guestwidget(QWidget *parent) : QWidget(parent)
{
    pic = new QLabel();
    name = new QLabel("Hello Traveler!! Welcome to.... umm ... s-something");
    history = new QPushButton("Score History");
    hw = new historywidget();
    image = new QImage();
    play = new QPushButton("Play");
    VBox = new QVBoxLayout();
    game = new game1menu;
    history->setStyleSheet("background-color:black; color:white;");
    play->setStyleSheet("background-color:black; color:white;");
    pic->setPixmap((QPixmap(":/images/image.jpeg")).scaled(150,150));
    this->setStyleSheet("background-color:grey;");

   VBox->addWidget(pic);
   VBox->addWidget(name);
   VBox->addWidget(history);
   VBox->addWidget(play);

    setLayout(VBox);
    QObject::connect(play, SIGNAL(clicked(bool)), this, SLOT(playGame()));
    QObject::connect(history, SIGNAL(clicked(bool)), this, SLOT(History()));
}
void guestwidget::playGame()
{
    this->close();
    game->user="guest";
    game->show();
}
void guestwidget::History()
{
    this->close();
    hw->show();
    hw->getHistory();
}
