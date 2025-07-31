#include <bits/stdc++.h>
#define ll long long
using namespace std;

/* 
    Improvements:
        1. Make class more abstract, make all data types private and use getters and setters

*/

class Song {
public:
    string song_name;
    Song* next;
    Song* prev;

    Song() : song_name(""), next(nullptr), prev(nullptr) {}
    Song(string name) : song_name(name), next(nullptr), prev(nullptr) {}
    Song(string name, Song* Next, Song* Prev) : song_name(name), next(Next), prev(Prev) {}
};

class PlayList {
public:
    Song* start;
    Song* end;

    PlayList() : start(nullptr), end(nullptr) {}

    void arr2LL(vector<string> list) {
        if(start==nullptr) start = new Song(list[0]);
        Song* mover = start;

        while(mover->next!=nullptr) mover=mover->next;

        for(int i=1; i<list.size(); i++) {
            Song* newSong = new Song(list[i]);
            mover->next = newSong;
            newSong->prev = mover;
            mover = mover->next;
        }

        end = mover;
    }

    void add_Song(string song_name) {
        Song* newSong = new Song(song_name);
        if(start==nullptr) start=newSong;
        Song* mover = start;

        while(mover->next!=nullptr) mover=mover->next;
        mover->next = newSong;
        newSong->prev = mover;
        end = newSong;
    }

    void forward_Traversal() {
        int i=1;
        Song* mover = start;
        cout<<"Your Playlist: "<<endl;
        while(mover!=nullptr) {
            cout<<i<<": "<<mover->song_name<<endl;
            mover=mover->next; i++;
        }
        cout<<endl<<endl;
    }
};

int main() {
    PlayList playlist;
    vector<string> songs = {
        "Shape of You",
        "Closer",
        "Perfect",
        "Believer",
        "Blinding Lights",
        "Let Her Go",
        "Levitating",
        "Senorita",
        "Photograph",
        "Girls Like You",
        "Faded",
        "Counting Stars",
        "Someone You Loved",
        "Stay",
        "Love Me Like You Do"
    };

    playlist.arr2LL(songs);
    playlist.forward_Traversal();
    playlist.add_Song("Daydream");
    playlist.forward_Traversal();
}
