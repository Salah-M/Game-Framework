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

/**
* \brief contains game 1 scene class definition
*
*
*  This class is responsible for creating and playing game 1 (Kill Covid-19)
*/
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

    QTimer *inst;//!< Timer used to call create instancce
    QTimer *count;//!< Timer used to call update counter

    QGraphicsRectItem *panel;//!< panel used to darken the screen for endgame

    virus *v[40];//!< array of viruses to be created
    /**
    * \brief lose function to call when you lose.
    *
    * ends the game with a loss screen and plays a loss audio. Also writes to the account's history the results of the game.
    */
    void lose();
    /**
    * \brief win function to call when you win.
    *
    * ends the game with a win screen and plays a victory sound. Also writes to the account's history the results of the game.
    */
    void win();
    /**
    * \brief function that draws a panel.
    *
    * function that draws pannels used to create a dark panel for the end game.
    */
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);

public slots:
    /**
    * \brief creates a virus.
    *
    * function that creates a virus called by the timer. It checks the game level to see the size and place at which the virus should be spawned.
    */
    void create_instance();
    /**
    * \brief updates the current state of the game.
    *
    * updates the current state of the game by updating the score, counts and checks for win/loss conditions.
    */
    void update_counters();
    /**
    * \brief Function that restarts the game.
    *
    * Function that restart the game when the Restart button is pressed.
    */
    void restartGame();
    /**
    * \brief Function that quits the game.
    *
    * Function that quits the game when the Quit game button is pressed. goes back to game 1 menu
    */
    void quitGame();


};

#endif // GAME1SCENE_H
