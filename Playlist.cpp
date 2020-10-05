#include "Playlist.h"

PlaylistNode::PlaylistNode() {
    ID = "noname";
    song = "noname";
    artist = "noname";
    length = 0;
    next = 0;
}

PlaylistNode::PlaylistNode(string id, string songName, string artistName, int lengthTime) {
    ID = id;
    song = songName;
    artist = artistName;
    length = lengthTime;
    next = 0;

}

void PlaylistNode::InsertAfter(PlaylistNode* ptr) {
    this->SetNext(ptr->GetNext());
    ptr->SetNext(this);
    
}

void PlaylistNode::SetNext(PlaylistNode* ptr) {
    next = ptr;
}

PlaylistNode* PlaylistNode::GetNext() {
    return next;
}

string PlaylistNode::getID() {
    return ID;
}

string PlaylistNode::getSong() {
    return song;
}

string PlaylistNode::getArtist() {
    return artist;
}

int PlaylistNode::getLength() {
    return length;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << ID << endl;
    cout << "Song Name: " << song << endl;
    cout << "Artist Name: " << artist << endl;
    cout << "Song Length (in seconds): " << length << endl;

}

// Playlist class implementation 

Playlist::Playlist() {
    head =0;
    tail = 0;
}

void Playlist::AddSong(string id, string songName, string artistName, int lengthTime) {
    PlaylistNode* n = new PlaylistNode(id, songName, artistName, lengthTime);
    if (head ==0) {
        head =n;
        tail = n;
    }
    else {
        n->InsertAfter(tail);
        tail = n;
    }
}

