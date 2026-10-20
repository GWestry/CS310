#include "Playlist.h"

#include <fstream>

void Playlist::addSong(const Song &song)
{
    PutItem(song);
}

void Playlist::removeSong(const std::string &title)
{
    NodeType<Song> *current = head;

    while (current != nullptr)
    {
        if (current->data.title == title)
        {
            if (current == head)
            {
                head = head->next;
            }
            else
            {
                NodeType<Song> *previous = head;
                while (previous->next != current)
                    previous = previous->next;
                previous->next = current->next;
            }

            delete current;
            length--;
            currPos = nullptr;
            return;
        }
        current = current->next;
    }
}

Song *Playlist::getCurrentSong()
{
    if (currPos == nullptr)
        currPos = head;

    if (currPos == nullptr)
        return nullptr;

    return &currPos->data;
}

void Playlist::nextSong()
{
    if (currPos == nullptr)
        currPos = head;
    else if (currPos->next != nullptr)
        currPos = currPos->next;
}

void Playlist::previousSong()
{
    if (currPos == nullptr || currPos == head)
        return;

    NodeType<Song> *previous = head;
    while (previous->next != currPos)
        previous = previous->next;
    currPos = previous;
}

void Playlist::sortByTitle()
{
    NodeType<Song> *current = head;

    while (current != nullptr)
    {
        NodeType<Song> *smallest = current;
        NodeType<Song> *search = current->next;

        while (search != nullptr)
        {
            if (search->data.title < smallest->data.title)
                smallest = search;
            search = search->next;
        }

        Song temp = current->data;
        current->data = smallest->data;
        smallest->data = temp;
        current = current->next;
    }
}

void Playlist::mergeSortedPlaylists(const Playlist &other)
{
    NodeType<Song> *left = head;
    NodeType<Song> *right = other.head;
    NodeType<Song> *newHead = nullptr;
    NodeType<Song> *newTail = nullptr;
    int newLength = 0;

    while (left != nullptr || right != nullptr)
    {
        Song song("", "", 0, "");

        if (right == nullptr || (left != nullptr && left->data.title <= right->data.title))
        {
            song = left->data;
            left = left->next;
        }
        else
        {
            song = right->data;
            right = right->next;
        }

        NodeType<Song> *newNode = new NodeType<Song>(song);
        if (newHead == nullptr)
            newHead = newTail = newNode;
        else
        {
            newTail->next = newNode;
            newTail = newNode;
        }
        newLength++;
    }

    while (head != nullptr)
    {
        NodeType<Song> *temp = head;
        head = head->next;
        delete temp;
    }

    head = newHead;
    length = newLength;
    currPos = nullptr;
}

void Playlist::mergeWithUnsorted(const Playlist &unsorted)
{
    NodeType<Song> *current = unsorted.head;

    while (current != nullptr)
    {
        PutItem(current->data);
        current = current->next;
    }

    sortByTitle();
}

int Playlist::getLength() const
{
    return Length();
}

std::vector<Song> Playlist::getSongs() const
{
    std::vector<Song> songs;
    NodeType<Song> *current = head;

    while (current != nullptr)
    {
        songs.push_back(current->data);
        current = current->next;
    }

    return songs;
}

std::vector<Song> Playlist::search(const std::string &text) const
{
    std::vector<Song> matches;
    NodeType<Song> *current = head;

    while (current != nullptr)
    {
        if (current->data.title.find(text) != std::string::npos ||
            current->data.artist.find(text) != std::string::npos)
        {
            matches.push_back(current->data);
        }
        current = current->next;
    }

    return matches;
}

bool Playlist::exportJson(const std::string &fileName) const
{
    std::ofstream output(fileName);
    if (!output)
        return false;

    output << "[\n";
    NodeType<Song> *current = head;
    while (current != nullptr)
    {
        output << "  {\"title\": \"" << current->data.title
               << "\", \"artist\": \"" << current->data.artist
               << "\", \"duration\": " << current->data.duration
               << ", \"filePath\": \"" << current->data.filePath << "\"}";
        if (current->next != nullptr)
            output << ",";
        output << "\n";
        current = current->next;
    }
    output << "]\n";
    return true;
}