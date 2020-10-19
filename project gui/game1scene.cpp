#include "game1scene.h"

game1scene::game1scene()
{
    setBackgroundBrush(QBrush(QImage(":/images/istockphoto-636339532-612x612.jpg").scaledToHeight(512).scaledToWidth(910)));
    setSceneRect(0,0,908,510);
}
