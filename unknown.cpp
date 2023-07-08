#include "unknown.h"
#include<iostream>

using namespace std;




void Unknown::Unknown_Init(QGraphicsScene *scene, double xx, double yy){
    unknown_scene=scene;
    length=35;
    width=35;
    unknown_photo=QPixmap(":/img/photo/unknown_stay.png");
    unknown_photo=unknown_photo.scaled(35,35);
    //    break_left=QPixmap(":/img/photo/brick2.png").scaled(15,15);
    //    break_right=QPixmap(":/img/photo/unknown3.png").scaled(15,15);
    //    Break_Left[0].setPixmap(break_left);
    //    Break_Left[1].setPixmap(break_left);
    //    Break_Right[0].setPixmap(break_right);
    //    Break_Right[1].setPixmap(break_right);
    unknown.setPixmap(unknown_photo);
    unknown.setPos(xx,yy);
    x=xx;
    y=yy;
    unknown_scene->addItem(&unknown);

}


void Unknown::move(double xx,double yy)
{
    unknown.moveBy(xx,yy);
    x+=xx;
    y+=yy;
}

void Unknown::broken(QGraphicsScene *scene,int id)
{
}


