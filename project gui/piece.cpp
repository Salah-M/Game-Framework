#include "piece.h"
#include "globalvar.h"
piece::piece(QObject *parent):QObject(parent)
{
    fresh = false;
    QTimer *timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()), this,SLOT(place()));
    timer2->start(1);
}

void piece::setState(state s)
{
    this->s=s;
    if(s==invalid)
    {
        this->setFlag(QGraphicsItem::ItemIsSelectable,false);
        this->setPixmap((QPixmap(":/images/invalid.png")).scaled(60,60));
        this->setPos(x()-5,y()-5);
    }
    if(s==valid)
    {
        this->setFlag(QGraphicsItem::ItemIsSelectable,true);
        this->setPixmap((QPixmap(":/images/invalid.png")).scaled(60,60));
    }
    if(s==white)
    {
        this->setFlag(QGraphicsItem::ItemIsSelectable,false);
        this->setPixmap((QPixmap(":/images/Whitep.png")).scaled(50,50));
        this->setPos(x()+5,y()+5);

    }
    if(s==black)
    {
       this->setFlag(QGraphicsItem::ItemIsSelectable,false);
       this->setPixmap((QPixmap(":/images/blackp.png")).scaled(50,50));
       this->setPos(x()+5,y()+5);
    }
}

void piece::place()
{
    if(this->isSelected())
    {
        if(turnmasta==true)
        {
            this->setState(black);
            this->fresh = true;

        }
        else
        {
            this->setState(white);
            this->fresh = true;

        }
    }
}

