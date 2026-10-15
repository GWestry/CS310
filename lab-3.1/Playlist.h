#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include "UnsortedLinkedList.h"

class Playlist : public UnsortedLinkedList {
public:
	void addSong(const Song& song);
	void removeSong(const std::string& title);
	Song* getCurrentSong();
	void nextSong();
	void previousSong();
	void sortByTitle();
};

#endif
