#include "gameover.h"
#include "ui_gameover.h"
#include "widget.h"

gameover::gameover(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameover)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),SLOT(when_restart_clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),SLOT(close()));
}

gameover::~gameover()
{
    delete ui;
}


void gameover::when_restart_clicked()
{
    close();
    Widget* w=new Widget();
    w->show();
}

