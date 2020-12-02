#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

/**
* \brief contains button class definition
*
*
*  This class is responsible for creating a button inside a game (QT scene)
*/
class Button:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    /**
    * \brief Button constructor.
    *
    * Button constructor that takes button name as parameter.
    */
    Button(QString name, QGraphicsItem* parent=NULL);
    /**
    * \brief mouse press event function.
    *
    * function that sends a signal whenever the button is pressed
    */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /**
    * \brief mouse hover event function.
    *
    * function that lightens up the button when the mouse is hovering over it
    */
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    /**
    * \brief mouse leave event function.
    *
    * function that dims back the button when the mouse is no longer hovering over it
    */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    /**
    * \brief signal to be emitted.
    *
    * signal that is emitted when the button is pressed.
    */
    void clicked();
private:
    QGraphicsTextItem* text;//!< text to be stored inside the button.
};

#endif // BUTTON_H
