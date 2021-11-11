#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<time.h>

using namespace std;

BOOL gotoxy(const WORD x, const WORD y)
{
    COORD xy;
    xy.X = x;
    xy.Y = y;
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

class musicplaylist
{
private:
    int songno;
    char name[40], artist[40], genre[40];
    float rating;
public:
    musicplaylist();
    void getdata();
    void showdata();
    int ret_songno();
    ~musicplaylist();
};
musicplaylist::musicplaylist()
{
    songno = 0;
    name;
    artist;
    genre;
    rating = 0.0;
}
musicplaylist::~musicplaylist()
{
    cout << "\n\n\n  \n\n\n";
}

void musicplaylist::getdata()
{
    string temp;
    gotoxy(15, 4); cout << "ENTER THE SONG DETAILS:  \n";
    gotoxy(10, 7); cout << "S O N G  NO. : ";
    cin >> songno;
    gotoxy(10, 9); cout << "N A M E : ";
    cin.ignore();
    cin.getline(name, 30);
    gotoxy(10, 11); cout << "A R T I S T : ";
    cin.getline(artist, 40);
    gotoxy(10, 13); cout << "G E N R E : ";
    cin.getline(genre, 10);
    gotoxy(10, 15); cout << "R A T I N G : ";
    cin >> rating;

}

/*
for the csv file
.
.
.
void create_list()
{
    fstream f;
    f.open("playlist.csv", ios::out | ios::app);
    musicplaylist mp;
    f << songno << "," << name << "," << artist << "," << genre << "," << rating << endl;

    f.close();
    system("PAUSE");
}
*/

void create()
{
    system("CLS");
    fstream f("playlist.dat", ios::binary | ios::out | ios::app);
    musicplaylist mp;
    mp.getdata();
    f.write((char*)&mp, sizeof(mp));
    f.close();
}

void musicplaylist::showdata()
{
    gotoxy(15, 5); cout << " S O N G   N O :" << songno;
    gotoxy(15, 7); cout << " N A M E : " << name;
    gotoxy(15, 9); cout << " A R T I S T : " << artist;
    gotoxy(15, 11); cout << " G E N R E : " << genre;
    gotoxy(15, 13); cout << " R A T I N G : " << rating;
    gotoxy(15, 17); cout << endl;
}

int musicplaylist::ret_songno()
{
    return songno;
}


void display_list()
{
    system("CLS");
    int k = 7, l = 20;
    fstream fin;
    string data;

    gotoxy(75, 3); cout << "T H E    P L A Y L I S T ..... ";
    gotoxy(15, 5); cout << "SONG NO, NAME, ARTIST, GENRE ,RATING ";

    // Open an existing file
    fin.open("playlist.csv", ios::in);
    while (!fin.eof())      //if not at end of file, continue reading numbers
    {
        getline(fin, data);
        gotoxy(l, k); cout << data;
        k = k + 1;
    }
    cout << endl;
    system("PAUSE");
    fin.close();
}

void display()
{
    fstream f("playlist.dat", ios::binary | ios::in);
    musicplaylist mp;
    while (f.read((char*)&mp, sizeof(mp)))
    {
        mp.showdata();
        gotoxy(50, 23);
        Sleep(500);
        system("CLS");
    }
    f.close();
}


void delete_song()
{
    fstream f1("playlist.dat", ios::binary | ios::in);
    fstream f2("temp.dat", ios::binary | ios::out);
    musicplaylist mp;
    int songnumber, found = 0;
    char confirm = 'y';
    cout << "ENTER THE SONG NO. : ";
    cin >> songnumber;

    while (f1.read((char*)&mp, sizeof(mp)))
    {
        if (songnumber == mp.ret_songno())
        {
            mp.showdata();
            found = 1;

            gotoxy(80, 23); cout << "ARE YOU SURE YOU WANT TO DELETE THIS SONG ? [Y/N]";
            cin >> confirm;

            if (confirm == 'n' || confirm == 'N')
                f2.write((char*)&mp, sizeof(mp));
            else
                cout << " R E C O R D   D E L E T E D ..............";
        }
        else
        {
            f2.write((char*)&mp, sizeof(mp));
        }
    }
    f1.close();
    f2.close();

    remove("playlist.dat");
    rename("temp.dat", "playlist.dat");

    if (found == 0)
    {
        gotoxy(10, 5); cout << " NO SUCH SONG EXIST IN THE DATA ";
        cout << endl << endl;
    }
}

void search_song()
{
    gotoxy(10, 3);
    int found = 0;
    fstream f("playlist.dat", ios::binary | ios::in);
    musicplaylist mp;
    int songnumber;
    cout << "ENTER THE SONG NUMBER TO BE SEARCHED FOR : ";
    cin >> songnumber;
    while (f.read((char*)&mp, sizeof(mp)))
    {
        if (songnumber == mp.ret_songno())
        {
            mp.showdata();
            found = 1;
        }
    }
    f.close();
    if (found == 0)
    {
        gotoxy(80, 25); cout << " NO SUCH SONG EXIST IN THE DATA";
    }
}


/*
void modify_song()
{
    fstream f("playlist.dat", ios::binary | ios::in | ios::out);
    musicplaylist mp;
    long songnumber,found=0;
    cout << "ENTER THE SONG NUMBER TO BE CHANGED : ";
    cin >> songnumber;

    while (f.read((char*)&mp, sizeof(mp)))
    {
        if (songnumber == mp.ret_songno())
        {
            mp.showdata();
            found = 1;
            cout << endl << endl;
            cout << "ENTER NEW DETAILS : ";
            mp.getdata();
            f.seekp(f.tellg(0,f.end)-sizeof(mp), ios::beg);
            f.write((char*)&mp, sizeof(mp));
            gotoxy(80, 25); cout << "S O N G   M O D I F I E D";
            break;
        }
    }
    f.close();
    if (found == 0)
    {
        cout << "NO SUCH SONG EXIST IN THE DATA";
    }
}*/

void edit()
{
    int temp = 0;
    do
    {
        system("CLS");
        gotoxy(75, 12); cout << "< < < < S E T T I N G > > > > ";
        gotoxy(77, 15); cout << "1. D E L E T E   S O N G : ";
        gotoxy(77, 17); cout << "2. S E A R C H   S O N G : ";
        gotoxy(77, 19); cout << "3. M O D I F Y   S O N G : ";
        gotoxy(77, 21); cout << "4. E X I T : ";
        cin >> temp;

        if (temp == 1)
        {
            system("CLS");
            delete_song();
            system("PAUSE");
        }
        else if (temp == 2)
        {
            system("CLS");
            search_song();
            system("PAUSE");
        }/*
        else if (temp == 3)
        {
            system("CLS");
            modify_song();
            system("PAUSE");
        }*/
    } while (temp != 4);
}

void printArray(int songnumber_array[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (songnumber_array[i] >= 1 && songnumber_array[i] <= 191)
        {
            cout << songnumber_array[i]<<"\t";
        }
    }
    cout << endl;
}

void randomize(int songnumber_array[], int n)
{
    srand(time(NULL));

    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&songnumber_array[i], &songnumber_array[j]);
    }
}

void search_song_for_shuffling(int songnumber_array[], int n)
{
    fstream f("playlist.dat", ios::binary | ios::in);
    musicplaylist mp;

    int songnumber = songnumber_array[0];

    while (f.read((char*)&mp, sizeof(mp)))
    {
        if (songnumber == mp.ret_songno())
        {
            mp.showdata();
            Sleep(1000);
        }
    }
    f.close();

    for (int i = 0; i < n; i++)
        songnumber_array[i] = songnumber_array[i + 1];

}

void display_fisher_yates(int songnumber_array[], int n)
{
    cout << endl << endl;
    cout << "F I S H E R  Y A T E S  A L G O R I T H M \n";
    printArray(songnumber_array, n);
    cout << endl;
    system("PAUSE");

    for (int i = 0; i < n; i++)
    {
        search_song_for_shuffling(songnumber_array, n);
        system("CLS");

    }

}



void fisher_yates()
{
    fstream f("playlist.dat", ios::binary | ios::in);
    musicplaylist mp;

    int songnumber_array[200];

    int n = sizeof(songnumber_array) / sizeof(songnumber_array[0]);

    int k = 0;
    while (f.read((char*)&mp, sizeof(mp)))
    {
        songnumber_array[k] = mp.ret_songno();
        k++;
    }

    for (int i = 0; i < n; i++)
    {
        if (songnumber_array[i] >= 0)
        {
            cout << songnumber_array[i] << " ";
        }

        else
        {
            songnumber_array[i] = 0;
        }

    }
    cout << endl;
    system("PAUSE");
    randomize(songnumber_array, n);
    display_fisher_yates(songnumber_array, n);
}



void sort_songnumber()
{
    char choice = 'n';
    fstream f("Playlist.dat", ios::binary | ios::in);
    musicplaylist mp;
    int songnumber_array[10];
    int n = sizeof(songnumber_array) / sizeof(songnumber_array[0]);
    int k = 0;
    while (f.read((char*)&mp, sizeof(mp)))
    {
        songnumber_array[k] = mp.ret_songno();
        k++;
    }
    f.close();
    cout << "U N S O R T E D   S O N G   N O  : \t";
    for (int i = 0; i < n; i++)
    {
        if (songnumber_array[i] >= 0)
        {
            cout <<" "<< songnumber_array[i];
        }

    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (songnumber_array[j] > songnumber_array[j + 1])
            {
                swap(&songnumber_array[j], &songnumber_array[j + 1]);
            }
        }
    }
    gotoxy(63, 3); cout << " S O R T E D   S O N G   N U M B E R   L I S T ";
    int l=6;
    for (int i = 0; i < n; i++)
    {
        if (songnumber_array[i] >= 0)
        {
            gotoxy(83, l); cout << songnumber_array[i];
            l++;
        }

    }
    gotoxy(110, 35); cout << "DO YOU WANT TO SAVE THIS ORDER AS A NEW PLAYLIST? [Y/N]  :  ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {

        cout << "SAVED";
        Sleep(1000);
    }

    if (choice == 'n' || choice == 'N')
    {}
}


void sorting_songs()
{
    int temp = 0;
    char choice = 'n';
    do
    {
        system("CLS");
        gotoxy(77, 13); cout << "S O R T  A C C O R I D N G  T O... ";
        gotoxy(77, 17); cout << "1.A C C O R D I N G  T O  S O N G   N O : "; //bubble sort
        gotoxy(77, 19); cout << "2.A C C O R D I N G  T O  N A M E : "; //merge sort
        gotoxy(77, 21); cout << "3.A C C O R D I N G  T O  A R T I S T : ";//quick sort
        gotoxy(77, 23); cout << "4.A C C O R D I N G  T O  G E N R E : ";//heap sort
        gotoxy(77, 25); cout << "5.B A C K : ";
        cin >> temp;

        if (temp == 1)
        {
            system("CLS");
            sort_songnumber();
        }
        else if (temp == 2)
        {
            system("CLS");
            gotoxy(60, 17); cout << "DO YOU WANT TO SAVE THIS ORDER AS A NEW PLAYLIST? [Y/N]";
            cin >> choice;
        }
        else if (temp == 3)
        {
            system("CLS");
            gotoxy(60, 17); cout << "DO YOU WANT TO SAVE THIS ORDER AS A NEW PLAYLIST? [Y/N]";
            cin >> choice;
        }
        else if (temp == 4)
        {
            system("CLS");
            gotoxy(60, 17); cout << "DO YOU WANT TO SAVE THIS ORDER AS A NEW PLAYLIST? [Y/N]";
            cin >> choice;
        }
    } while (temp != 5);
}
int main()
{
    int choice = 0;
    musicplaylist mp;
    do
    {
        system("CLS");
        gotoxy(80, 9); cout << "__________________________";
        gotoxy(75, 10); cout << "    M U S I C    P L A Y L I S T";
        gotoxy(77, 17); cout << "1.A D D  S O N G  I N  T H E  L I S T :";
        gotoxy(77, 19); cout << "2.D I S P L A Y  P L A Y L I S T :";
        gotoxy(77, 21); cout << "3.E D I T  P L A Y L I S T :";
        gotoxy(77, 23); cout << "4.S H U F F L E  P L A Y L I S T :";
        gotoxy(77, 25); cout << "5.S O R T  P L A Y L I S T : ";
        gotoxy(77, 27); cout << "6.S U G G E S T I V E  P L A Y L I S T :";
        gotoxy(77, 29); cout << "7.E X I T : ";
        cin >> choice;

        if (choice == 1)
        {
            system("CLS");
            create();
        }
        else if (choice == 2)
        {
            system("CLS");
            display_list();
        }
        else if (choice == 3)
        {
            system("CLS");
            edit();
        }
        else if (choice == 4)
        {
            system("CLS");
            fisher_yates();
        }
        else if (choice == 5)
        {
            sorting_songs();
        }
        else if (choice == 6)
        {
            for (int i = 1; i <= 4; i++)
            {
                system("CLS");
                gotoxy(63, 17); cout << "  S U G G E S T I N G  A  P L A Y L I S T  ";
                for (int j = 105; j <= 111; j++)
                {
                    gotoxy(j, 17); cout << ".";
                    Sleep(300);
                }
            }
        }
        else if (choice == 7)
        {
            system("CLS");
            gotoxy(63, 17); cout << " < < < < E X I T I N G  T H E  S H U F F L E R > > > >";
            gotoxy(63, 37);
            exit(0);
        }
        else
        {
            gotoxy(67, 33); cout << "ENTER A VALID NUMBER ..... TRY 1,2,3,4,5,6 or 7 TO EXIT\n\n";
            system("PAUSE");
        }
    } while (choice != 7);
    return 0;
}
