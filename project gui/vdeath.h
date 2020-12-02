#ifndef VDEATH_H
#define VDEATH_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
/**
* \file vdeath.h
* \brief contains virus death class definition
*
*
* This class is responsible for setting the death animation and removing it from the scene
*/
/**
* \brief contains virus death class definition
*
*
*  This class is responsible for setting the death animation and removing it from the scene
*/
class vdeath : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
    * \brief sets the death image and calls slot die to remove it
    *
    * constructor to set the death image and call slot die to remove it from the scene
    */
    explicit vdeath(QObject *parent=nullptr);
    QTimer *timer;//!< timer to remove the death image

public slots:
    /**
    * \brief Remove death image from scene
    *
    * clearing up the scene from the dead viruses
    */
    void die();

};

#endif // VDEATH_H
