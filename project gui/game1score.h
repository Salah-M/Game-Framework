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
    /**
    * \brief game 1 score constructor.
    *
    * constructs the class and sets all scores to 0. additionally sets the base text to be displayed in game 1 scene.
    */
    explicit game1score(QGraphicsItem *parent=nullptr);
    int scount;//!< stores small count
    int mcount;//!< stores medium count
    int bcount;//!< stores big count
    int score;//!< stores total game score
    int sum;//!< stores the sum of scount, mcount and bcount

    QString text;//!< text to be displayed on screen as score
    /**
    * \brief updates score when small virus is killed.
    *
    * updates score when small virus is killed by incrementing small count by 1 and score by 3.
    */
    void si();
    /**
    * \brief updates score when medium virus is killed.
    *
    * updates score when medium virus is killed by incrementing medium count by 1 and score by 5.
    */
    void mi();
    /**
    * \brief updates score when big virus is killed.
    *
    * updates score when big virus is killed by incrementing big count by 1 and score by 7.
    */
    void bi();

};

#endif // GAME1SCORE_H
