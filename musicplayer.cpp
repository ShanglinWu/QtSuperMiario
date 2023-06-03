#include "musicplayer.h"
#include<QSoundEffect>
#include <QDebug>

MusicPlayer::MusicPlayer(QObject *parent) : QObject(parent)
{
    mediaPlayer = new QSoundEffect;
    backPlayer = new QSoundEffect;
}

void MusicPlayer::play(QString str)
{
    mediaPlayer->setSource(QUrl::fromLocalFile(str));
    mediaPlayer->setLoopCount(1);
    mediaPlayer->setVolume(20);
    if(jump)
        mediaPlayer->play();
    //playerList.append(mediaPlayer);
}

void MusicPlayer::backMusicPlay(QString str)
{
    backPlayer->setSource(QUrl::fromLocalFile(str));
    backPlayer->setLoopCount(QSoundEffect::Infinite);
    backPlayer->setVolume(20);
    backPlayer->play();
    //backplayerList.append(backPlayer);
}

void MusicPlayer::stopPlayBGM()
{
    backPlayer->stop();
}
