#ifndef MEDIA_PLAYER_H
#define MEDIA_PLAYER_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

#include "Playlist.h"

class MediaPlayer
{
private:
    sf::RenderWindow window;
    sf::Music music;
    Playlist playlist;
    int currentIndex;
    bool isPlaying;
    std::string loadedPath;

    sf::Font font;
    sf::Text currentSongText;
    sf::RectangleShape playButton;
    sf::RectangleShape nextButton;
    sf::RectangleShape previousButton;
    sf::RectangleShape addButton;
    sf::RectangleShape progressBar;
    sf::Text playLabel;
    sf::Text nextLabel;
    sf::Text previousLabel;
    sf::Text addLabel;

public:
    MediaPlayer();
    void run();
    void handleEvents();
    void update();
    void render();
    void next();
    void previous();
    void loadPlaylist(const std::string &directory);
};

#endif