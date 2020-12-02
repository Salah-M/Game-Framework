#ifndef VIRUS_H
#define VIRUS_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include "vdeath.h"
/**
* \file virus.h
* \brief contains virus class definition
definition
*
*
* This class is responsible for creating the viruses for the game along with destroying them on click
*/
/**
* \brief contains virus class definition
*
*
* This class is responsible for creating the viruses for the game along with destroying them on click
*/
class virus : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enum sizz{small,medium,big};//!< enum type for virus sizes
    sizz size;//!< instance of enum type
    bool alive;//!< boolean to verify if virus is alive
    bool isChecked;//!< used to keep track for score
    QMediaPlayer *deathsound;//!< mediaplayer to play death sound
    int speed;//!< speed of viruses falling
    /**
    * \brief sets the death sound mediaplayer
    *
    * constructor was only used to set the media player other functionalities were delegated to setSize()
    */
    explicit virus(QObject *parent=nullptr);
    /**
    * \brief sets the size and image to viruses
    *
    * sets the size of the virus along with a respective image and connects the timers to their respective slots. to be called everytime you need to create a virus.
    */
    void setSize(sizz s);
    QTimer *timer;//!< first timer responsible for calling update position of virus
    QTimer *timer2;//!< second timer responsible for calling kill to check for killed viruses

public slots:
    /**
    * \brief Updates position of the virus
    *
    * make the virus fall down with varrying speeds.
    */
   void update();
   /**
   * \brief Check if virus is selected then kill it
   *
   * checks if a virus was selected then it kills it and plays the deathsound and displays death animation
   */
   void kill();
};

#endif // VIRUS_H
