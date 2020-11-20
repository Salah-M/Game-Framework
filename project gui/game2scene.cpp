#include "game2scene.h"

game2scene::game2scene()
{
    view = new QGraphicsView();
    view->setFixedSize(600,600);
    view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setScene(this);
    view->show();
    setBackgroundBrush(QBrush(QImage(":/images/othello-board.jpg").scaledToHeight(600).scaledToWidth(600)));
    setSceneRect(0,0,600,600);
}
