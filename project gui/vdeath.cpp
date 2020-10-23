#include "vdeath.h"

vdeath::vdeath(QObject *parent):QObject(parent)
{
    this->setPixmap((QPixmap(":/images/ripan.png")).scaled(70,70));
    this->show();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(die()));
    timer->start(2000);
}

void vdeath::die()
{
    scene()->removeItem(this);
    delete this;
}
