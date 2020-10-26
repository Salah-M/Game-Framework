#include "virus.h"

virus::virus(QObject *parent):QObject(parent)
{
    deathsound = new QMediaPlayer;
    deathsound->setMedia(QUrl("qrc:/music/neck_snap-Vladimir-719669812.wav"));

}
void virus::setSize(sizz s)
{
    alive = true;
    isChecked = false;
    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
    this->size=s;
    if(s==small){
        this->setPixmap((QPixmap(":/images/smallb.png")).scaled(100,100));
    }
    if(s==medium){
        this->setPixmap((QPixmap(":/images/ClipartKey_346282.png")).scaled(120,120));
     }
    if(s==big){
       this->setPixmap((QPixmap(":/images/ClipartKey_346832.png")).scaled(150,150));
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
        deathsound->play();
        alive = false;
        vdeath *v = new vdeath();
        v->setPos(this->x(),this->y());
        scene()->addItem(v);
        scene()->removeItem(this);
        this->hide();
    }
}

