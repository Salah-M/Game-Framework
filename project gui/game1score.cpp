#include "game1score.h"

game1score::game1score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    scount = 0;
    mcount = 0;
    bcount = 0;
    //lossCount = 0;
    score = 0;
    sum = 0;

    text = "Small Count = " + QString::number(scount) + "\nmedium Count = " + QString::number(mcount) + "\nbig Count = " + QString::number(bcount) + "\nScore = " + QString::number(score);

    setDefaultTextColor(Qt::white);
    setPlainText(text);
}

void game1score::si()
{
    scount++;
    score = score + 3;
    sum = scount + mcount + bcount;
    text = "Small Count = " + QString::number(scount) + "\nmedium Count = " + QString::number(mcount) + "\nbig Count = " + QString::number(bcount) + "\nScore = " + QString::number(score);
    setPlainText(text);
}

void game1score::mi()
{
    mcount++;
    score = score + 5;
    sum = scount + mcount + bcount;
    text = "Small Count = " + QString::number(scount) + "\nmedium Count = " + QString::number(mcount) + "\nbig Count = " + QString::number(bcount) + "\nScore = " + QString::number(score);
    setPlainText(text);
}

void game1score::bi()
{
    bcount++;
    score = score + 7;
    sum = scount + mcount + bcount;
    text = "Small Count = " + QString::number(scount) + "\nmedium Count = " + QString::number(mcount) + "\nbig Count = " + QString::number(bcount) + "\nScore = " + QString::number(score);
    setPlainText(text);
}



