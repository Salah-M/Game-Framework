#ifndef VIRUS_H
#define VIRUS_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include "vdeath.h"

class virus : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enum sizz{small,medium,big};
    sizz size;
    bool alive;
    bool isChecked;
    QMediaPlayer *deathsound;
    int speed;
    explicit virus(QObject *parent=nullptr);
    void setSize(sizz s);
    QTimer *timer;
    QTimer *timer2;

public slots:
   void update();
   void kill();
};

#endif // VIRUS_H
