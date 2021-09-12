// C program for ID3 tagging of music files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
struct tags // Structure to store tagging information.
{
    char title[100], artist[100], album[100], 
         track_num[100], year[100], genre[100];
};
  
void merge_file(char* file1, char* file2, char* file3)
{
    FILE *f1, *f2, *f3;
    int ch;
    f1 = fopen(file1, "rb"); // Opening in write mode.
    f2 = fopen(file2, "rb");
    f3 = fopen(file3, "wb");
  
    if (f1 == NULL || f2 == NULL) {
        exit(EXIT_FAILURE);
    }
  
    while ((ch = fgetc(f1)) != EOF) // Appending tagging info.
        fputc(ch, f3);
  
    while ((ch = fgetc(f2)) != EOF) // Appending media file info.
        fputc(ch, f3);
  
    // Closing the files.
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
  
void tagging(char* file1, char* file2, char* file3)
{
    int size = 0;
    char clean[100];
    struct tags t;
    unsigned char pad1[7] = { 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76 };
    unsigned char pad2[3] = { 0x00, 0x00, 0x00 };
  
    FILE* f1;
    f1 = fopen(file1, "wb");
  
    fprintf(f1, "ID3");
    fwrite(pad1, sizeof(pad1), 1, f1); /*Essential tag to identify 
                                        as an ID3 tagged media file.*/
  
    gets(clean); // Clearing the input stream.
  
    // Taking input from user.
    printf("\nEnter the title of the mp3:");
    scanf("%[^\n]%*c", t.title);
  
    printf("\nEnter the artist of the mp3:");
    scanf("%[^\n]%*c", t.artist);
  
    printf("\nEnter the album of the mp3.\n");
    scanf("%[^\n]%*c", t.album);
  
    printf("\nEnter the year of the mp3.\n");
    scanf("%[^\n]%*c", t.year);
  
    printf("\nEnter the track number of the mp3.\n");
    scanf("%[^\n]%*c", t.track_num);
  
    // Track Number
    // Tag to identify track number.
    fprintf(f1, "TRCK"); 
  
    // Essential 3 NULL bits required for separation.
    fwrite(pad2, sizeof(pad2), 1, f1); 
  
    size = strlen(t.track_num);
    size++; // Calculating size.
  
     // Appending the size of the track number to tag.
    fprintf(f1, "%c", size);
  
    // Essential 3 NULL bits required for separation.
    fwrite(pad2, sizeof(pad2), 1, f1);
  
    // Adding tag number entered by the user.
    fprintf(f1, "%s", t.track_num); 
  
    // Print Year
    fprintf(f1, "TYER"); 
    fwrite(pad2, sizeof(pad2), 1, f1); 
    size = strlen(t.year);
    size++; // Calculating size.
    fprintf(f1, "%c", size);
    fwrite(pad2, sizeof(pad2), 1, f1); 
    fprintf(f1, "%s", t.year); 
  
    // Print Title
    fprintf(f1, "TIT2"); 
    fwrite(pad2, sizeof(pad2), 1, f1); 
    size = strlen(t.title);
    size++; // Calculating size.
    fprintf(f1, "%c", size);
    fwrite(pad2, sizeof(pad2), 1, f1); 
    fprintf(f1, "%s", t.title);
  
    // Print Artist
    fprintf(f1, "TPE1"); 
    fwrite(pad2, sizeof(pad2), 1, f1); 
    size = strlen(t.artist);
    size++; // Calculating size.
    fprintf(f1, "%c", size);
    fwrite(pad2, sizeof(pad2), 1, f1); 
    fprintf(f1, "%s", t.artist); 
  
    // Print Album
    fprintf(f1, "TALB"); 
    fwrite(pad2, sizeof(pad2), 1, f1); 
    size = strlen(t.album);
    size++; // Calculating size.
    fprintf(f1, "%c", size);
    fwrite(pad2, sizeof(pad2), 1, f1); 
    fprintf(f1, "%s", t.album); 
  
    // Print Genre
    fprintf(f1, "TCON"); // Tag to identify genre.
    fwrite(pad2, sizeof(pad2), 1, f1);
    size = strlen(t.genre);
    size++; // Calculating size.
    fprintf(f1, "%c", size); 
    fwrite(pad2, sizeof(pad2), 1, f1); 
    fprintf(f1, "%s", t.genre); 
  
    fclose(f1); // Closing the file.
}
  
int main()
{
    char file1[100] = "media_info.txt", file2[100], file3[100];
  
    printf("\nEnter the input mp3 file name\n");
    scanf("%s", file2);
    printf("\nEnter the output mp3 file name\n");
    scanf("%s", file3);
  
    // Function to append media info to input file.
    tagging(file1, file2, file3); 
  
    // Function to merge media info and media
    // input file.
    merge_file(file1, file2, file3); 
    return 0;
}