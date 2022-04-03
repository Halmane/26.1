#pragma once
#include <string>
#include <ctime>
#include <iomanip>

class Track
{
	std::string name;
	std::string author;
	std::time_t dateAdded;
	std::tm duration;
	std::tm* dateAddedTm ;

public:
	void setName(std::string);
	void setAuthor(std::string);
	void setDuration();
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

class Player
{
	Track* trackList = new Track[10];
public:
	void addTacks();
	void getTrackList();
};