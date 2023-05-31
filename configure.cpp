#include "configure.h"
#include "ui_configure.h"

configure::configure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::configure)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),SLOT(close()));
}

configure::~configure()
{
    delete ui;
}


