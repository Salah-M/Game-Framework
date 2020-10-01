#include "guestwidget.h"

guestwidget::guestwidget(QWidget *parent) : QWidget(parent)
{
    pic = new QLabel();
    name = new QLabel("Hello Traveler!! Welcome to.... umm ... s-something");
    history = new QPushButton("Score History");
    image = new QImage();
    play = new QPushButton("Play");
    VBox = new QVBoxLayout();

    QString loc = "/home/eece435l/lab2/images/garbage.png";

    bool valid = image->load("/home/eece435l/lab2/images/garbage.png");
    if (valid)
    {
        pic->setPixmap(loc);
    }
    else
    {

    }

    VBox->addWidget(pic);
    VBox->addWidget(name);
    VBox->addWidget(history);
    VBox->addWidget(play);
    setLayout(VBox);
}
