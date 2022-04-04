#pragma once
#include <string>
#include <ctime>
#include <iomanip>

class Track
{
	std::string name;
	std::string author;
	std::time_t dateAdded = std::time(nullptr);
	std::tm duration;
	std::tm* dateAddedTm = std::localtime(&dateAdded);

public:
	void setName(std::string);
	void setAuthor(std::string);
	void setDuration(std::tm);
	void getTrackInfo();
};

enum trackNameNumber
{
	Rain = 0,
	Pain,
	Snow,
	Dog,
	Cat,
	City,
	Sky,
	Dry,
	Name,
	Home
};

std::string getTrackName(int);

enum authorName
{
	Billi = 0,
	Villi,
	Milli,
	Bob,
	Pop,
	Rob,
	Nana,
	Ken,
	Calen,
	Dilan
};

std::string getAuthorName(int);

struct commandList
{
	std::string play = "play";
	std::string pause = "pause";
	std::string stop = "stop";
	std::string next = "next";
};

class Player
{
	Track* trackList = new Track[10];
	int playStatus = 0;
public:
	void addTracks();
	void getTrackList();
	int selectTrack();
	void getPlayStatus();
	void play(int);
	void stop();
	void pause();
	void next();
	void selectCommand(std::string);
};

