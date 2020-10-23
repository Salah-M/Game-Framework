#ifndef VDEATH_H
#define VDEATH_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
class vdeath : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit vdeath(QObject *parent=nullptr);
    QTimer *timer;

public slots:
    void die();

};

#endif // VDEATH_H
