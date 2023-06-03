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
#include <QSoundEffect>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void mariomove();
    void mariojump();
    void enemymove();
    bool moveCollision();
    bool jumpCollision();
    void marioDie();
    void show_gameover();

private:
    Ui::Widget *ui;
    QGraphicsView mGameView;
    QGraphicsScene mScene;
    QGraphicsPixmapItem mario_right[21];
    QGraphicsPixmapItem mario_left[21];
    QGraphicsPixmapItem mymario;
    QGraphicsPixmapItem mBackGround1;
    QGraphicsPixmapItem mBackGround2;
    QGraphicsPixmapItem brick[100];
    QGraphicsPixmapItem castle;
    QTimer* mariomovetimer;
    QTimer* mariojumptimer;
    QTimer* diemovetimer;
    QTimer* gameovertimer;

    //记录keyevent
    QList<int> mylist;

    //跳跃相关
    QSoundEffect * jumpSound;
    bool is_first=false;

    //enemy
    QGraphicsPixmapItem enemy[3];
    QTimer *enemymovetimer;
    QPixmap enemy_left_ph;
    QPixmap enemy_right_ph;
    int enemy_dir[3]={0};


};
#endif // WIDGET_H
