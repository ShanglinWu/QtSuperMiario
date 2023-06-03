#include "configure.h"
#include "ui_configure.h"
#include "mainwindow.h"
#include "global.h"

configure::configure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::configure)
{
    ui->setupUi(this);
    ui->checkBox->setCheckState(Qt::Checked);
    ui->checkBox_2->setCheckState(Qt::Checked);

    connect(ui->pushButton,SIGNAL(clicked()),SLOT(close()));
    connect(ui->checkBox,SIGNAL(stateChanged(int)),SLOT(when_voice_clicked()));
    connect(ui->checkBox_2,SIGNAL(stateChanged(int)),SLOT(when_music_clicked()));
}


configure::~configure()
{
    delete ui;
}

void configure::when_voice_clicked()
{
    if(ui->checkBox->isChecked())
    {
        musicPlayer->jump=true;
    }
    else
        musicPlayer->jump=false;
}

void configure::when_music_clicked()
{
    if(ui->checkBox_2->isChecked())
    {
        musicPlayer->backMusicPlay(bgmusic);
    }
    else
        musicPlayer->stopPlayBGM();
}


