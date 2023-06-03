#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget.h"
#include "musicplayer.h"
#include "global.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //背景音乐

    musicPlayer->backMusicPlay(bgmusic);

    connect(ui->pushButton_2,SIGNAL(clicked(bool)),SLOT(when_configure_clicked()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),SLOT(when_start_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::when_configure_clicked()
{
    configure* conf= new configure();
    conf->show();
}

void MainWindow::when_start_clicked()
{
    close();
    Widget* w=new Widget();
    w->show();
}


