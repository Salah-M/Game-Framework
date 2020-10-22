#include "game1scene.h"


game1scene::game1scene()
{
    speed = 1;
    i = 0;
    scount = 0;
    mcount = 0;
    bcount = 0;

    QGraphicsTextItem * io = new QGraphicsTextItem;
    this->addItem(io);
    io->setPos(0,0);
    io->setDefaultTextColor(Qt::white);

    file = new QFile(":/level1.txt");
    file->open(QIODevice::ReadOnly);
    in = new QTextStream(file);
    *in >> scoreToWin;
    qDebug() << scoreToWin << endl;
    *in >> loss;
    qDebug() << loss << endl;



    setBackgroundBrush(QBrush(QImage(":/images/istockphoto-636339532-612x612.jpg").scaledToHeight(412).scaledToWidth(988)));
    setSceneRect(0,0,988,412);
    QTimer *inst = new QTimer();
    QTimer *count = new QTimer();
    connect(inst,SIGNAL(timeout()),this,SLOT(create_instance()));
    connect(count,SIGNAL(timeout()),this,SLOT(update_counters()));
    count->start(100);
    inst->start(1000);

    text = "Small Count = " + QString::number(scount) + "\nmedium Count = " + QString::number(mcount) + "\nbig Count = " + QString::number(bcount);

    io->setPlainText(text);
}

void game1scene::create_instance()
{
    v[i] = new virus();
    v[i]->speed = speed;


    /*int r = rand()%3;
    if(r==0){
    v[i]->setSize(virus::small);
    }
    if(r==1){
    v[i]->setSize(virus::medium);
    }
    if(r==2){
    v[i]->setSize(virus::big);
    }
    this->addItem(v[i]);*/

    QString temp;
    int pos;
    *in >> temp;
    *in >> pos;
    //qDebug() << pos << endl;
    v[i]->setPos(pos , -50);
    if(temp == "small")
    {
        v[i]->setSize(virus::small);
    }
    if(temp == "medium")
    {
        v[i]->setSize(virus::medium);
    }
    if(temp == "big")
    {
        v[i]->setSize(virus::big);
    }
    this->addItem(v[i]);

    i = i + 1;
}

void game1scene::update_counters()          // check this
{
    int sum = 0;
    int j = 0;
    while (j < i)
    {
        if (v[j]->alive == false)
        {
            v[j]->alive = true;
            if (v[j]->size == virus::small)
            {
                scount = scount + 1;
            }
            if (v[j]->size == virus::medium)
            {
                mcount = mcount + 1;
            }
            if (v[j]->size == virus::big)
            {
                bcount = bcount + 1;
            }
        }
        j = j + 1;
    }
    sum = scount + mcount + bcount;
    if (sum >= 20)
    {
        speed = 16;
    }
    else if(sum >= 15)
    {
        speed = 8;
    }
    else if (sum >= 10)
    {
        speed = 4;
    }
    else if (sum >= 5)
    {
        speed = 2;
    }
    text = "Small Count = " + QString::number(scount) + "\nmedium Count = " + QString::number(mcount) + "\nbig Count = " + QString::number(bcount);
    //qDebug() << sum << " " << speed << endl;

    //io->setPlainText(text);
}
