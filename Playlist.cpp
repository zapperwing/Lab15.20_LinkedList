#include "Playlist.h"

PlaylistNode::PlaylistNode() {
    ID = "none";
    song = "none";
    artist = "none";
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

string PlaylistNode::GetID() {
    return ID;
}

string PlaylistNode::GetSongName() {
    return song;
}

string PlaylistNode::GetArtistName() {
    return artist;
}

int PlaylistNode::GetSongLength() {
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

bool Playlist::RemoveSong(string id) {
   if (head == NULL) {
       cout << "Playlist is empty" << endl;
       return false;
   }

   PlaylistNode* curr = head;
   PlaylistNode* prev = NULL;
   while (curr != NULL) {
       if (curr->GetID() == id) {
           break;
       }
       prev = curr;
       curr = curr->GetNext();
   }

   if (curr == NULL) {
       cout << "\"" << curr->GetSongName() << "\" is not found" << endl;
       return false;
   }
   else {
       if (prev != NULL) {
           prev->SetNext(curr->GetNext());
       }
       else {
           head = curr->GetNext();
       }

       if (tail == curr) {
           tail = prev;
       }
   
       cout << "\"" << curr->GetSongName() << "\" removed" << endl;
       delete curr;
       return true;
   }
}

bool Playlist::ChangePosition(int oldPos, int newPos) {
   if (head == NULL) {
       cout << "Playlist is empty" << endl;
       return false;
   }


   PlaylistNode* prev = NULL;
   PlaylistNode* curr = head;

   int pos;
   if (head == NULL || head == tail) {
       return false;
   }

   for (pos = 1; curr != NULL && pos < oldPos; pos++) {
       prev = curr;
       curr = curr->GetNext();
   }
   if (curr != NULL) {
       string currentSong = curr->GetSongName();

       if (prev == NULL) {
           head = curr->GetNext();
       }
       else {
           prev->SetNext(curr->GetNext());
       }

       if (curr == tail) {
           tail = prev;
       }

       PlaylistNode* curr1 = curr;
       prev = NULL;
       curr = head;
       //now locate the new position
       for (pos = 1; curr != NULL && pos < newPos; pos++) {
           prev = curr;
           curr = curr->GetNext();
       }

       //insert in located position

       if (prev == NULL) {
           curr1->SetNext(head);
           head = curr1;
       }
       else {
           curr1->InsertAfter(prev);
       }

       if (curr == NULL) {
           tail = curr1;
       }


       cout << "\"" << currentSong << "\" moved to position " << newPos << endl;
       return true;

   }
   else {
       cout << "Song's current position is invalid" << endl;
       return false;
   }
}

void Playlist::SongsByArtist(string artist) {
   if (head == NULL) {
       cout << "Playlist is empty" << endl;
   }
   else {
       PlaylistNode* curr = head;
       int i = 1;
       while (curr != NULL) {
           if (curr->GetArtistName() == artist) {
               cout << endl << i << "." << endl;
               curr->PrintPlaylistNode();              
           }
           curr = curr->GetNext();
           i++;
       }
   }
}

int Playlist::totalTime() {
   int total = 0;
   PlaylistNode* curr = head;

   while (curr != NULL) {
       total += curr->GetSongLength();
       curr = curr->GetNext();
   }

   return total;
}


void Playlist::PrintList() {
   if (head == NULL) {
       cout << "Playlist is empty" << endl;
   }
   else {
       PlaylistNode* curr = head;
       int i = 1;
       while (curr != NULL) {
           cout << endl << i++ << "." << endl;
           curr->PrintPlaylistNode();          
           curr = curr->GetNext();
       }
   }
}
