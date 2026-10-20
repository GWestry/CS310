#ifndef SORTED_LINKED_PLAYLIST_H
#define SORTED_LINKED_PLAYLIST_H

#include "Playlist.h"

class SortedLinkedPlaylist : public Playlist
{
public:
    void addSong(const Song &song)
    {
        Playlist::addSong(song);
        sortByTitle();
    }
};

#endif