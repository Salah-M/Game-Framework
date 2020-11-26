#ifndef GAME2SCENE_H
#define GAME2SCENE_H

#include "button.h"
#include "game1menu.h"
#include "piece.h"
#include <QObject>
#include <QWidget>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <qdebug.h>
#include "game2menu.h"

class game2scene : public QGraphicsScene
{
    Q_OBJECT
public:
    game2scene();
    account *userscene;
    QGraphicsView *view;
    piece *v[8][8];
    QMediaPlayer *au;
    QGraphicsRectItem *panel;
    QGraphicsTextItem *io;
    game2menu *g;
    Button *playAgain;
    Button *quitButton;
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void outflank(int i, int j);
    bool checklegal();
    void end();

signals:

public slots:
    void checkFresh();
    void restartGame();
    void quitGame();
};

#endif // GAME2SCENE_H
