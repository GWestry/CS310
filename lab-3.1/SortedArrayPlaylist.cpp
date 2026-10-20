#include "SortedArrayPlaylist.h"

void SortedArrayPlaylist::addSong(const Song &song)
{
    songs.push_back(song);
    int index = static_cast<int>(songs.size()) - 1;

    while (index > 0 && songs[index].title < songs[index - 1].title)
    {
        Song temp = songs[index];
        songs[index] = songs[index - 1];
        songs[index - 1] = temp;
        index--;
    }
}

void SortedArrayPlaylist::removeSong(const std::string &title)
{
    for (int index = 0; index < static_cast<int>(songs.size()); index++)
    {
        if (songs[index].title == title)
        {
            songs.erase(songs.begin() + index);
            if (currentIndex >= static_cast<int>(songs.size()))
                currentIndex = 0;
            return;
        }
    }
}

Song *SortedArrayPlaylist::getCurrentSong()
{
    if (songs.empty())
        return nullptr;
    return &songs[currentIndex];
}

void SortedArrayPlaylist::nextSong()
{
    if (!songs.empty() && currentIndex < static_cast<int>(songs.size()) - 1)
        currentIndex++;
}

void SortedArrayPlaylist::previousSong()
{
    if (currentIndex > 0)
        currentIndex--;
}

int SortedArrayPlaylist::getLength() const
{
    return static_cast<int>(songs.size());
}

std::vector<Song> SortedArrayPlaylist::getSongs() const
{
    return songs;
}