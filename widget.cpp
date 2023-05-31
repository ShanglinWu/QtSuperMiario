#include "widget.h"
#include "ui_widget.h"
#include<QKeyEvent>
#include<QTimer>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
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
    mymario.setPos(100,500);
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
    castle.setPixmap(QPixmap(":/img/photo/castle.png"));
    castle.setScale(0.2);
    castle.setPos(75,500+mymario.pixmap().height()-castle.pixmap().height()*0.2);

    //设置砖的图片
    int brk_width=0;//砖的宽度和厚度
    int brk_height=0;
    QPixmap brk=QPixmap(":/img/photo/brick1.png");
    brk_width=brk.width()*0.06;
    brk_height=brk.height()*0.06;
    //铺第一层砖
    for(int i=0;i<40;i++)
    {
        brick[i].setPixmap(brk);
        brick[i].setScale(0.06);
        brick[i].setPos(0+i*brk_width,500+mymario.pixmap().height());
        mScene.addItem(&brick[i]);
    }
    //铺第二层砖
    for(int i=40;i<80;i++)
    {
        brick[i].setPixmap(brk);
        brick[i].setScale(0.06);
        brick[i].setPos(0+(i-40)*brk_width,500+mymario.pixmap().height()+brk_height*2/3+2);//重叠一小部分，好看
        mScene.addItem(&brick[i]);
    }

    //图片添加到场景,需要给一个地址，取地址
    mScene.addItem(&castle);
    mScene.addItem(&mymario);

    //设置视图场景
    mGameView.setScene(&mScene);

    //设置视图父亲为窗口
    mGameView.setParent(this);
    mGameView.show();

    //按键事件
    mariomovetimer = new QTimer();
    mariomovetimer -> start(18);
    connect(mariomovetimer,&QTimer::timeout,this,&Widget::mariomove);

}

Widget::~Widget()
{
    delete ui;
}
static int right=0,left=0;
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
        if(keycode==Qt::Key_D)
        {
            right=(right+1)%21;
            mymario.setPixmap(mario_right[right].pixmap());
            mymario.moveBy(5,0);
        }
        else if(keycode==Qt::Key_A)
        {
            left=(left+1)%21;
            mymario.setPixmap(mario_left[left].pixmap());
            mymario.moveBy(-5,0);
        }
    }
}

