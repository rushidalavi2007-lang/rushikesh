#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Media {
protected:
    string title;
public:
    Media(string t) : title(t) {}
    virtual void play() const = 0;
    virtual void showDetails() const { cout << "Title: " << title << endl; }
    virtual ~Media() {}
};

class Audio : public Media {
public:
    Audio(string t) : Media(t) {}
    void play() const override { cout << "Playing Audio: " << title << " (mp3 format)" << endl; }
};

class Video : public Media {
public:
    Video(string t) : Media(t) {}
    void play() const override { cout << "Streaming Video: " << title << " (1080p)" << endl; }
};

int main() {
    vector<Media*> playlist;
    playlist.push_back(new Audio("Song 1"));
    playlist.push_back(new Video("Movie Trailer"));

    cout << "== Polymorphic Media Player ==" << endl;
    for (int i = 0; i < playlist.size(); i++) {
        playlist[i]->play();
        delete playlist[i];
    }
    return 0;
}
