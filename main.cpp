#include "Playlist.h"
#include <iostream>
using namespace std;

void PrintMenu(string title);


int main() {
   string playlistTitle;
   cout << "Enter playlist's title: ";
   getline(cin, playlistTitle);

   PrintMenu(playlistTitle);  
  
   return 0;
}


void PrintMenu(string title) {
   Playlist list;
   string id;
   string nameOfSong;
   string nameOfArtist;
   int length;
   int oldPos;
   int newPos;
   char userSelection;

   while (true) {
       cout << endl << title << " PLAYLIST MENU" << endl;
       cout << "a - Add song" << endl;
       cout << "d - Remove song" << endl;
       cout << "c - Change position of song" << endl;
       cout << "s - Output songs by specific artist" << endl;
       cout << "t - Output total time of playlist (in seconds)" << endl;
       cout << "o - Output full playlist" << endl;
       cout << "q - Quit" << endl << endl;

       cout << "Choose an option: ";
       cin >> userSelection;
       cin.ignore(); 

       if (userSelection == 'q' || userSelection == 'Q') {
           exit(1);
       }

       else if (userSelection == 'a' || userSelection == 'A') {
           cout << "\nADD SONG" << endl;
           cout << "Enter song's unique ID: ";
           cin >> id;
           cin.ignore();
           cout << "Enter song's name: ";
           getline(cin, nameOfSong);
           cout << "Enter artist's name: ";
           getline(cin, nameOfArtist);
           cout << "Enter song's length (in seconds): ";
           cin >> length;
           list.AddSong(id, nameOfSong, nameOfArtist, length);
       }

       else if (userSelection == 'd' || userSelection == 'D') {
           cout << "\nREMOVE SONG" << endl;
           cout << "Enter song's unique ID: ";
           cin >> id;
           list.RemoveSong(id);
       }

       else if (userSelection == 'c' || userSelection == 'C') {
           cout << "\nCHANGE POSITION OF SONG" << endl;
           cout << "Enter song's current position: ";
           cin >> oldPos;
           cout << "Enter new position for song: ";
           cin >> newPos;
           list.ChangePosition(oldPos, newPos);
       }

       else if (userSelection == 's' || userSelection == 'S') {
           cout << "\nOUTPUT SONGS BY SPECIFIC ARTIST" << endl;
           cout << "Enter artist's name: ";
           getline(cin, nameOfArtist);          
           list.SongsByArtist(nameOfArtist);
       }

       else if (userSelection == 't' || userSelection == 'T') {
           cout << "\nOUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
           cout << "Total time: " << list.totalTime() << " seconds" << endl;
       }

       else if (userSelection == 'o' || userSelection == 'O') {
           cout << endl << title << " - OUTPUT FULL PLAYLIST" << endl;
           list.PrintList();
       }
       else {
           cout << "Invalid selection. Please try again." << endl;
       }

   }
   
} 