# Playlist Project Report Notes

## Implemented

The project contains a Song class, an unsorted linked Playlist, song navigation, title sorting, merging of two sorted playlists, and merging of a sorted playlist with an unsorted playlist. Catch2 tests cover these operations. The SFML player loads MP3 files from the `music` directory and provides playback and navigation controls. The project also includes sorted linked and sorted array playlist variants.

## Complexity discussion

The linked list can add a song at the front in O(1). Removing by title takes O(n). Moving forward takes O(1), while moving backward takes O(n) because a singly linked list does not store a previous pointer. Sorting the linked list with the simple selection-sort implementation takes O(n^2). Merging two sorted lists takes O(n + m) because each list is traversed once. Merging an unsorted list into a sorted list and sorting afterward takes O((n + m)^2) with the simple sort used here.

## Screenshots to add before submission

1. CMake build and Catch2 test output.
2. The SFML player window with the playlist visible.
3. Playback in progress with the progress bar visible.
4. Next and previous navigation.
5. Test output after changing the playlist.
