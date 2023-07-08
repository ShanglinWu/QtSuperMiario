#ifndef BRICK_H
#define BRICK_H
#include<QGraphicsPixmapItem>//图形元素
#include<QGraphicsScene>

class Brick
{
public:
    int type;
    int width;
    int length;
    double x;
    double y;
    int state=1;
    Brick();
    QPixmap brick_photo;
    QPixmap break_left;
    QPixmap break_right;
    QGraphicsPixmapItem Break_Left[2];
    QGraphicsPixmapItem Break_Right[2];
    QGraphicsPixmapItem brick;
    QGraphicsScene *brick_scene;
    void brick_init(QGraphicsScene *scene,double xx,double yy);
    void move(double xx,double yy);
    void broken();
};

#endif // BRICK_H
