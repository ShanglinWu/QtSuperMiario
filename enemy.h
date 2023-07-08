#ifndef ENEMY_H
#define ENEMY_H
#include<QGraphicsPixmapItem>//图形元素
#include<QGraphicsScene>
#include"global.h"
#include<brick.h>
#include<cannibal.h>
class enemy
{
public:
    int type;//判断class类型
    int start;//起始位置
    int dir;
    enemy();
    QGraphicsScene *enemyscene;
    QGraphicsPixmapItem master;
    QPixmap walk_left;
    QPixmap walk_right;
    QPixmap dead_left;
    QPixmap dead_right;
    void enemy_init(QGraphicsScene *scene,double xx,double yy);
//    void enemy_collision();
    void move(double x,double y);
    void enemy_move();
    void enemy_block(Brick* b,Cannibal* c);
    void enemy_die();
    int x();
    int y();

};

#endif // ENEMY_H
