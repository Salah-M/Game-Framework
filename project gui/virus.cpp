#include "virus.h"

virus::virus(QObject *parent):QObject(parent)
{


}
void virus::setSize(sizz s)
{
    alive = true;
    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
    this->size=s;
    if(s==small){
        this->setPixmap((QPixmap(":/images/smallb.png")).scaled(100,100));
    }
    if(s==medium){
        this->setPixmap((QPixmap(":/images/mediumb.png")).scaled(120,120));
     }
    if(s==big){
       this->setPixmap((QPixmap(":/images/bigb.png")).scaled(150,150));
    }
    /*
    int random_number = rand()%700;
    setPos(random_number,-50);
    */
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(update()));
    timer->start(5);
    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()), this,SLOT(kill()));
    timer2->start(1);
}

void virus ::update()
{
    this->setPos(x(),y()+(0.1*speed));

}

void virus::kill()
{
    if(this->isSelected())
    {
        alive = false;
        this->setFlag(QGraphicsItem::ItemIsSelectable,false);
        this->setPixmap((QPixmap(":/images/ripan.png")).scaled(100,100));
        scene()->removeItem(this);
        this->hide();
    }
}

