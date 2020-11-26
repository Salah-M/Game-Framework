#ifndef GAME1SCENE_H
#define GAME1SCENE_H

#include "game1score.h"
#include "virus.h"
#include "button.h"
#include "game1menu.h"
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <qdebug.h>

class game1scene : public QGraphicsScene
{
    Q_OBJECT
public:
    game1scene();
    int i;
    account *userscene;
    int speed;

    QGraphicsView *view;

    QMediaPlayer *audio;

    int lossCount;

    int scoreToWin;
    int loss;

    game1menu *g;
    QFile *file;
    QTextStream *in;

    game1score *score;
    QGraphicsTextItem *io;
    Button *playAgain;
    Button *quitButton;

    QTimer *inst;
    QTimer *count;

    QGraphicsRectItem *panel;

    virus *v[40];
    void lose();
    void win();
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);

public slots:
    void create_instance();
    void update_counters();
    void restartGame();
    void quitGame();


};

#endif // GAME1SCENE_H
