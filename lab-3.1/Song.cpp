#include "Song.h"

Song::Song(const std::string& t, const std::string& a, int d, const std::string& path)
	: title(t), artist(a), duration(d), filePath(path) {}

bool Song::operator<(const Song& other) const {
	return title < other.title;  // Sort by title alphabetically
}
