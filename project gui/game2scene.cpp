#include "game2scene.h"
#include "globalvar.h"
game2scene::game2scene()
{
    turnmasta=true;
    g= new game2menu;
    view = new QGraphicsView();
    view->setFixedSize(520,520);
    view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setScene(this);
    view->show();
    setBackgroundBrush(QBrush(QImage(":/images/board.jpg").scaledToHeight(520).scaledToWidth(520)));
    setSceneRect(0,0,520,520);
    int i = 0;
    int j = 0;
    while(i <8)
    {
        j = 0;
        while(j <8)
        {
            v[i][j] = new piece();
            v[i][j]->setPos(25+i*60,25+j*60);
            v[i][j]->setState(piece::invalid);
            this->addItem(v[i][j]);
            j++;
        }
        i++;
    }
    i = 0;
    /*while(i <8)
    {
        j = 0;
        while(j <8)
        {
            v[i][j]->setPos(25+i*60,25+j*60);
            j++;
        }
        i++;
    }*/

    //v[3][3]->setPos(v[3][3]->x()+5,v[3][3]->y()+5);
    v[3][3]->setState(piece::white);
    //v[3][4]->setPos(25+3*60,25+4*60);
    v[3][4]->setState(piece::black);
    //v[4][3]->setPos(25+4*60,25+3*60);
    v[4][3]->setState(piece::black);
    //v[4][4]->setPos(25+4*60,25+4*60);
    v[4][4]->setState(piece::white);
    v[5][4]->setState(piece::valid);
    v[4][5]->setState(piece::valid);
    v[3][2]->setState(piece::valid);
    v[2][3]->setState(piece::valid);
   /* v[1][0]->setState(piece::black);
    v[2][0]->setState(piece::black);
    v[3][0]->setState(piece::black);
    v[4][0]->setState(piece::black);
    v[5][0]->setState(piece::black);
    v[6][0]->setState(piece::black);
    v[7][0]->setState(piece::white);

    v[0][1]->setState(piece::black);
    v[0][2]->setState(piece::black);
    v[0][3]->setState(piece::black);
    v[0][4]->setState(piece::black);
    v[0][5]->setState(piece::black);
    v[0][6]->setState(piece::black);
    v[0][7]->setState(piece::white);

    v[1][1]->setState(piece::black);
    v[2][2]->setState(piece::black);
    v[3][3]->setState(piece::black);
    v[4][4]->setState(piece::black);
    v[5][5]->setState(piece::black);
    v[6][6]->setState(piece::black);
    v[7][7]->setState(piece::white);

    v[0][0]->setState(piece::valid);
*/




for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        QObject::connect(v[i][j],SIGNAL(placed()),this,SLOT(checkFresh()));
    }
}

}

void game2scene::checkFresh()
{
    int i = 0;
    int j = 0;
    while(i <8)
    {
        j = 0;
        while(j <8)
        {
            if (v[i][j]->fresh == true)
            {
                v[i][j]->fresh = false;
                outflank(i,j);
                return;
            }
            j++;
        }
        i++;
    }
}

void game2scene::outflank(int i, int j)
{
    int x;
    int y;

    x = i - 1;
    while (x >= 0)
    {
        if (v[x][j]->s == piece::valid || v[x][j]->s == piece::invalid)
        {
            break;
        }
        if (v[x][j]->s == v[i][j]->s)
        {
            while(x < i)
            {
                v[x][j]->setState(piece::invalid);
                v[x][j]->setState(v[i][j]->s);
                x++;
            }
            break;
        }
        x--;
    }

    x = i + 1;
    while (x < 8)
    {
        if (v[x][j]->s == piece::valid || v[x][j]->s == piece::invalid)
        {
            break;
        }
        if (v[x][j]->s == v[i][j]->s)
        {
            while(x > i)
            {
                v[x][j]->setState(piece::invalid);
                v[x][j]->setState(v[i][j]->s);
                x--;
            }
            break;
        }
        x++;
    }


    x = j - 1;
    while (x >= 0)
    {
        if (v[i][x]->s == piece::valid || v[i][x]->s == piece::invalid)
        {
            break;
        }
        if (v[i][x]->s == v[i][j]->s)
        {
            while(x < j)
            {
                v[i][x]->setState(piece::invalid);
                v[i][x]->setState(v[i][j]->s);
                x++;
            }
            break;
        }
        x--;
    }

    x = j+1;
    while (x < 8)
    {
        if (v[i][x]->s == piece::valid || v[i][x]->s == piece::invalid)
        {
            break;
        }
        if (v[i][x]->s == v[i][j]->s)
        {
            while(x > j)
            {
                v[i][x]->setState(piece::invalid);
                v[i][x]->setState(v[i][j]->s);
                x--;
            }
            break;
        }
        x++;
    }


    x = i - 1;
    y = j - 1;
    while (x >= 0 && y>=0)
    {
        if (v[x][y]->s == piece::valid || v[x][y]->s == piece::invalid)
        {
            break;
        }
        if (v[x][y]->s == v[i][j]->s)
        {
            while(x < i)
            {
                v[x][y]->setState(piece::invalid);
                v[x][y]->setState(v[i][j]->s);
                x++;
                y++;
            }
            break;
        }
        x--;
        y--;
    }

    x = i + 1;
    y = j + 1;
    while (x < 8 && y < 8)
    {
        if (v[x][y]->s == piece::valid || v[x][y]->s == piece::invalid)
        {
            break;
        }
        if (v[x][y]->s == v[i][j]->s)
        {
            while(x > i)
            {
                v[x][y]->setState(piece::invalid);
                v[x][y]->setState(v[i][j]->s);
                x--;
                y--;
            }
            break;
        }
        x++;
        y++;
    }

    x = i + 1;
    y = j - 1;
    while (x < 8 && y >= 0)
    {
        if (v[x][y]->s == piece::valid || v[x][y]->s == piece::invalid)
        {
            break;
        }
        if (v[x][y]->s == v[i][j]->s)
        {
            while(x > i)
            {
                v[x][y]->setState(piece::invalid);
                v[x][y]->setState(v[i][j]->s);
                x--;
                y++;
            }
            break;
        }
        x++;
        y--;
    }

    x = i - 1;
    y = j + 1;
    while (x >=0  && y < 8)
    {
        if (v[x][y]->s == piece::valid || v[x][y]->s == piece::invalid)
        {
            break;
        }
        if (v[x][y]->s == v[i][j]->s)
        {
            while(x < i)
            {
                v[x][y]->setState(piece::invalid);
                v[x][y]->setState(v[i][j]->s);
                x++;
                y--;
            }
            break;
        }
        x--;
        y++;
    }
    turnmasta=!turnmasta;
    if(checklegal())
    {
       return;
    }
    else
    {
       turnmasta=!turnmasta;
       if(!checklegal())
       {
           end();
       }
    }
}

void game2scene::drawPanel(int x, int y, int width, int height, QColor color, double opacity)
{
    panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    this->addItem(panel);
}

void game2scene::end()
{
    int wcount = 0;
    int bcount = 0;

    int x;
    int y;
    x = 0;
    y = 0;
    while (x <8)
    {
        y = 0;
        while(y < 8)
        {
            if(v[x][y]->s == piece::white)
            {
                wcount++;
            }
            else if(v[x][y]->s == piece::black)
            {
                bcount++;
            }
            y++;
        }
        x++;
    }


    drawPanel(0,0,520,520,Qt::black,0.65);
    io = new QGraphicsTextItem();
    io->setPos(150,100);
    io->setDefaultTextColor(Qt::white);
    QString losttxt;
    if (wcount > bcount)
    {
        losttxt = "White Won \nWhite Count:" + QString::number(wcount)+"\nBlack Count:" + QString::number(bcount);
    }
    else if (wcount < bcount)
    {
        losttxt = "Black Won \nWhite Count:" + QString::number(wcount)+"\nBlack Count:" + QString::number(bcount);
    }
    else if (wcount == bcount)
    {
        losttxt = "Draw \nWhite Count:" + QString::number(wcount)+"\nBlack Count:" + QString::number(bcount);
    }

    au = new QMediaPlayer;
    au->setMedia(QUrl("qrc:/music/win.mp3"));
    au->play();
    io->setPlainText(losttxt);
    io->setFont(QFont("times",32));
    this->addItem(io);
    playAgain = new Button(QString("Play Again"));
    playAgain->setPos(175,300);
    this->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));
    quitButton = new Button(QString("Quit"));
    quitButton->setPos(175,350);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quitGame()));
    this->addItem(quitButton);

}

void game2scene::restartGame()
{


}

void game2scene::quitGame()
{
    view->close();
    g->show();
}


bool game2scene::checklegal()
{
    int x;
    int y;
    x = 0;
    y = 0;
    while (x <8)
    {
        y = 0;
        while(y < 8)
        {
            if(v[x][y]->s == piece::valid)
            {
                v[x][y]->setState(piece::white);
                v[x][y]->setState(piece::invalid);
            }
            y++;
        }
        x++;
    }
    piece::state turn;
    if(turnmasta)
    {
        turn=piece::black;
    }
    else
    {
        turn=piece::white;
    }

    bool check=false;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(v[i][j]->s == piece::invalid)
            {
                x = i - 1;
                while (x >= 0)
                {
                    if(v[i-1][j]->s==turn)  //if 1st one is same color then dont do checks it is invalid
                    {
                        break;
                    }
                    if (v[x][j]->s == piece::valid || v[x][j]->s == piece::invalid)
                    {
                        break;
                    }

                    if (v[x][j]->s == turn)
                    {
                        if(x < i)
                        {
                            v[i][j]->setState(piece::valid);
                            check=true;
                        }
                        break;
                    }
                    x--;
                }

                x = i + 1;
                while (x < 8)
                {
                    if(v[i+1][j]->s==turn){//if 1st one is same color then dont do checks it is invalid
                        break;
                    }
                    if (v[x][j]->s == piece::valid || v[x][j]->s == piece::invalid)
                    {
                        break;
                    }
                    if (v[x][j]->s == turn)
                    {
                        if(x > i)
                        {
                            v[i][j]->setState(piece::valid);
                            check=true;

                        }
                        break;
                    }
                    x++;
                }


                x = j - 1;
                while (x >= 0)
                {
                    if(v[i][j-1]->s==turn){//if 1st one is same color then dont do checks it is invalid
                        break;
                    }
                    if (v[i][x]->s == piece::valid || v[i][x]->s == piece::invalid)
                    {
                        break;
                    }
                    if (v[i][x]->s == turn)
                    {
                        if(x < j)
                        {
                            v[i][j]->setState(piece::valid);
                            check=true;

                        }
                        break;
                    }
                    x--;
                }

                x = j+1;
                while (x < 8)
                {
                    if(v[i][j+1]->s==turn){//if 1st one is same color then dont do checks it is invalid
                        break;
                    }
                    if (v[i][x]->s == piece::valid || v[i][x]->s == piece::invalid)
                    {
                        break;
                    }
                    if (v[i][x]->s == turn)
                    {
                        if(x > j)
                        {
                            v[i][j]->setState(piece::valid);
                            check=true;

                        }
                        break;
                    }
                    x++;
                }


                x = i - 1;
                y = j - 1;
                while (x >= 0 && y>=0)
                {
                    if(v[i-1][j-1]->s==turn){//if 1st one is same color then dont do checks it is invalid
                        break;
                    }
                    if (v[x][y]->s == piece::valid || v[x][y]->s == piece::invalid)
                    {
                        break;
                    }
                    if (v[x][y]->s == turn)
                    {
                        if(x < i)
                        {
                            v[i][j]->setState(piece::valid);
                            check=true;

                        }
                        break;
                    }
                    x--;
                    y--;
                }

                x = i + 1;
                y = j + 1;
                while (x < 8 && y < 8)
                {
                    if(v[i+1][j+1]->s==turn){//if 1st one is same color then dont do checks it is invalid
                        break;
                    }
                    if (v[x][y]->s == piece::valid || v[x][y]->s == piece::invalid)
                    {
                        break;
                    }
                    if (v[x][y]->s == turn)
                    {
                        if(x > i)
                        {
                            v[i][j]->setState(piece::valid);
                            check=true;

                        }
                        break;
                    }
                    x++;
                    y++;
                }

                x = i + 1;
                y = j - 1;
                while (x < 8 && y >= 0)
                {
                    if(v[i+1][j-1]->s==turn){//if 1st one is same color then dont do checks it is invalid
                        break;
                    }
                    if (v[x][y]->s == piece::valid || v[x][y]->s == piece::invalid)
                    {
                        break;
                    }
                    if (v[x][y]->s == turn)
                    {
                        if(x > i)
                        {
                            v[i][j]->setState(piece::valid);
                            check=true;

                        }
                        break;
                    }
                    x++;
                    y--;
                }

                x = i - 1;
                y = j + 1;
                while (x >=0  && y < 8)
                {
                    if(v[i-1][j+1]->s==turn){//if 1st one is same color then dont do checks it is invalid
                        break;
                    }
                    if (v[x][y]->s == piece::valid || v[x][y]->s == piece::invalid)
                    {
                        break;
                    }
                    if (v[x][y]->s == turn)
                    {
                        if(x < i)
                        {
                            v[i][j]->setState(piece::valid);
                            check=true;

                        }
                        break;
                    }
                    x--;
                    y++;
                }
            }
        }
    }
    if(check)
    {
     return true;
    }
    else
    {
      return false;
    }
}
