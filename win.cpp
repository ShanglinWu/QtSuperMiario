#include "win.h"
#include "ui_win.h"
#include "widget.h"

win::win(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::win)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),SLOT(when_restart_clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),SLOT(close()));
}

win::~win()
{
    delete ui;
}

void win::when_restart_clicked()
{
    close();
    Widget* w=new Widget();
    w->show();
}

