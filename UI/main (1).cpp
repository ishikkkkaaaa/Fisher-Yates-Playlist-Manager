#include<iostream>
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

void create()
{
	//linked list,genre,rating,time
    system("CLS");
    // file pointer
    fstream f;
    // opens an existing csv file or creates a new file.
    f.open("playlist.csv", ios::out | ios::app);
    string name;
    cout<<"ENTER THE DETAILS OF THE SONG : \n";
    cin>>name;
	system("PAUSE");

    // Insert the data to file
    f<<"\t"<<name<<"\n";
    f.close();
}

void read_record()
{
    system("CLS");
    int k=5,l=70;
    fstream fin;
    string data;

    gotoxy(60,3);cout<<"T H E    P L A Y L I S T ..... \n";
    // Open an existing file
    fin.open("playlist.csv", ios::in);
    for(int i=1; i<=10; i++)
    {
        getline(fin,data);
        l=l+2;
        gotoxy(l,k);cout<<data;
        k=k+2;
    }
	system("PAUSE");
    fin.close();
}

int main()
{
    int choice=0;
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


        if(choice==1)
        {
            create();
        }
        else if(choice==2)
        {
            read_record();
        }
        else if(choice==5)
        {
            int temp=0;
            system("CLS");
            gotoxy(77,13);cout<< "S O R T  A C C O R I D N G  T O... ";
            gotoxy(77,17);cout<< "1.A C C O R D I N G  T O  N A M E : ";
            gotoxy(77,19);cout<< "2.A C C O R D I N G  T O  A R T I S T : ";
            gotoxy(77,21);cout<< "3.A C C O R D I N G  T O  G E N R E : ";
            gotoxy(77,23);cout<< "4.B A C K : ";
                          cin>>temp;

            if(temp==1)
            {
                system("CLS");
                char choice='n';
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
            int temp=0;
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
            cin>>temp;
            //system("PAUSE");
        }

    }while(choice!=7);
    return 0;
}
