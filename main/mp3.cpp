#include <string>
#include <ctime>
#include <iomanip>
#include <iostream>
#include "mp3.h"




void Track::setName(std::string trackName)
{
	name = trackName;
}
void Track::setAuthor(std::string authorName)
{
	author = authorName;
}
void Track::setDuration(std::tm duration_t)
{
	duration.tm_min = duration_t.tm_min;
	duration.tm_sec = duration_t.tm_sec;
	
}
void Track::getTrackInfo()
{
	std::cout << name << " - " << author << "  Add:" << std::put_time(dateAddedTm, "%d.%m.%y") << std::endl << "Duration: " << std::put_time(&duration, "%M:%S") << std::endl << std::endl;
}




std::string getTrackName(int numberOfTrackName)
{
	switch (numberOfTrackName)
	{
	case(0): return "Rain";
	case(1): return "Pain";
	case(2): return "Snow";
	case(3): return "Dog";
	case(4): return "Cat";
	case(5): return "City";
	case(6): return "Sky";
	case(7): return "Dry";
	case(8): return "Name";
	case(9): return "Home";
	}

}


std::string getAuthorName(int numberOfTrackName)
{
	switch (numberOfTrackName)
	{
	case(0): return "Billi";
	case(1): return "Villi";
	case(2): return "Milli";
	case(3): return "Bob";
	case(4): return "Pop";
	case(5): return "Rob";
	case(6): return "Nana";
	case(7): return "Ken";
	case(8): return "Calen";
	case(9): return "Dilan";
	}
}

void Player::addTracks()
{
	std::srand(std::time(nullptr));
	for (int i = 0; i < 10; i++)
	{
		trackList[i].setName(getTrackName(std::rand() % 10));
		trackList[i].setAuthor(getAuthorName(std::rand() % 10));
		std::tm duration_t;
		duration_t.tm_min = std::rand() % 3 + 1;
		duration_t.tm_sec = std::rand() % 57 + 1;
		trackList[i].setDuration(duration_t);
	}
}


void Player::getTrackList()
{
	for (int i = 0; i < 10; i++)
	{
		trackList[i].getTrackInfo();
	}
}


int Player::selectTrack()
{
	getTrackList();
	std::cout << "Enter track number:";
	int trackNumber;
	std::cin >> trackNumber;
	if (trackNumber > 10 or trackNumber < 0)
	{
		trackNumber = selectTrack();
	}
	return trackNumber;
}


void Player::getPlayStatus()
{
	if	   (playStatus == 1)
	{
		std::cout << "Status : Playing" << std::endl;
	}
	else if(playStatus == 0)
	{
		std::cout << "Status : Stop" << std::endl;
	}
	else if (playStatus == 2)
	{
		std::cout << "Status : Pause" << std::endl;
	}
}

void Player::play(int trackNumber = -1)
{
	if (playStatus == 0)
	{
		if (trackNumber == -1)
		{
			trackNumber = selectTrack();
		}
		playStatus = 1;
		getPlayStatus();
		trackList[trackNumber].getTrackInfo();
	}
}

void Player::stop()
{
	if (playStatus == 1)
	{
		playStatus = 0;
		getPlayStatus();
	}
}

void Player::pause()
{
	if (playStatus == 2)
	{
		playStatus = 2;
		getPlayStatus();
	}
}

void Player::next()
{
	if (playStatus == 1)
	{
		pause();
		std::srand(std::time(nullptr));
		int trackNumber = std::rand() % 10;
		play(trackNumber);
	}
}

void Player::selectCommand(std::string command)
{
	commandList commands;
	if (command == commands.play)
	{
		play();
	}
	else if (command == commands.pause)
	{
		pause();
	}
	else if (command == commands.stop)
	{
		stop();
	}
	else if (command == commands.next)
	{
		next();
	}
}