#ifndef GAME1SCENE_H
#define GAME1SCENE_H
#include "virus.h"
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <qdebug.h>
class game1scene : public QGraphicsScene
{
    Q_OBJECT
public:
    game1scene();
    int i;

    int speed;

    int scount;
    int mcount;
    int bcount;

    int score;
    int scoreToWin;
    int loss;
    QString text;

    QFile *file;
    QTextStream *in;


    QGraphicsTextItem * io;
    virus *v[40];
public slots:
    void create_instance();
    void update_counters();

};

#endif // GAME1SCENE_H
