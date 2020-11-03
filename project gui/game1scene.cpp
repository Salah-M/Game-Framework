#include "game1scene.h"
#include "game1menu.h"
#include  "globalvar.h"

game1scene::game1scene()
{

    g= new game1menu;
    QPixmap cpixmap=QPixmap(":/images/needle.png").scaled(30,30);
    QCursor cursor = QCursor(cpixmap,0,0);
    view = new QGraphicsView();
    view->setCursor(cursor);
    view->setFixedSize(988,412);
    view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setScene(this);
    view->show();
    speed = 1;
    i = 0;
    lossCount = 0;
    quit = false;

    score = new game1score();
    qDebug()<<"lvl is:"<<level;
    audio = new QMediaPlayer;

    audio->setMedia(QUrl(aud));
    audio->play();

    this->addItem(score);
    score->setPos(0,0);

    file = new QFile(textf);
    file->open(QIODevice::ReadOnly);
    in = new QTextStream(file);
    *in >> scoreToWin;
    qDebug() << scoreToWin << endl;
    *in >> loss;
    qDebug() << loss << endl;

    //QObject::connect(this, SIGNAL(quit_g()),&game1m, SLOT(quit()));

    setBackgroundBrush(QBrush(QImage(":/images/istockphoto-636339532-612x612.jpg").scaledToHeight(412).scaledToWidth(988)));
    setSceneRect(0,0,988,412);
    inst = new QTimer();
    count = new QTimer();
    connect(inst,SIGNAL(timeout()),this,SLOT(create_instance()));
    connect(count,SIGNAL(timeout()),this,SLOT(update_counters()));
    count->start(100);
    inst->start(1000);

}

void game1scene::create_instance()
{
    v[i] = new virus();
    v[i]->speed = speed;

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

void game1scene::update_counters()
{
    int j = 0;
    while (j < i)
    {
        if (v[j]->alive == false && v[j]->isChecked == false)
        {
            v[j]->isChecked = true;
            if (v[j]->size == virus::small)
            {
                score->si();
            }
            if (v[j]->size == virus::medium)
            {
                score->mi();
            }
            if (v[j]->size == virus::big)
            {
                score->bi();
            }
        }
        if (v[j]->y() >= 400 && v[j]->isChecked == false)
        {
            v[j]->setY(-200);
            lossCount = lossCount + 1;
            qDebug() << lossCount << endl;
            if (lossCount == loss)
            {
                lose();
                return;
            }
        }
        j = j + 1;
    }
    if (score->score >= 150)
    {
        win();
        return;
    }
    if (score->sum >= 20)
    {
        speed = 16;
    }
    else if(score->sum >= 15)
    {
        speed = 8;
    }
    else if (score->sum >= 10)
    {
        speed = 4;
    }
    else if (score->sum >= 5)
    {
        speed = 2;
    }
}

void game1scene::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    this->addItem(panel);
}

void game1scene::lose()
{
    inst->stop();
    count->stop();
    audio->stop();
    drawPanel(0,0,1000,450,Qt::black,0.65);
    io = new QGraphicsTextItem();
    io->setPos(300,100);
    io->setDefaultTextColor(Qt::white);
    QString losttxt = "YOU LOST \nScore = " + QString::number(score->score);
    io->setPlainText(losttxt);
    io->setFont(QFont("times",32));
    this->addItem(io);
    playAgain = new Button(QString("Play Again"));
    playAgain->setPos(400,300);
    this->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));
    quitButton = new Button(QString("Quit"));
    quitButton->setPos(400,350);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quitGame()));
    this->addItem(quitButton);
    qDebug()<<"username in lose"<<this->userscene;
    file->close();

    QString path = "./userHistory";
      QString date = QDate::currentDate().toString();
      QString time = QTime::currentTime().toString();
      path.append("/" + this->userscene + ".txt");
      QFile filee(path);
      qDebug()<<"username in lose before printing"<<this->userscene;
      if (filee.open(QIODevice::ReadWrite | QIODevice::Append))
      {     qDebug()<<"username in lose printing"<<this->userscene;
          QTextStream stream(&filee);
          stream << "game1 " << date << " " << time  << " lost " << QString::number(score->score) << endl;
          qDebug()<<"printing to file"<<endl;
          stream.flush();
      }
      filee.close();
}

void game1scene::win()
{
    inst->stop();
    count->stop();
    audio->stop();
    drawPanel(0,0,1000,450,Qt::black,0.65);
    io = new QGraphicsTextItem();
    io->setPos(300,100);
    io->setDefaultTextColor(Qt::white);
    QString wintxt = "YOU WON \nScore = " + QString::number(score->score);
    io->setPlainText(wintxt);
    io->setFont(QFont("times",32));
    this->addItem(io);
    playAgain = new Button(QString("Play Again"));
    playAgain->setPos(400,300);
    this->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));
    quitButton = new Button(QString("Quit"));
    quitButton->setPos(400,350);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quitGame()));
    this->addItem(quitButton);
    qDebug()<<"username in win"<<this->userscene;

    file->close();
    QString path = "./userHistory";
      QString date = QDate::currentDate().toString();
      QString time = QTime::currentTime().toString();
      qDebug()<<"username in win printed"<<this->userscene;
      path.append("/" + this->userscene + ".txt");
      QFile filee(path);
      if (filee.open(QIODevice::ReadWrite | QIODevice::Append))
      {
          QTextStream stream(&filee);
          stream << "game1 " << date << " " << time  << " won " << QString::number(score->score) << endl;
          qDebug()<<"printing to file"<<endl;
          stream.flush();
      }
      filee.close();
}

void game1scene::restartGame()
{
    this->removeItem(panel);
    this->removeItem(io);
    this->removeItem(playAgain);
    this->removeItem(quitButton);
    this->removeItem(score);
    speed = 1;
    i = 0;
    lossCount = 0;
    score->sum = 0;
    score->scount = -1;
    score->mcount = 0;
    score->bcount = 0;
    score->score = -3;
    score->si();
    this->addItem(score);

    audio = new QMediaPlayer;
    audio->setMedia(QUrl(aud));
    audio->play();

    this->addItem(score);
    score->setPos(0,0);

    file = new QFile(textf);
    file->open(QIODevice::ReadOnly);
    in = new QTextStream(file);
    *in >> scoreToWin;
    qDebug() << scoreToWin << endl;
    *in >> loss;
    qDebug() << loss << endl;

    count->start(100);
    inst->start(1000);
}

void game1scene::quitGame()
{
    view->close();
    qDebug()<<"username in quiting"<<this->userscene;
    g->user=this->userscene;
    g->show();


}
