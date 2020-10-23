#include "guestwidget.h"

guestwidget::guestwidget(QWidget *parent) : QWidget(parent)
{
    pic = new QLabel();
    name = new QLabel("Hello Traveler!! Welcome to.... umm ... s-something");
    history = new QPushButton("Score History");
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
}
void guestwidget::playGame()
{
    this->close();
    game->show();
}
