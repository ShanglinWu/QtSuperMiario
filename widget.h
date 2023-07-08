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
#include <QGraphicsTextItem>
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
    void draw_score_board();
    void win_check();

//    void paintEvent(QPaintEvent *event);

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
    QGraphicsPixmapItem scoreboard;
    QGraphicsPixmapItem coinboard;
    QGraphicsPixmapItem castle;
    QGraphicsPixmapItem rainbow;
    QGraphicsPixmapItem ground;
    QGraphicsPixmapItem ground2;
    QGraphicsPixmapItem ground3;
    QGraphicsTextItem score_text;
    QGraphicsTextItem coin_text;
    QTimer* mariomovetimer;
    QTimer* mariojumptimer;
    QTimer* diemovetimer;
    QTimer* gameovertimer;
    QTimer* drawtimer;

    //记录keyevent
    QList<int> mylist;

    //跳跃相关
    QSoundEffect * jumpSound;

    QSoundEffect* coinSound;

//    //enemy
//    QGraphicsPixmapItem enemy[3];
    QTimer *enemymovetimer;
//    QPixmap enemy_left_ph;
//    QPixmap enemy_right_ph;
//    int enemy_dir[3]={0};

    bool undefeatable=false;
    bool died=false;
    bool kill[7]={false};
    bool first_die[7]={true,true,true,true,true,true,true};
    bool brick_break[67]={false};
    bool unk_break[5]={false};
    int first_break[67]={true,true,true,true,true,true,true,true,true,true
                           ,true,true,true,true,true,true,true,true,true,true
                           ,true,true,true,true,true,true,true,true,true,true
                           ,true,true,true,true,true,true,true,true,true,true
                           ,true,true,true,true,true,true,true,true,true,true
                           ,true,true,true,true,true,true,true,true,true,true
                           ,true,true,true,true,true,true,true};
    int unk_first_break[5]={true};
    //跳跃和行进参数
    int right=0,left=0;
    bool is_right=true;
    bool jump=false;
    bool is_first=false;
    bool moveblocked=false;
    double jumpspeed=60;
    double die_jump_speed=50;
    double brick_jump_speed[67]={0};
      double jumphight=0;
    //
      bool right_block=false;
      bool left_block=false;
     bool brick_right_block=false;
      bool brick_left_block=false;

    //
      bool on_brick[67]={false};
      bool on_unknown[5]={false};
      bool on_cannibal[3]={false};
      bool mfall=false;
    double fallspeed=0;

    //
      int score=0;
      int coin=0;
    //
      bool winf=false;



};
#endif // WIDGET_H
