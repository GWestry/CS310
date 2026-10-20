#ifndef SORTED_ARRAY_PLAYLIST_H
#define SORTED_ARRAY_PLAYLIST_H

#include <vector>

#include "Song.h"

class SortedArrayPlaylist
{
private:
    std::vector<Song> songs;
    int currentIndex;

public:
    SortedArrayPlaylist() : currentIndex(0) {}

    void addSong(const Song &song);
    void removeSong(const std::string &title);
    Song *getCurrentSong();
    void nextSong();
    void previousSong();
    int getLength() const;
    std::vector<Song> getSongs() const;
};

#endif