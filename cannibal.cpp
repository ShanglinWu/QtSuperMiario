#include "cannibal.h"

Cannibal::Cannibal()
{

}

void Cannibal::cannibal_init(QGraphicsScene *scene,double xx,double yy)
{
        cannibal_scene=scene;
        cannibal_photo=QPixmap(":/img/photo/pipe_long.png");
        cannibal.setPixmap(cannibal_photo);
        cannibal.setPos(xx,yy);
        x=xx;
        y=yy;
        cannibal_scene->addItem(&cannibal);
}

void Cannibal::move(double xx, double yy)
{
        cannibal.moveBy(xx,yy);
        x+=xx;
        y+=yy;
}


