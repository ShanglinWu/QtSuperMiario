#ifndef CANNIBAL_H
#define CANNIBAL_H
#include<QGraphicsPixmapItem>//图形元素
#include<QGraphicsScene>

class Cannibal
{
public:
    Cannibal();
    int type;
    int width;
    int length;
    double x;
    double y;
    QPixmap cannibal_photo;
    QGraphicsPixmapItem cannibal;
    QGraphicsScene *cannibal_scene;
    void cannibal_init(QGraphicsScene *scene,double xx,double yy);
    void move(double xx,double yy);
    void collision();
};

#endif // CANNIBAL_H
