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

/**
* \file game2scene.h
* \brief contains game 2 scene class definition
*
*
*  This class is responsible for creating and playing game 2 (othello or reversi)
*/

/**
* \brief contains game 2 scene class definition
*
*
*  This class is responsible for creating and playing game 2 (othello or reversi)
*/
class game2scene : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
    * \brief game 2 scene constructor.
    *
    * constructs game 2 scene and sets background image and initialized all elements inlucding all 64 pieces links their signals to the correct slots.
    */
    game2scene();
    account *userscene;//!< user account passed down from game 1 menu
    QGraphicsView *view;//!< view used to create the scene
    piece *v[8][8];//!< Double array containing all 64 pieces of the game
    QMediaPlayer *au;//!< adio player used to play different sounds
    QGraphicsRectItem *panel;//!< panel used to darken the screen for endgame
    QGraphicsTextItem *io;//!< text item to display who won and the score
    game2menu *g;//!< pointer to game 2 menu to be able to exit the game
    Button *playAgain;//!< button used for Play again when the game is over
    Button *quitButton;//!< button used to quit the game when the game is over
    /**
    * \brief function that draws a panel.
    *
    * function that draws pannels used to create a dark panel for the end game.
    */
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    /**
    * \brief Outflank function.
    *
    * this function takes the location of a piece and checks all 8 directions around it if it can outflank the enemy pieces and outflanks them. At the end, the function checklegal is called and the turn is changed.
    */
    void outflank(int i, int j);
    /**
    * \brief function that checks which pieces should be valid.
    *
    * this boolean function checks all pieces on the board from all directions to see if they are outflankable. if a piece is outflankable this piece is set to valid. this function returns false if no  valid piece is found and thus does not switch turns else it returns true.
    */
    bool checklegal();
    /**
    * \brief end game function.
    *
    * when the game is over, this function checks who won, display the end game scene on the view and plays a victory sound.
    */
    void end();

signals:

public slots:
    /**
    * \brief Function that is called when a signal is emitted from any piece.
    *
    * This function is called whenever a signal is emitted from any piece, It searches for the fresh or newest piece placed on the board and calls the function outflank.
    */
    void checkFresh();
    /**
    * \brief Function that restarts the game.
    *
    * Function that restart the game when the Restart button is pressed.
    */
    void restartGame();
    /**
    * \brief Function that quits the game.
    *
    * Function that quits the game when the Quit game button is pressed. goes back to game 2 menu
    */
    void quitGame();
};

#endif // GAME2SCENE_H
