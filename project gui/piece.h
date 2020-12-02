#ifndef PIECE_H
#define PIECE_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class piece : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enum state{invalid, valid ,white,black};//!< enum type for piece state
    state s;//!< indicates the state of a piece
    bool fresh;//!< bool value to store if the piece is the newest piece on the board
    QMediaPlayer *placep;//!< audio to be played when a piece is placed
    /**
    * \brief piece constructor.
    *
    * constructor was only used to set the media player and timers.
    */
    explicit piece(QObject *parent=nullptr);
    /**
    * \brief sets the state of a piece.
    *
    * sets the state of a piece and displays the correct image (black circle, white circle, green box, yellow box).
    */
    void setState(state s);

public slots:
    /**
    * \brief places a piece.
    *
    * when a valid piece is selected it's state is replaced by eithe white or black depending on the turn. In addition to that, the place audio is played and a signal is emitted to game2scene.
    */
    void place();

signals:
    /**
    * \brief signal to be emitted.
    *
    * signal to be emitted to game2scene to indicate that a piece is placed.
    */
    void placed();
};

#endif // PIECE_H
