# Simple Playlist Media Player

This project uses a linked list of `Song` objects. The playlist supports adding, removing, sorting, and moving between songs.

## Build the playlist tests

```powershell
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Catch2 and SFML 2.6.1 are downloaded by CMake when they are not already installed.

## Run the player

Put MP3 files in a folder named `music`, then run the `player` executable. The player includes play/pause, next, previous, and add-song buttons, a current-song display, a progress bar, and a playlist display.

## Complexity

| Operation | Complexity |
| --- | --- |
| Add song at the front | O(1) |
| Remove song by title | O(n) |
| Get current song | O(1) |
| Move next | O(1) |
| Move previous | O(n) because a singly linked list must be searched for the previous node |
| Sort by title | O(n^2) |
| Merge two sorted playlists | O(n + m) |
| Merge sorted and unsorted playlists | O((n + m)^2) because the combined list is sorted afterward |
| Search by title or artist | O(n) |
| Export playlist to JSON | O(n) |

The sorted linked variant inserts a song and then sorts, so insertion is O(n^2) with the simple linked-list sort. The sorted array variant inserts in order by shifting items, so insertion is O(n) and lookup by index is O(1).

## Manual testing checklist

- Start with an empty playlist.
- Load a folder containing MP3 files.
- Click play/pause.
- Click next and previous.
- Click add song.
- Confirm the current song and playlist display update.
- Capture screenshots of the player and Catch2 test output for the report.
