#include <catch2/catch_test_macros.hpp>

#include "Playlist.h"
#include "SortedArrayPlaylist.h"
#include "SortedLinkedPlaylist.h"

Song song(const std::string &title)
{
    return Song(title, "Artist", 180, title + ".mp3");
}

TEST_CASE("Playlist adds and navigates songs")
{
    Playlist playlist;
    playlist.addSong(song("First"));
    playlist.addSong(song("Second"));

    REQUIRE(playlist.getLength() == 2);
    REQUIRE(playlist.getCurrentSong()->title == "Second");

    playlist.nextSong();
    REQUIRE(playlist.getCurrentSong()->title == "First");

    playlist.previousSong();
    REQUIRE(playlist.getCurrentSong()->title == "Second");
}

TEST_CASE("Playlist removes a song by title")
{
    Playlist playlist;
    playlist.addSong(song("First"));
    playlist.addSong(song("Second"));

    playlist.removeSong("Second");

    REQUIRE(playlist.getLength() == 1);
    REQUIRE(playlist.getCurrentSong()->title == "First");
}

TEST_CASE("Playlist sorts songs by title")
{
    Playlist playlist;
    playlist.addSong(song("Charlie"));
    playlist.addSong(song("Alpha"));
    playlist.addSong(song("Bravo"));
    playlist.sortByTitle();

    std::vector<Song> songs = playlist.getSongs();
    REQUIRE(songs[0].title == "Alpha");
    REQUIRE(songs[1].title == "Bravo");
    REQUIRE(songs[2].title == "Charlie");
}

TEST_CASE("Playlist merges two sorted playlists")
{
    Playlist first;
    Playlist second;
    first.addSong(song("Bravo"));
    first.addSong(song("Alpha"));
    second.addSong(song("Delta"));
    second.addSong(song("Charlie"));
    first.sortByTitle();
    second.sortByTitle();

    first.mergeSortedPlaylists(second);
    std::vector<Song> songs = first.getSongs();

    REQUIRE(first.getLength() == 4);
    REQUIRE(songs[0].title == "Alpha");
    REQUIRE(songs[1].title == "Bravo");
    REQUIRE(songs[2].title == "Charlie");
    REQUIRE(songs[3].title == "Delta");
}

TEST_CASE("Playlist merges an unsorted playlist and sorts the result")
{
    Playlist sorted;
    Playlist unsorted;
    sorted.addSong(song("Alpha"));
    unsorted.addSong(song("Charlie"));
    unsorted.addSong(song("Bravo"));

    sorted.mergeWithUnsorted(unsorted);
    std::vector<Song> songs = sorted.getSongs();

    REQUIRE(sorted.getLength() == 3);
    REQUIRE(songs[0].title == "Alpha");
    REQUIRE(songs[1].title == "Bravo");
    REQUIRE(songs[2].title == "Charlie");
}

TEST_CASE("Playlist searches and exports songs")
{
    Playlist playlist;
    playlist.addSong(Song("Blue", "Artist One", 180, "blue.mp3"));
    playlist.addSong(Song("Red", "Artist Two", 200, "red.mp3"));

    REQUIRE(playlist.search("Artist One").size() == 1);
    REQUIRE(playlist.search("Red").size() == 1);
    REQUIRE(playlist.exportJson("playlist_test.json"));
}

TEST_CASE("Sorted playlist variants keep songs ordered")
{
    SortedLinkedPlaylist linked;
    SortedArrayPlaylist array;
    linked.addSong(song("Charlie"));
    linked.addSong(song("Alpha"));
    array.addSong(song("Charlie"));
    array.addSong(song("Alpha"));

    REQUIRE(linked.getSongs()[0].title == "Alpha");
    REQUIRE(array.getSongs()[0].title == "Alpha");
}
