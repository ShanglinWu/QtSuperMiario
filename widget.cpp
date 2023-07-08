#include "widget.h"
#include "ui_widget.h"
#include "global.h"
#include "gameover.h"
#include "unknown.h"
#include "win.h"
#include<QKeyEvent>
#include<QTimer>
#include<QDebug>
#include<QPainter>

//参数变量
//死亡状态
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
static int right=0,left=0;
static bool is_right=true;
static bool jump=false;
static bool is_first=false;
static bool moveblocked=false;
double jumpspeed=60;
double die_jump_speed=50;
double brick_jump_speed[67]={0};
static double jumphight=0;
//
static bool right_block=false;
static bool left_block=false;
static bool brick_right_block=false;
static bool brick_left_block=false;

//
static bool on_brick[67]={false};
static bool on_unknown[5]={false};
static bool on_cannibal[3]={false};
static bool mfall=false;
double fallspeed=0;

//
static int score=0;
static int coin=0;
//
static bool winf=false;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    game_init();
    ui->setupUi(this);
    this->setFixedSize(1000,600);
    mGameView.setSceneRect(QRect(0,0,1000,660));
    mScene.setSceneRect(QRect(0,0,1000,660));
    qDebug("setup!");

    //设置背景图片、并添加到场景（越早添加的，在越底下）
    mBackGround1.setPixmap(QPixmap(":/img/photo/sky.png"));
    mScene.addItem(&mBackGround1);




    //设置mario原始图片、初始位置
    mymario.setPixmap(QPixmap(":/img/mario_right/walk_right1.png"));
    mymario.setPos(100,551-mario_height);
    //设置跑动中的mario图片
    {
        mario_right[0].setPixmap(QPixmap(":/img/mario_right/walk_right1.png"));
        mario_right[1].setPixmap(QPixmap(":/img/mario_right/walk_right2.png"));
        mario_right[2].setPixmap(QPixmap(":/img/mario_right/walk_right3.png"));
        mario_right[3].setPixmap(QPixmap(":/img/mario_right/walk_right4.png"));
        mario_right[4].setPixmap(QPixmap(":/img/mario_right/walk_right5.png"));
        mario_right[5].setPixmap(QPixmap(":/img/mario_right/walk_right6.png"));
        mario_right[6].setPixmap(QPixmap(":/img/mario_right/walk_right7.png"));
        mario_right[7].setPixmap(QPixmap(":/img/mario_right/walk_right8.png"));
        mario_right[8].setPixmap(QPixmap(":/img/mario_right/walk_right9.png"));
        mario_right[9].setPixmap(QPixmap(":/img/mario_right/walk_right10.png"));
        mario_right[10].setPixmap(QPixmap(":/img/mario_right/walk_right11.png"));
        mario_right[11].setPixmap(QPixmap(":/img/mario_right/walk_right12.png"));
        mario_right[12].setPixmap(QPixmap(":/img/mario_right/walk_right13.png"));
        mario_right[13].setPixmap(QPixmap(":/img/mario_right/walk_right14.png"));
        mario_right[14].setPixmap(QPixmap(":/img/mario_right/walk_right15.png"));
        mario_right[15].setPixmap(QPixmap(":/img/mario_right/walk_right16.png"));
        mario_right[16].setPixmap(QPixmap(":/img/mario_right/walk_right17.png"));
        mario_right[17].setPixmap(QPixmap(":/img/mario_right/walk_right18.png"));
        mario_right[18].setPixmap(QPixmap(":/img/mario_right/walk_right19.png"));
        mario_right[19].setPixmap(QPixmap(":/img/mario_right/walk_right20.png"));
        mario_right[20].setPixmap(QPixmap(":/img/mario_right/walk_right21.png"));

        mario_left[0].setPixmap(QPixmap(":/img/walk_left/walk_left.png"));
        mario_left[1].setPixmap(QPixmap(":/img/walk_left/walk_left1.png"));
        mario_left[2].setPixmap(QPixmap(":/img/walk_left/walk_left2.png"));
        mario_left[3].setPixmap(QPixmap(":/img/walk_left/walk_left3.png"));
        mario_left[4].setPixmap(QPixmap(":/img/walk_left/walk_left4.png"));
        mario_left[5].setPixmap(QPixmap(":/img/walk_left/walk_left5.png"));
        mario_left[6].setPixmap(QPixmap(":/img/walk_left/walk_left6.png"));
        mario_left[7].setPixmap(QPixmap(":/img/walk_left/walk_left7.png"));
        mario_left[8].setPixmap(QPixmap(":/img/walk_left/walk_left8.png"));
        mario_left[9].setPixmap(QPixmap(":/img/walk_left/walk_left9.png"));
        mario_left[10].setPixmap(QPixmap(":/img/walk_left/walk_left10.png"));
        mario_left[11].setPixmap(QPixmap(":/img/walk_left/walk_left11.png"));
        mario_left[12].setPixmap(QPixmap(":/img/walk_left/walk_left12.png"));
        mario_left[13].setPixmap(QPixmap(":/img/walk_left/walk_left13.png"));
        mario_left[14].setPixmap(QPixmap(":/img/walk_left/walk_left14.png"));
        mario_left[15].setPixmap(QPixmap(":/img/walk_left/walk_left15.png"));
        mario_left[16].setPixmap(QPixmap(":/img/walk_left/walk_left16.png"));
        mario_left[17].setPixmap(QPixmap(":/img/walk_left/walk_left17.png"));
        mario_left[18].setPixmap(QPixmap(":/img/walk_left/walk_left18.png"));
        mario_left[19].setPixmap(QPixmap(":/img/walk_left/walk_left19.png"));
        mario_left[20].setPixmap(QPixmap(":/img/walk_left/walk_left20.png"));
    }

    //设置城堡图片、大小、初始位置
    castle.setPixmap(QPixmap(":/img/photo/castle.png").scaled(130,130));
    castle.setPos(3290,140);
    rainbow.setPixmap(QPixmap(":/img/photo/rainbow.png").scaled(60,60));
    rainbow.setPos(3290,200);


    double enemy_pos[7][2]={{600,508},{800,508},{1600,508},{1800,508},{2000,508},{3300,508},{3500,508}};
    for(int i=0;i<7;i++)
        enemy_master[i].enemy_init(&mScene,enemy_pos[i][0],enemy_pos[i][1]);
    double brk_pos[67][2]={  {600,400},{635,400},{670,400},{705,270},{740,270},{775,270},{810,400},{845,400},{880,400},{1700,400},
                          {1735,400},{1770,400},{1805,400},{1840,400},{1875,400},{1910,400},{1945,400},{1980,400},{2015,400},
                          {2050,400},{1875,270},{1910,270},{1945,270},{1980,270},{2280,516},{2315,516},{2350,516},{2385,516},
                          {2420,516},{2500,516},{2535,516},{2570,516},{2605,516},{2640,516},{2315,481},{2350,481},{2385,481},
                          {2420,481},{2500,481},{2535,481},{2570,481},{2605,481},{2350,446},{2385,446},{2420,446},{2500,446},
                          {2535,446},{2570,446},{2385,411},{2420,411},{2500,411},{2535,411},{2420,376},{2500,376},{2800,400},
                          {2835,400},{2870,400},{2935,270},{2970,270},{3005,270},{3040,270},{3075,270},{3265,270},{3300,270},
                          {3335,270},{3370,270},{3405,270}};
    double unk_pos[5][2]={{845,270},{1770,270},{950,400},{2155,400},{3010,400}};
    for(int i=0;i<67;i++)
        bricks[i].brick_init(&mScene,brk_pos[i][0],brk_pos[i][1]);
    for(int i=0;i<5;++i)
    {
        unknowns[i].Unknown_Init(&mScene, unk_pos[i][0],unk_pos[i][1]);
    }
    double can_pos[3][2]={{1100,418},{1400,418},{300,418}};
    can[0].cannibal_init(&mScene,can_pos[0][0],can_pos[0][1]);
    can[1].cannibal_init(&mScene,can_pos[1][0],can_pos[1][1]);
    can[2].cannibal_init(&mScene,can_pos[2][0],can_pos[2][1]);
    //增加地
    QPixmap ground_photo =QPixmap(":/audio/photo/ground.png");
    ground.setPixmap(ground_photo);
    ground2.setPixmap(ground_photo);
    ground3.setPixmap(ground_photo);
    ground3.setPos(-1600,551);
    ground.setPos(0,551);
    ground2.setPos(1500,551);
    mScene.addItem(&ground);
    mScene.addItem(&ground2);
    mScene.addItem(&ground3);

    //图片添加到场景,需要给一个地址，取地址
    mScene.addItem(&castle);
    mScene.addItem(&mymario);
    mScene.addItem(&rainbow);

    //记分栏
    draw_score_board();

    //设置视图场景
    mGameView.setScene(&mScene);

    //设置视图父亲为窗口
    mGameView.setParent(this);
    mGameView.show();

//    QPainter painter(this);
//    painter.drawPixmap(600, 200, QPixmap(":/img/photo/coin.png"), 0, 0, 30, 30);


}

Widget::~Widget()
{
    delete ui;
}





void Widget::game_init(){
    undefeatable=false;
    died=false;
    is_first=false;

    memset(kill,false, sizeof(kill));
    memset(first_die,true, sizeof(first_die));
    memset(brick_break,false, sizeof(brick_break));
    memset(unk_break,false, sizeof(unk_break));
    memset(first_break,true, sizeof(first_break));
    memset(unk_first_break,true, sizeof(unk_first_break));
    //跳跃和行进参数
    right=0;
    left=0;
    is_right=true;
    jump=false;
    moveblocked=false;
    jumpspeed=60;
    die_jump_speed=50;
    memset(brick_jump_speed,0, sizeof(brick_jump_speed));
    jumphight=0;
    score=0;
    coin=0;
    //
    right_block=false;
    left_block=false;
    brick_right_block=false;
    brick_left_block=false;
    //
    memset(on_brick,false, sizeof(on_brick));
    memset(on_unknown,false,sizeof(on_unknown));
    memset(on_cannibal,false, sizeof(on_cannibal));
    mfall=false;
    fallspeed=0;

    winf=false;

    musicPlayer->backMusicPlay(bgmusic);

    //按键事件
    mariomovetimer = new QTimer();
    mariomovetimer -> start(18);
    connect(mariomovetimer,&QTimer::timeout,this,&Widget::mariomove);

    mariojumptimer = new QTimer();
    mariojumptimer->start(1);
    connect(mariojumptimer,&QTimer::timeout,this,&Widget::mariojump);

    //敌人移动
    enemymovetimer=new QTimer();
    enemymovetimer->start(30);
    connect(enemymovetimer,&QTimer::timeout,this,&Widget::enemymove);

    //mario死亡
    diemovetimer=new QTimer();
    diemovetimer->start(1);
    connect(diemovetimer,&QTimer::timeout,this,&Widget::Die);
    //    connect(diemovetimer,&QTimer::timeout,this,&Widget::mariofall);

    //    //信息绘制
    //    drawtimer=new QTimer();
    //    drawtimer->start(18);
    //    connect(drawtimer,&QTimer::timeout,this,&Widget::draw);

    gameovertimer=new QTimer();
    connect(gameovertimer,&QTimer::timeout,this,&Widget::show_gameover);
    gameovertimer->setSingleShot(true);
}

void Widget::keyPressEvent(QKeyEvent *event)
{

        if(event->key()==Qt::Key_D)
        {
            if(!mylist.contains(event->key()))
                mylist.append(event->key());

        }
        else if(event->key()==Qt::Key_A)
        {
            if(!mylist.contains(event->key()))
                mylist.append(event->key());
        }
        else if(event->key()==Qt::Key_W)
        {
            if(!mylist.contains(event->key())&&!moveblocked)
                mylist.append(event->key());
        }

}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    //移除
    if(mylist.contains(event->key()))
    {
        mylist.removeOne(event->key());
    }

}

void Widget::mariomove()
{
    for(int keycode : mylist)
    {
        cannibal_collison();//检查能否往前走
        brick_collison();//加一个碰壁
        unknownCollision();
        check_block();
        win_check();
        if(keycode==Qt::Key_D)
        {
            if(moveblocked)
                continue;
            is_right=true;
            if(mymario.x()>=700)
            {
                mymario.setX(700);
            }
            right=(right+1)%21;
            mymario.setPixmap(mario_right[right].pixmap());
            if(!right_block && ! brick_right_block)
            {
                mymario.moveBy(5,0);
            }
            fall();
        }
        else if(keycode==Qt::Key_A)
        {
            if(moveblocked)
                continue;
            is_right=false;
            if(mymario.x()<100)
            {
                mymario.setX(100);
            }

            left=(left+1)%21;
            mymario.setPixmap(mario_left[left].pixmap());

            if(!left_block&&!brick_left_block)
                mymario.moveBy(-5,0);
            fall();
        }
        else if(keycode==Qt::Key_W)
        {
            if(!moveblocked)
            {
                is_first=true;
                jump=true;
                moveblocked=true;
            }
        }
        if(!jump)
            background_move(5);
    }

}

void Widget::mariojump()
{
    if(jump)
    {

        if(is_first)
        {
            musicPlayer->play(jumpsound);
            is_first=false;
        }
        //qDebug()<<jumpspeed;
        jumpspeed=jumpspeed-9.8*0.015;
        mymario.moveBy(0,-jumpspeed*0.015);
        win_check();
        for(int keycode : mylist)
        {
            check_block();
            if(keycode==Qt::Key_D)
            {
                is_right=true;
                if(mymario.x()>=700)
                {
                    mymario.setX(700);
                }
                mymario.setPixmap(mario_right[right].pixmap());
                if(!right_block&&!brick_right_block)
                {
                    mymario.moveBy(0.3,0);
                    background_move(0.3);
                }
            }
            if(keycode==Qt::Key_A)
            {
                is_right=false;
                if(mymario.x()<100)
                {
                    mymario.setX(100);
                }
                mymario.setPixmap(mario_left[left].pixmap());
                if(!left_block&&!brick_left_block)
                {
                    mymario.moveBy(-0.3,0);
                    background_move(0.3);
                }
            }
        }

        jumphight+=jumpspeed*0.015;
        jumpCollision();
        brick_collison();
        unknownCollision();
        cannibal_collison();//检查是否跳上去了
        check_block();//检查是否能往前走
        if(jumphight<0)
        {
            if((551-mario_height)-mymario.y()<=2)
            {
                jump=false;
                jumpspeed=60;
                jumphight=0;
                moveblocked=false;
            }
        }
    }
    if(mfall)
    {
        qDebug("fall");
        fallspeed-=9.8*0.015;
        mymario.moveBy(0,-fallspeed*0.015);
        for(int keycode : mylist)
        {
            if(keycode==Qt::Key_D)
            {
                is_right=true;
                if(mymario.x()>=700)
                {
                    mymario.setX(700);
                }
                mymario.setPixmap(mario_right[right].pixmap());
                if(!right_block&&!brick_right_block)
                {
                    mymario.moveBy(0.3,0);
                    background_move(0.3);
                }
            }
            if(keycode==Qt::Key_A)
            {
                is_right=false;
                if(mymario.x()<100)
                {
                    mymario.setX(100);
                }
                mymario.setPixmap(mario_left[left].pixmap());
                if(!left_block&&!brick_left_block)
                {
                    mymario.moveBy(-0.3,0);
                    background_move(0.3);
                }
            }
        }
        jumpCollision();
        brick_collison();
        unknownCollision();
        cannibal_collison();//检查是否跳上去了
        check_block();//检查是否能往前走

        if((551-mario_height)-mymario.y()<=2 )
        {
            mfall=false;
            fallspeed=0;
            moveblocked=false;
        }
    }
}


void Widget::enemymove()
{
    if(died)
        return;

    for(int i=0;i<7;i++)
    {
        if(!kill[i])
        {
            enemy_master[i].enemy_block(bricks,can);
            enemy_master[i].enemy_move();
            if(moveCollision()){
                moveblocked=true;
                died=true;
                musicPlayer->play(diedsound);
                gameovertimer->start(2000);
            }
        }
    }
}

bool Widget::moveCollision()
{
    if(undefeatable)
        return false;
    for(int i=0;i<7;i++)
    {
        if((mymario.x()-enemy_master[i].x()<=20 && mymario.x()-enemy_master[i].x()>=-20)
            && (mymario.y()-enemy_master[i].y()<=10 && mymario.y()-enemy_master[i].y()>=-20))
        {
                return true;
        }
    }
    return false;
}

void Widget::jumpCollision()
{
    for(int i=0;i<7;i++)
    {
        if((mymario.x()-enemy_master[i].x()<=20 && mymario.x()-enemy_master[i].x()>=-20)
        && (enemy_master[i].y()-mymario.y()>=10 && enemy_master[i].y()-mymario.y()<=30)&&((jump&&jumpspeed<0)||(mfall&&fallspeed<0)))
        {
                qDebug("yes");
                jumpspeed=-jumpspeed*0.7;
                fallspeed=-fallspeed;
                kill[i]=true;
                musicPlayer->play(killsound);
                score+=10;
                draw_score_board();
                undefeatable=true;
        }
    }
}

void Widget::Die()
{
    //未初始化初始速度
    if(died)
    {
        die_jump_speed=die_jump_speed-9.8*0.01;
        mymario.moveBy(0,-die_jump_speed*0.01);
        qDebug("die jump");
        if(die_jump_speed<=-150)//调数
        {
            died=false;
            die_jump_speed=50;
            qDebug("ok");
        }
    }
    for(int i=0;i<7;i++)
    {
        if(kill[i])
        {
            if(first_die[i])
            {
                enemy_master[i].enemy_die();
                first_die[i]=false;
            }
            die_jump_speed=die_jump_speed-9.8*0.025;
            enemy_master[i].move(0,-die_jump_speed*0.01);
            if(die_jump_speed<=-150)//调数
            {
                qDebug("kill %d",i);
                died=false;
                die_jump_speed=50;
                undefeatable=false;
                kill[i]=false;
            }
        }
    }
    for(int i=0;i<67;i++)
    {
        if(brick_break[i])
        {
            brick_jump_speed[i]=brick_jump_speed[i]-9.8*0.04;
            bricks[i].move(0,-brick_jump_speed[i]*0.02);
        }
    }
}

void Widget::show_gameover()
{
    musicPlayer->stopPlayBGM();
    close();
    died=false;
    killTimer(mariojumptimer->timerId());
    killTimer(mariomovetimer->timerId());
    gameover* g=new gameover();
    g->show();
}

void Widget::background_move(double step)
{

    if(mymario.x()>700)
    {
        ground.moveBy(-step,0);
        ground2.moveBy(-step,0);
        ground3.moveBy(-step,0);
        castle.moveBy(-step,0);
        rainbow.moveBy(-step,0);
        for(int i=0;i<7;i++)
            enemy_master[i].move(-step,0);
        for(int i=0;i<67;i++)
            bricks[i].move(-step,0);
        for(int i=0;i<5;++i)
            unknowns[i].move(-step,0);
        for(int i=0;i<3;i++)
            can[i].move(-step,0);
        if(ground.x()<=-3000)
            ground.setPos(1500,551);
        if(ground2.x()<=-3000)
            ground2.setPos(1500,551);
        if(ground3.x()<=-3000)
            ground3.setPos(1500,551);
    }
    if(mymario.x()<=100)
    {
        ground.moveBy(step,0);
        ground2.moveBy(step,0);
        ground3.moveBy(step,0);
        castle.moveBy(step,0);
        rainbow.moveBy(step,0);
        for(int i=0;i<7;i++)
            enemy_master[i].move(step,0);
        for(int i=0;i<67;i++)
            bricks[i].move(step,0);
        for(int i=0;i<5;++i)
            unknowns[i].move(step,0);
        for(int i=0;i<3;i++)
            can[i].move(step,0);
        if(ground.x()>=3000)
            ground.setPos(-1500,551);
        if(ground2.x()>=3000)
            ground2.setPos(-1500,551);
        if(ground3.x()>=3000)
            ground3.setPos(-1500,551);
    }
}

void Widget::brick_collison()
{
    for(int i=0;i<67;i++)
    {
        if((mymario.x()-bricks[i].x<=25 && mymario.x()-bricks[i].x>=-30)
            && (mymario.y()-bricks[i].y<=32 && mymario.y()-bricks[i].y>=30)
            &&(!died))
        {
            if(first_break[i]&&jumpspeed>0)
            {
                bricks[i].broken();
                musicPlayer->play(bricksound);
                jumpspeed=-jumpspeed;
                qDebug()<<mymario.x()<<' '<<mymario.y();
                first_break[i]=false;
                brick_break[i]=true;
                score+=5;
                draw_score_board();
            }
        }
        else if((mymario.x()-bricks[i].x<=25 && mymario.x()-bricks[i].x>=-30)
                && (bricks[i].y-mymario.y()>=43&& bricks[i].y-mymario.y()<=46)
                && (jumpspeed<0||!jump))
        {
            on_brick[i]=true;
            mymario.setPos(mymario.x(),bricks[i].y-mario_height);
            fall();
            jump=false;
            jumpspeed=60;
            jumphight=0;
            moveblocked=false;
            mfall=false;
            fallspeed=0;
        }
    }
}

void Widget::unknownCollision()
{
    for(int i=0;i<5;i++)
    {
        if((mymario.x()-unknowns[i].x<=25 && mymario.x()-unknowns[i].x>=-30)
            && (mymario.y()-unknowns[i].y<=32 && mymario.y()-unknowns[i].y>=30)
            && (!died))
        {
            if(jumpspeed>0)
            {
                if(unk_first_break[i]){
                    unknowns[i].broken(&mScene,i);
                    coin++;
                    unk_first_break[i]=false;
                    unk_break[i]=true;
                    score+=10;
                    musicPlayer->play(coinsound);
                    draw_score_board();
                }
                jumpspeed=-jumpspeed;
                qDebug()<<mymario.x()<<' '<<mymario.y();

            }
        }
        else if((mymario.x()-unknowns[i].x<=25 && mymario.x()-unknowns[i].x>=-30)
                 && (unknowns[i].y-mymario.y()>=43&& unknowns[i].y-mymario.y()<=46)
                 && (jumpspeed<0||!jump))
        {
            on_unknown[i]=true;
            mymario.setPos(mymario.x(),unknowns[i].y-mario_height);
            fall();
            jump=false;
            jumpspeed=60;
            jumphight=0;
            moveblocked=false;
            mfall=false;
            fallspeed=0;
        }
    }
}

void Widget::cannibal_collison()
{
    for(int i=0;i<3;i++)
    if((can[i].x-mymario.x()<40 && can[i].x-mymario.x()>-130)&&(can[i].y-mymario.y()>=40&&can[i].y-mymario.y()<=49)&&jumpspeed<=0)
    {
        on_cannibal[i]=true;
        mymario.setPos(mymario.x(),can[i].y-46);
        fall();
        jump=false;
        jumpspeed=60;
        jumphight=0;
        moveblocked=false;
        mfall=false;
        fallspeed=0;
    }

}

void Widget::fall()
{
    check_on();
    for(int k=0;k<3;k++)
        if(on_cannibal[k])
        {
            if(can[k].x-mymario.x()>=35 || can[k].x-mymario.x()<=-120)
            {
                qDebug("in");
                mfall=true;
                moveblocked=true;
                on_cannibal[k]=false;
            }
        }
    for(int i=0;i<67;i++)
    {
        if(on_brick[i])
            {
                if((i==66 && is_right) || (i==0 && !is_right))
                {
                    if((mymario.x()-bricks[i].x>24 || mymario.x()-bricks[i].x<-30))
                    {
                        on_brick[i]=false;
                        if((is_right &&!on_brick[i+1]&&mymario.x()>bricks[i].x)||(!is_right && !on_brick[i-1]&&mymario.x()<bricks[i].x))
                        {
                            mfall=true;
                            moveblocked=true;
                            return;
                        }
                    }
                }
                else
                {
                    if((mymario.x()-bricks[i].x>24 || mymario.x()-bricks[i].x<-30))
                    {

                        on_brick[i]=false;
                        if((is_right &&!on_brick[i+1]&&mymario.x()>bricks[i].x)||(!is_right && !on_brick[i-1]&&mymario.x()<bricks[i].x))
                        {
                            mfall=true;
                            moveblocked=true;
                            return;
                        }
                    }
                }
            }
    }
    for(int i=0;i<5;i++)
    {
            if(on_unknown[i])
            {

                if((mymario.x()-unknowns[i].x>24 || mymario.x()-unknowns[i].x<-30))
                {

                    on_unknown[i]=false;
                    if((is_right &&!on_unknown[i+1]&&mymario.x()>unknowns[i].x)||(!is_right && !on_unknown[i-1]&&mymario.x()<unknowns[i].x))
                    {
                        mfall=true;
                        moveblocked=true;
                        return;
                    }
                }
            }
    }
}

void Widget::check_on()
{
    for(int i=0;i<3;i++)
    {
            if((can[i].x-mymario.x()<40 && can[i].x-mymario.x()>-130)&&(can[i].y-mymario.y()>=40&&can[i].y-mymario.y()<=49)&&(jumpspeed<0||!jump))
        {
            on_cannibal[i]=true;
        }
        else
            on_cannibal[i]=false;
    }
    for(int i=0;i<67;i++)
    {
        if((mymario.x()-bricks[i].x<=30 && mymario.x()-bricks[i].x>=-36)
        && (bricks[i].y-mymario.y()>=43&& bricks[i].y-mymario.y()<=46)
        && (jumpspeed<0||!jump))
        {
                on_brick[i]=true;
        }
        else
                on_brick[i]=false;
    }
    for(int i=0;i<5;i++)
    {
        if((mymario.x()-unknowns[i].x<=30 && mymario.x()-unknowns[i].x>=-36)
            && (unknowns[i].y-mymario.y()>=43&& unknowns[i].y-mymario.y()<=46)
            && (jumpspeed<0||!jump))
        {
                on_unknown[i]=true;
        }
        else
                on_unknown[i]=false;
    }
}

void Widget::check_block()
{
    for(int i=0;i<3;i++)
    {
        if(can[i].x-mymario.x()<40 && can[i].x-mymario.x()>-130 && can[i].y-mymario.y()<40)
        {
                if(can[i].x>mymario.x())
                {
                    right_block=true;
                    left_block=false;
                    i=100;//退出
                }
                else
                {
                    left_block=true;
                    right_block=false;
                    i=100;
                }
        }
        else
        {
                right_block=false;
                left_block=false;
        }
    }
    for(int i=0;i<67;i++)
    {
            if(bricks[i].x-mymario.x()<45 && bricks[i].x-mymario.x()>-40 && bricks[i].y-mymario.y()>-34&&bricks[i].y-mymario.y()<40)
            {
                if(bricks[i].x>mymario.x())
                {
                    brick_right_block=true;
                    brick_left_block=false;
                    return;
                }
                else
                {
                    brick_left_block=true;
                    brick_right_block=false;
                    return;
                }
            }
            else
            {
                brick_right_block=false;
                brick_left_block=false;
            }
    }
    for(int i=0;i<5;i++)
    {
            if(unknowns[i].x-mymario.x()<45 && unknowns[i].x-mymario.x()>-40 && unknowns[i].y-mymario.y()>-34&&unknowns[i].y-mymario.y()<40)
            {
                if(unknowns[i].x>mymario.x())
                {
                    brick_right_block=true;
                    brick_left_block=false;
                    return;
                }
                else
                {
                    brick_left_block=true;
                    brick_right_block=false;
                    return;
                }
            }
            else
            {
                brick_right_block=false;
                brick_left_block=false;
            }
    }
}

void Widget::draw_score_board()
{
    //score
    scoreboard.setPixmap(QPixmap(":/img/photo/score.png").scaled(30,30));
    scoreboard.setPos(20,20);
    mScene.addItem(&scoreboard);
    score_text.setPlainText(QVariant(score).toString());
    score_text.setPos(50, 10);
    score_text.setFont(QFont("Arial", 50));
    mScene.addItem(&score_text);

    //coin
    coinboard.setPixmap(QPixmap(":/img/photo/single_coin.png").scaled(50,50));
    coinboard.setPos(500,20);
    mScene.addItem(&coinboard);
    coin_text.setPlainText(QVariant(coin).toString());
    coin_text.setPos(550, 10);
    coin_text.setFont(QFont("Arial", 50));
    mScene.addItem(&coin_text);
}

void Widget::win_check()
{
    if(winf)
            return;
    if( (mymario.x()>(castle.x()-20)) && (mymario.x()<(castle.x()+20)) &&
        (mymario.y()>(castle.y()-20)) && (mymario.y()<(castle.y()+40))){
        winf=true;
        close();
        died=false;
        killTimer(mariojumptimer->timerId());
        killTimer(mariomovetimer->timerId());
        win* w=new win();
        w->show();
    }
}


