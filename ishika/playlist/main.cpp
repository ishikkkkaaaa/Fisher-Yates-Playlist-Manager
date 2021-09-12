#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "songs.h"
using namespace std;

Songs::Songs()
{
	this->songName = " ";
	this->artistName = " ";
	this->albumName = " ";
	this->playTime = 1; 
	this->year = 1901;
	this->starRating = 1;
	this->genre = "Other";
}

Songs::Songs(string SN, string ArN, string AlN, int PT, int YR, int SR, string GR)
{
	this->songName = SN;
	this->artistName = ArN;
	this->albumName = AlN;
	this->playTime = PT; 
	this->year = YR;
	this->starRating = SR;
	this->genre = GR;
}

string Songs::getSongName()
{
	return songName;
}

void Songs::setSongName(string newSong)
{
	this->songName = newSong;
}

string Songs::getArtistName()
{
	return artistName;
}

void Songs::setArtistName(string newArtist)
{
	this->artistName = newArtist;
}

string Songs::getAlbumName()
{
	return albumName;
}

void Songs::setAlbumName(string newAlbum)
{
	this->albumName = newAlbum;
}

int Songs::getPlayTime()
{
	return playTime;
}

void Songs::setPlayTime(int newTime)
{
	this->playTime = newTime;
}

int Songs::getYear()
{
	return year;
}

void Songs::setYear(int newYear)
{
	this->year = newYear;
}

int Songs::getStarRating()
{
	return starRating;
}

void Songs::setStarRating(int newStarRating)
{
	this->starRating = newStarRating;
}

string Songs::getSongGenre()
{
	return genre;
}

void Songs::setSongGenre(string newGenre)
{
	this->genre = newGenre;
}

void Songs::addSongLibrary(vector<Songs> *library, vector<Songs> *playlist)
{
	cout << "Please enter song name: ";
	getline(cin, songName);
	cout << "Please enter artist name: ";
	getline(cin, artistName);
	cout << "Please enter album name: ";
	getline(cin, albumName);
	while(true)
	{
		cout << "Please enter length of song in seconds: ";
		cin >> playTime;
		if(!cin.fail() && playTime > 0)
			break;
		else if(cin.fail())
			cout << "Time must be in seconds. Please enter the song's length again: ";
		else if(playTime <= 0)
			cout << "Time must be greater than 0 seconds. Please enter the song's length again: ";		
		cin >> playTime;
	}
	while(true)
	{
		cout << "Please enter the year the song was made: ";
		cin >> year;
		if(!cin.fail() && year < 1900)
			break;
		else if(cin.fail())
			cout << "Year must be in numbers. Please enter the song's year again: ";
		else if(year < 1900)
			cout << "Year must be 1900 or greater. Please enter the song's year again: ";		
		cin >> year;
	}
	while(true)
	{
		cout << "Please enter a star rating for the song (1 to 5 stars): ";
		cin >> starRating;
		if(!cin.fail() && starRating >= 1 && starRating <= 5)
			break;
		else if(cin.fail())
			cout << "Rating can only be the digits 1, 2, 3, 4, or 5. Please enter a new rating for the song: ";
		else if(starRating < 1 || starRating > 5)
			cout << "Rating must be between 1 and 5. Please enter the song's year again: ";		
		cin >> year;
	}
	while(true)
	{
		cout << "Please enter a genre (Rock, Rap, Country, Gospel, or Other) for the song: ";
		cin >> genre;
		if(genre == "Rock" || genre == "Rap" || genre == "Country" || genre == "Gospel" || genre == "Other")
			break;
		else
			cout << "Genre not recognized. Please enter one of the five given genres (Rock, Rap, Country, Gospel, or Other)";		
		cin >> genre;
	}
		
	Songs* newSongInfo = new Songs();
	newSongInfo->setSongName(songName);
	newSongInfo->setArtistName(artistName);
	newSongInfo->setAlbumName(albumName);
	newSongInfo->setPlayTime(playTime);
	newSongInfo->setYear(year);
	newSongInfo->setStarRating(starRating);
	newSongInfo->setSongGenre(genre);	
	library.push_back(newSongInfo);
	
	while(true)
	{
		cout << "Enter y to add the song to you playlist, or n to do nothing: ";
		cin >> yesOrNo;
		if(yesOrNo = 'y')
		{
			playlist.push_back(newSongInfo);
			break;
		}
		else if(yesOrNo == 'n')
			break;
		else
			cout << "Invalid operation. Please enter y to add the song to you playlist, or n to do nothing: ";
		cin >> yesOrNo;
	}	
}