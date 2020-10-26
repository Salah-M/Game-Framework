#ifndef GAME1SCORE_H
#define GAME1SCORE_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include <QCalendarWidget>
#include <QRegExp>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QPixmap>
#include <QCursor>

class game1score : public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit game1score(QGraphicsItem *parent=nullptr);
    int scount;
    int mcount;
    int bcount;
    int score;
    int sum;

    QString text;

    void si();
    void mi();
    void bi();

};

#endif // GAME1SCORE_H
