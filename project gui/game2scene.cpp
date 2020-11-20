#include "game2scene.h"

game2scene::game2scene()
{
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
    /*
    //v[3][3]->setPos(v[3][3]->x()+5,v[3][3]->y()+5);
    v[3][3]->setState(piece::white);
    //v[3][4]->setPos(25+3*60,25+4*60);
    v[3][4]->setState(piece::black);
    //v[4][3]->setPos(25+4*60,25+3*60);
    v[4][3]->setState(piece::black);
    //v[4][4]->setPos(25+4*60,25+4*60);
    v[4][4]->setState(piece::white);
    */

    v[1][0]->setState(piece::black);
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


    QTimer *t1 = new QTimer();
    connect(t1,SIGNAL(timeout()), this,SLOT(checkFresh()));
    t1->start(1000);
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
}
