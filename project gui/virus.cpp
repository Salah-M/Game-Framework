#include "virus.h"

virus::virus(QObject *parent):QObject(parent)
{


}
void virus::setSize(sizz s){
    this->size=s;
    if(s==small){
        this->setPixmap((QPixmap(":/images/smallb.png")).scaled(80,80));
    }
    if(s==medium){
        this->setPixmap((QPixmap(":/images/mediumb.png")).scaled(100,100));
     }
    if(s==big){
       this->setPixmap((QPixmap(":/images/bigb.png")).scaled(150,150));
    }
    int random_number = rand()%700;
    setPos(random_number,0);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(update()));
    timer->start(1000);
}
void virus ::update()
{
    this->setPos(x(),y()+60);

}
void virus::MPressEvent(QGraphicsSceneMouseEvent *event){
       QGraphicsPixmapItem::mousePressEvent(event);
       scene()->removeItem(this);
       delete this;
}
