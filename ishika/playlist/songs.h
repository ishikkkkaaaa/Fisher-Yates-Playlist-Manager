#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "songs.h"	
using namespace std;

void Welcome();

int main()
{
	vector <Songs*> library;
	vector <Songs*> playlist;
	
	Welcome();																// Welcome screen.
	
	
	// Main Menu: (S) enter song, (L) review library, (P)review playlist, or (X) print and end program.
		//Check SLPX in while loop.
	// S - Enter Song: Name, length (s), artist name, album name, genre, star rating, year.
		// Check length (s, ><), check genre(1 of 5), check rating(1-5), check year(>1900<2010).
		// Add to playlist? Y or N (Check); Y copy to playlist vector
		// -> Main Menu
	// L - Print library (function) 
		// Ask to delete song from libray (and playligst; search and delete), add song to playlist not on it yet, or go back to Main Menu.
	// P - Print playlist (function)
		// Ask to delete song from playlist, or back to Main Menu
	// X - Print Both (function; no questions; end)

	return 0;
}

void Welcome()
{
	cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Name/ID - Gabe Audick #7681539807" << endl;
	cout << "Class/Assignment - CSCI-102 Disccusion 29915: Homework Assignment #1" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Welcome to myTunes." << endl << endl;
}