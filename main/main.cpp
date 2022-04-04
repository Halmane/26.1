#include <iostream>
#include "mp3.h"

int main()
{
    Player* player = new Player;
    player->addTracks();

    std::string command;

    while (command != "exit")
    {
        std::cout << "Enter command:";
        std::cin >> command;
        player->selectCommand(command);
    }
}

