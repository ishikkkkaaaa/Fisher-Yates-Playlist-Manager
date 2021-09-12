#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#define MAX_LEN 30
using namespace std;

typedef struct
{
    string name; // for the filename
    //... change this to your specification
} hashd;

hashd hashArray[MAX_LEN]; // tentative

int returnHash(string s)
{
    // A simple hashing, no collision handled
    int sum = 0, index = 0;
    for (string::size_type i = 0; i < s.length(); i++)
    {
        sum += s[i];
    }
    index = sum % MAX_LEN;
    return index;
}

int main()
{
    string fileName;
    int index;
    cout << "Enter filename        ::\t";
    cin >> fileName;
    cout << "Enter filename is     ::\t" + fileName << "\n";
    index = returnHash(fileName);
    cout << "Generated index is ::\t" << index << "\n";
    hashArray[index].name = fileName;
    cout << "Filename in array    ::\t" << hashArray[index].name;
    return 0;
}