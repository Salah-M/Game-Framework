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
    enum state{invalid, valid ,white,black};
    state s;
    bool fresh;
    explicit piece(QObject *parent=nullptr);
    void setState(state s);

public slots:
    void place();
};

#endif // PIECE_H
