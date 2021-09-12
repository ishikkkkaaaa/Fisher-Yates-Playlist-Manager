//https://www.dreamincode.net/forums/topic/403985-make-a-playlist-with-the-music-info-input-by-the-user/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Song
{
    string artistName;
    string songTitle;
    string songGenre;
    double songLength;

    Song(const string s_title, const string n_artist, const string s_genre, const double s_length)
        : songTitle(s_title), artistName(n_artist), songLength(s_length), songGenre(s_genre) {}
};

int main()
{
    struct Song;

    int choice; // To hold a menu choice

    string n_playlist;
    string s_title;
    string n_artist;
    string s_genre;

    double s_length;
    double totalLength;
    double totalAverage;

    cout << "***************************************************" << endl;
    cout << "*                                                 *" << endl;
    cout << "*         Noemi's Playlist Manager                *" << endl;
    cout << "*                                                 *" << endl;
    cout << "***************************************************" << endl;
    cout << endl;

    cout << "Where would you like to start? \n\n";

    // Display the menu of choices.

    cout << "1. Add a New Song \n";
    cout << "2. Add New Playlist\n";
    cout << "3. View All Playlists \n\n";

    cout << "Enter Your Choice: ";
    cin >> choice;

    // Set the numeric output formatting.
    cout << fixed << showpoint << setprecision(2);

    // Respond to the user's menu selection.

    switch (choice)
    {

    case 1:

        cout << "\nTo add a new song please enter the title, artist, genre, and length. \n";
        cout << "\nTitle: ";
        cin >> s_title;
        cout << "\nArtist: ";
        cin >> n_artist;
        cout << "\nGenre: ";
        cin >> s_genre;
        cout << "\nLength: ";
        cin >> s_length;

        cout << "\nYour " << s_genre << " song " << s_title << " by " << n_artist << " at " << s_length << " mintues has been added! \n\n";

        break;

    case 2:

        cout << "\nEnter Playlist Name: ";
        cin >> n_playlist;

        cout << "\nYour new playlist " << n_playlist << " has been added! \n\n";

        cout << "Would you like to add songs to your new playlist? \n\n";

        break;

    case 3:

        totalAverage = s_length;
        totalLength = s_length;

        cout << " Playlist: " << n_playlist << ".\n"
             << "song" << "\nTotal Playlist Length: " << totalLength
             << "\nAverage Song Length: " << totalAverage
             << " \n\nHappyListening!\n"
             << endl;
    }

    return 0;
}
