#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),SLOT(when_configure_clicked()));
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

