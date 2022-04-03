#include <string>
#include <ctime>
#include <iomanip>
#include <iostream>


class Track
{
	std::string name;
	std::string author;
	std::time_t dateAdded = std::time(nullptr);
	std::tm duration;
	std::tm* dateAddedTm = std::localtime(&dateAdded);

public:
	void setName(std::string trackName)
	{
		name = trackName;
	}
	void setAuthor(std::string authorName)
	{
		author = authorName;
	}
	void setDuration()
	{
		std::srand(std::time(nullptr));
		duration.tm_min = std::rand() % 4 + 1;
		duration.tm_sec = std::rand() % 58 + 1;
	}
	void getTrackInfo()
	{
		
		std::cout << name << " - " << author << "  Add:" << std::put_time(dateAddedTm,"%D.%M.%y") << std::endl << "Duration: " << std::put_time(&duration, "%m:%s") << std::endl << std::endl;
	}
};

enum trackNameNumber
{
	Rain = 0,
	Pain ,
	Snow ,
	Dog  ,
	Cat  ,
	City ,
	Sky  ,
	Dry  ,
	Name ,
	Home
};

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


class Player
{
	Track* trackList = new Track[10];
public:
	void addTacks()
	{
		std::srand(std::time(nullptr));
		for (int i = 0; i < 10; i++)
		{
			trackList[i].setName(getTrackName(std::rand() % 10));
			trackList[i].setAuthor(getAuthorName(std::rand() % 10));
			trackList[i].setDuration();
		}
	}

	void getTrackList()
	{
		for (int i = 0; i < 10; i++)
		{
			trackList[i].getTrackInfo();
		}
	}
	
};