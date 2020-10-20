#include "game1scene.h"


game1scene::game1scene()
{
    setBackgroundBrush(QBrush(QImage(":/images/istockphoto-636339532-612x612.jpg").scaledToHeight(412).scaledToWidth(988)));
    v = new virus;
    v->setSize(virus::small);
    this->addItem(v);
    setSceneRect(0,0,988,412);
    QTimer *inst = new QTimer();
    connect(inst,SIGNAL(timeout()),this,SLOT(create_instance()));
    inst->start(2000);
}

void game1scene::create_instance()
{
    virus *vi = new virus;
    vi->setSize(virus::big);
    this->addItem(vi);
}
