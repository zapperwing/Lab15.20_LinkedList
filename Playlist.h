#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <string>

using namespace std;

class PlaylistNode {
    public:
        PlaylistNode();
        PlaylistNode(string id, string songName, string artistName, int lengthTime);
        void InsertAfter(PlaylistNode* ptr);
        void SetNext(PlaylistNode* ptr);
        string getID();
        string getSong();
        string getArtist();
        int getLength();
        PlaylistNode* GetNext();
        void PrintPlaylistNode();

    private:
        string ID;
        string song;
        string artist;
        int length;
        PlaylistNode* next;


};

class Playlist {
    public:
        Playlist();
        void AddSong(string id, string songName, string artistName, int lengthTime);
        bool RemoveSong(string ID);
        void PrintList();
        bool ChangePosition(int oldPos, int newPos);
        void SongsByArtist(string artist);
        int totalTime();

    private:
        PlaylistNode* head;
        PlaylistNode* tail;
  
};

#endif