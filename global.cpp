#ifndef GLOBAL_CPP
#define GLOBAL_CPP

#include "global.h"

MusicPlayer *musicPlayer = new MusicPlayer;
QString bgmusic=":/audio/sound/main_theme_sped_up - instance.wav";
QString jumpsound=":/audio/sound/small_jump.wav";
QString diedsound=":/audio/sound/death.wav";
QString coinsound=":/audio/sound/coin.wav";
QString bricksound=":/audio/sound/brick_smash.wav";
QString killsound=":/audio/sound/kick.wav";


int sky_length=1500;
int mario_height=43;
int ground_length=1600;
int master_height=43;
#endif // GLOBAL_CPP
