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
    /**
    * \brief game 1 scene constructor.
    *
    * constructs game 1 scene and sets background image and initialized all elements inlucding timers and linking timers to slots.
    */
    game1scene();
    int i;//!< itterator that keeps track of viruses
    account *userscene;//!< user account passed down from game 1 menu
    int speed;//!< speed at which the game is running

    QGraphicsView *view;//!< view used to create the scene

    QMediaPlayer *audio;//!< music audio that is played during the game

    int lossCount;//!< stores the number of missed viruses required to lose the game

    int scoreToWin;//!< stores the score needed to win the game
    int loss;//!< keeps count of how many viruses were missed

    game1menu *g;//!< pointer to game 1 menu to be able to exit the game
    QFile *file;//!< files used to read level (the txt databasse)
    QTextStream *in;//!< Text stream used to read file

    game1score *score;//!< score class that keeps track of the score and displays it on the scene
    QGraphicsTextItem *io;//!< text item to display either a win or a loss
    Button *playAgain;//!< button used for Play again when the game is over
    Button *quitButton;//!< button used to quit the game when the game is over

    QTimer *inst;//!<
    QTimer *count;

    QGraphicsRectItem *panel;

    virus *v[40];
    /**
    * \brief updates score when small virus is killed.
    *
    * updates score when small virus is killed by incrementing small count by 1 and score by 3.
    */
    void lose();
    /**
    * \brief updates score when small virus is killed.
    *
    * updates score when small virus is killed by incrementing small count by 1 and score by 3.
    */
    void win();
    /**
    * \brief updates score when small virus is killed.
    *
    * updates score when small virus is killed by incrementing small count by 1 and score by 3.
    */
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);

public slots:
    /**
    * \brief updates score when small virus is killed.
    *
    * updates score when small virus is killed by incrementing small count by 1 and score by 3.
    */
    void create_instance();
    /**
    * \brief updates score when small virus is killed.
    *
    * updates score when small virus is killed by incrementing small count by 1 and score by 3.
    */
    void update_counters();
    /**
    * \brief updates score when small virus is killed.
    *
    * updates score when small virus is killed by incrementing small count by 1 and score by 3.
    */
    void restartGame();
    /**
    * \brief updates score when small virus is killed.
    *
    * updates score when small virus is killed by incrementing small count by 1 and score by 3.
    */
    void quitGame();


};

#endif // GAME1SCENE_H
