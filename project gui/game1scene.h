#ifndef GAME1SCENE_H
#define GAME1SCENE_H
#include "virus.h"
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
class game1scene : public QGraphicsScene
{
    Q_OBJECT
public:
    game1scene();
    virus *v;
public slots:
    void create_instance();

};

#endif // GAME1SCENE_H
