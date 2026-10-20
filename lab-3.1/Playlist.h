#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <vector>
#include "Song.h"
#include "UnsortedLinkedList.h"

class Playlist : public UnsortedLinkedList<Song>
{
public:
    void addSong(const Song &song);
    void removeSong(const std::string &title);
    Song *getCurrentSong();
    void nextSong();
    void previousSong();
    void sortByTitle();
    void mergeSortedPlaylists(const Playlist &other);
    void mergeWithUnsorted(const Playlist &unsorted);
    int getLength() const;
    std::vector<Song> getSongs() const;
    std::vector<Song> search(const std::string &text) const;
    bool exportJson(const std::string &fileName) const;
};

#endif
