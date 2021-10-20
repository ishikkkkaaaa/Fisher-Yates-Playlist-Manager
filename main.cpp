#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string>
#include<fstream>

using namespace std;

BOOL gotoxy(const WORD x, const WORD y)
{
    COORD xy;
    xy.X = x;
    xy.Y = y;
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

class musicplaylist
{
	private:
		int songno;
		string name,artist,genre;
		float rating;
   public:
        musicplaylist()
        {
            songno=0;
            name="NOT ASSIGNED";
            artist="NOT ASSIGNED";
            genre="NOT ASSIGNED";
            rating=0.0;
        }
        void getdata();
        void showdata();
};
void musicplaylist::getdata()
{
	system("CLS");
	gotoxy(10,5);cout<<"ENTER THE SONG DETAILS:  \n";
	cout<<"S O N G  NO. : ";
	cin>>songno;
	cout<<"N A M E : ";
	cin>>name;
	cout<<"A R T I S T : ";
	cin>>artist;
	cout<<"G E N R E : ";
	cin>>genre;
	cout<<"R A T I N G :";
	cin>>rating;

    fstream f;
    f.open("playlist.csv", ios::out | ios::app);
	musicplaylist mp;
	f<<songno<<","<<name<<","<<artist<<","<<genre<<","<<rating<<endl;
    gotoxy(10,25);cout<<"S O N G  A D D E D \n";
    f.close();
	system("PAUSE");
}
void read_record()
{
    system("CLS");
    int k=7,l=20;
    fstream fin;
    string data;

    gotoxy(75,3);cout<<"T H E    P L A Y L I S T ..... ";
    gotoxy(15,5);cout<<"SONG NO, NAME, ARTIST, GENRE ,RATING ";

    // Open an existing file
    fin.open("playlist.csv", ios::in);
	while (!fin.eof( ))      //if not at end of file, continue reading numbers
    {
        getline(fin,data);
		gotoxy(l,k);cout<<data;
        k=k+1;
    }
    cout<<endl;
	system("PAUSE");
    fin.close();
}

void musicplaylist::showdata()
{
	read_record();
}

int main()
{
    int choice=0;
    musicplaylist mp;
    do
    {
        system("CLS");
        gotoxy(80,9); cout<< "__________________________";
        gotoxy(75,10);cout<< "    M U S I C    P L A Y L I S T";
        gotoxy(77,17);cout<< "1.A D D  S O N G  I N  T H E  L I S T :";
        gotoxy(77,19);cout<< "2.D I S P L A Y  P L A Y L I S T :";
        gotoxy(77,21);cout<< "3.E D I T  P L A Y L I S T :";
        gotoxy(77,23);cout<< "4.S H U F F L E  P L A Y L I S T :";
        gotoxy(77,25);cout<< "5.S O R T  P L A Y L I S T : ";
        gotoxy(77,27);cout<< "6.S U G G E S T I V E  P L A Y L I S T :";
        gotoxy(77,29);cout<< "7.E X I T : ";
                      cin>>choice;

		if(choice>7 && choice!=404)
		{
				gotoxy(67,33);cout<<"ENTER A VALID NUMBER ..... TRY 1,2,3,4,5,6 or 7 TO EXIT\n\n";
				system("PAUSE");
		}
		
        if(choice==1)
        {
        	mp.getdata();
        }
        else if(choice==2)
        {
			mp.showdata();
        }
        else if(choice==4)
        {
        	system("CLS");
        	cout<<"F I S H E R  Y A T E S  A L G O R I T H M ";
        	// bubble sort for comparision
        	
        	system("PAUSE");
		}
        else if(choice==5)
        {
            int temp=0;
            system("CLS");
            gotoxy(77,13);cout<< "S O R T  A C C O R I D N G  T O... ";
            gotoxy(77,17);cout<< "1.A C C O R D I N G  T O  N A M E : ";
            //merge sort
            gotoxy(77,19);cout<< "2.A C C O R D I N G  T O  A R T I S T : ";
			//quick sort
            gotoxy(77,21);cout<< "3.A C C O R D I N G  T O  G E N R E : ";
            //heap sort
            gotoxy(77,23);cout<< "4.B A C K : ";
                          cin>>temp;

            if(temp==1)
            {
                system("CLS");
                char choice='n';
                string array[2];
			    short loop=0;
			    string line;
			    ifstream myfile ("Codespeedy.txt");
			    if (myfile.is_open())
			    {
			        while (! myfile.eof() )
			        {
			            getline (myfile,line);
			            array[loop] = line;
			            cout << array[loop] << endl;
			            loop++;
			        }
			        myfile.close();
				}
			    else
					cout << "can't open the file";
			    system("PAUSE");
                gotoxy(60,17);cout<< "DO YOU WANT TO SAVE THIS ORDER AS A NEW PLAYLIST? [Y/N]";
                              cin>>choice;
            }
            else if(temp==2)
            {
                system("CLS");
                char choice='n';
                gotoxy(60,17);cout<< "DO YOU WANT TO SAVE THIS ORDER AS A NEW PLAYLIST? [Y/N]";
                              cin>>choice;
            }
            else if(temp==3)
            {
                system("CLS");
                char choice='n';
                gotoxy(60,17);cout<< "DO YOU WANT TO SAVE THIS ORDER AS A NEW PLAYLIST? [Y/N]";
                              cin>>choice;
            }
        }
        else if(choice==6)
        {
            for(int i=1; i<=4; i++)
            {
                system("CLS");
                gotoxy(63,17); cout<< "  S U G G E S T I N G  A  P L A Y L I S T  ";
                for(int j=105; j<=111; j++)
                {
                    gotoxy(j,17); cout<<".";
                    Sleep(300);
                }
            }
        }
        else if(choice==7)
        {
			system("CLS");
			gotoxy(63,17);cout<<" < < < < E X I T I N G  T H E  S H U F F L E R > > > >";
			gotoxy(63,37);
			exit(0);
		}
    }while(choice!=7);
    return 0;
}
