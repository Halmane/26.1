#include <iostream>
#include "mp3.h"

int main()
{
    Player* player = new Player;
    player->addTacks();
    player->getTrackList();
    delete player;
}

