#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QGraphicsPixmapItem>//图形元素
#include<QGraphicsView>//视图
#include<QGraphicsScene>//场景
#include<QKeyEvent>
#include<QList>
#include<mainwindow.h>
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
    QList<int> mylist;
};
#endif // WIDGET_H
