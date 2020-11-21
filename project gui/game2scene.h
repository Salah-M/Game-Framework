#ifndef GAME2SCENE_H
#define GAME2SCENE_H

#include "button.h"
#include "game1menu.h"
#include "piece.h"
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <qdebug.h>

class game2scene : public QGraphicsScene
{
    Q_OBJECT
public:
    game2scene();
    account *userscene;
    QGraphicsView *view;
    piece *v[8][8];

    //void win();
    //void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void outflank(int i, int j);
    bool checklegal();

signals:
    //void quit_g();

public slots:
    void checkFresh();
    //void update_counters();
    //void restartGame();
    //void quitGame();
};

#endif // GAME2SCENE_H
