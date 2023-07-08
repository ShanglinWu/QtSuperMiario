#include "enemy.h"

enemy::enemy()
{

}

void enemy::enemy_init(QGraphicsScene *scene,double xx,double yy)
{
    enemyscene=scene;
    dir=1;//向左走
    walk_left=QPixmap(":/img/photo/master_0.png");
    walk_right=QPixmap(":/img/photo/master_1.png");
    dead_left=walk_left.scaled(42,25);
    dead_right=walk_right.scaled(42,25);
    master.setPixmap(walk_right);
    master.setPos(xx,yy);
    scene->addItem(&master);
}

void enemy::move(double x,double y)
{
    master.moveBy(x,y);
}

void enemy::enemy_move()
{
    if(dir==0)
    {
        master.moveBy(-2,0);
    }
    else
    {
        master.moveBy(2,0);
    }
}

void enemy::enemy_block(Brick *b, Cannibal *c)
{
    for(int i=0;i<3;i++)
    {
        if(c[i].x-master.x()<40 && c[i].x-master.x()>-130 && c[i].y-master.y()<40)
        {
            if(dir==0)
            {
                master.setPixmap(walk_right);
                dir=1;
            }
            else
            {
                master.setPixmap(walk_left);
                dir=0;
            }
        }
    }
    for(int i=0;i<67;i++)
    {
        if(b[i].x-master.x()<45 && b[i].x-master.x()>-40 && b[i].y-master.y()>-34&&b[i].y-master.y()<40)
        {
            if(dir==0)
            {
                master.setPixmap(walk_right);
                dir=1;
            }
            else
            {
                master.setPixmap(walk_left);
                dir=0;
            }
        }
    }
}

void enemy::enemy_die()
{
    if(dir==0)
        master.setPixmap(dead_left);
    else
        master.setPixmap(dead_right);
    master.setPos(master.x(),526);
}

int enemy::x()
{
    return master.x();
}

int enemy::y()
{
    return master.y();
}
