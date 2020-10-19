#include "game1menu.h"

game1menu::game1menu(QWidget *parent) : QWidget(parent)
{
    title = new QLabel("Kill Covid-19");
    play = new QPushButton("play!");

    Vbox = new QVBoxLayout();
    Vbox->addWidget(title);
    Vbox->addWidget(play);
    setLayout(Vbox);
}
