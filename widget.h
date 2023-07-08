#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QGraphicsPixmapItem>//图形元素
#include<QGraphicsView>//视图
#include<QGraphicsScene>//场景
#include<QKeyEvent>
#include<QList>
#include"mainwindow.h"
#include "configure.h"
#include "unknown.h"
#include <QSoundEffect>
#include<enemy.h>
#include<brick.h>
#include <cannibal.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void game_init();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void mariomove();
    void mariojump();
    void enemymove();
    bool moveCollision();
    void jumpCollision();
    void unknownCollision();
    void Die();
    void show_gameover();
    void background_move(double step);
    void brick_collison();
    void cannibal_collison();
    void fall();
    void mariofall();
    void check_on();
    void check_block();

    Cannibal can[3];
    Brick bricks[70];
    Unknown unknowns[5];
    enemy enemy_master[7];
    Ui::Widget *ui;
    QGraphicsView mGameView;
    QGraphicsScene mScene;
    QGraphicsPixmapItem mario_right[21];
    QGraphicsPixmapItem mario_left[21];
    QGraphicsPixmapItem mymario;
    QGraphicsPixmapItem mBackGround1;
    QGraphicsPixmapItem castle;
    QGraphicsPixmapItem ground;
    QGraphicsPixmapItem ground2;
    QGraphicsPixmapItem ground3;
    QTimer* mariomovetimer;
    QTimer* mariojumptimer;
    QTimer* diemovetimer;
    QTimer* gameovertimer;

    //记录keyevent
    QList<int> mylist;

    //跳跃相关
    QSoundEffect * jumpSound;

//    //enemy
//    QGraphicsPixmapItem enemy[3];
    QTimer *enemymovetimer;
//    QPixmap enemy_left_ph;
//    QPixmap enemy_right_ph;
//    int enemy_dir[3]={0};


};
#endif // WIDGET_H
