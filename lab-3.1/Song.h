#ifndef SONG_H
#define SONG_H
#include <string>

class Song
{
public:
    std::string title;
    std::string artist;
    int duration;         // in seconds
    std::string filePath; // path to MP3 file

    Song(const std::string &t, const std::string &a, int d, const std::string &path);
    bool operator<(const Song &other) const; // For potential sorting
};

#endif