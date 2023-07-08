#include "brick.h"

Brick::Brick()
{
    brick_photo=QPixmap(":/img/photo/brick1.png");
    brick_photo=brick_photo.scaled(35,35);
    break_left=QPixmap(":/img/photo/brick2.png").scaled(15,15);
    break_right=QPixmap(":/img/photo/brick3.png").scaled(15,15);
    Break_Left[0].setPixmap(break_left);
    Break_Left[1].setPixmap(break_left);
    Break_Right[0].setPixmap(break_right);
    Break_Right[1].setPixmap(break_right);
    brick.setPixmap(brick_photo);
}

void Brick::brick_init(QGraphicsScene *scene,double xx,double yy)
{
    brick_scene=scene;
    length=35;
    width=35;
    brick.setPos(xx,yy);
    x=xx;
    y=yy;
    brick_scene->addItem(&brick);
}

void Brick::move(double xx,double yy)
{
    if(state)
    {
        brick.moveBy(xx,yy);
        x+=xx;
        y+=yy;
    }
    else
    {
        Break_Left[0].moveBy(xx,yy);
        Break_Left[1].moveBy(xx,yy);
        Break_Right[0].moveBy(xx,yy);
        Break_Right[1].moveBy(xx,yy);
        x+=xx;
        y+=yy;
    }
}

void Brick::broken()
{
    state=0;
    brick.setPos(0,1000);
    Break_Left[0].setPos(x-10,y-10);
    Break_Left[1].setPos(x-10,y+10);
    Break_Right[0].setPos(x+20,y-10);
    Break_Right[1].setPos(x+20,y+10);
    brick_scene->addItem(&Break_Right[0]);
    brick_scene->addItem(&Break_Right[1]);
    brick_scene->addItem(&Break_Left[0]);
    brick_scene->addItem(&Break_Left[1]);
    x=0;
    y=1000;
}
