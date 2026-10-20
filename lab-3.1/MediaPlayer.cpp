#include "MediaPlayer.h"

#include <filesystem>

MediaPlayer::MediaPlayer()
    : window(sf::VideoMode(800, 600), "Simple Playlist Player"),
      currentIndex(0), isPlaying(false)
{
    font.loadFromFile("arial.ttf");

    currentSongText.setFont(font);
    currentSongText.setCharacterSize(24);
    currentSongText.setPosition(20, 20);
    currentSongText.setFillColor(sf::Color::White);

    playButton.setSize(sf::Vector2f(120, 45));
    playButton.setPosition(20, 100);
    nextButton.setSize(sf::Vector2f(120, 45));
    nextButton.setPosition(160, 100);
    previousButton.setSize(sf::Vector2f(120, 45));
    previousButton.setPosition(300, 100);
    addButton.setSize(sf::Vector2f(120, 45));
    addButton.setPosition(440, 100);
    progressBar.setSize(sf::Vector2f(540, 12));
    progressBar.setPosition(20, 175);

    playLabel.setFont(font);
    playLabel.setString("Play/Pause");
    playLabel.setCharacterSize(16);
    playLabel.setPosition(30, 112);
    nextLabel.setFont(font);
    nextLabel.setString("Next");
    nextLabel.setCharacterSize(16);
    nextLabel.setPosition(195, 112);
    previousLabel.setFont(font);
    previousLabel.setString("Previous");
    previousLabel.setCharacterSize(16);
    previousLabel.setPosition(320, 112);
    addLabel.setFont(font);
    addLabel.setString("Add Song");
    addLabel.setCharacterSize(16);
    addLabel.setPosition(465, 112);
}

void MediaPlayer::run()
{
    while (window.isOpen())
    {
        handleEvents();
        update();
        render();
    }
}

void MediaPlayer::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2f position = window.mapPixelToCoords(
                sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

            if (playButton.getGlobalBounds().contains(position))
            {
                if (isPlaying)
                    music.pause();
                else
                    music.play();
                isPlaying = !isPlaying;
            }
            else if (nextButton.getGlobalBounds().contains(position))
                next();
            else if (previousButton.getGlobalBounds().contains(position))
                previous();
            else if (addButton.getGlobalBounds().contains(position))
                playlist.addSong(Song("Added Song", "Student", 0, ""));
        }
    }
}

void MediaPlayer::update()
{
    Song *song = playlist.getCurrentSong();
    if (song == nullptr)
    {
        currentSongText.setString("No song loaded");
        return;
    }

    currentSongText.setString(song->title + " - " + song->artist);

    if (song->filePath != loadedPath && !song->filePath.empty())
    {
        if (music.openFromFile(song->filePath))
        {
            loadedPath = song->filePath;
            if (isPlaying)
                music.play();
        }
    }

    if (music.getStatus() == sf::SoundSource::Stopped && isPlaying)
        next();

    if (music.getDuration().asSeconds() > 0)
    {
        float progress = music.getPlayingOffset().asSeconds() /
                         music.getDuration().asSeconds();
        progressBar.setSize(sf::Vector2f(540 * progress, 12));
    }
}

void MediaPlayer::render()
{
    window.clear(sf::Color(35, 35, 40));

    playButton.setFillColor(sf::Color(70, 130, 180));
    nextButton.setFillColor(sf::Color(70, 130, 180));
    previousButton.setFillColor(sf::Color(70, 130, 180));
    addButton.setFillColor(sf::Color(70, 130, 180));
    progressBar.setFillColor(sf::Color(90, 190, 90));

    window.draw(currentSongText);
    window.draw(playButton);
    window.draw(nextButton);
    window.draw(previousButton);
    window.draw(addButton);
    window.draw(progressBar);
    window.draw(playLabel);
    window.draw(nextLabel);
    window.draw(previousLabel);
    window.draw(addLabel);

    std::vector<Song> songs = playlist.getSongs();
    int y = 230;
    for (const Song &song : songs)
    {
        sf::Text songText(song.title, font, 18);
        songText.setPosition(20, static_cast<float>(y));
        window.draw(songText);
        y += 28;
    }

    window.display();
}

void MediaPlayer::next()
{
    playlist.nextSong();
    isPlaying = false;
    loadedPath.clear();
}

void MediaPlayer::previous()
{
    playlist.previousSong();
    isPlaying = false;
    loadedPath.clear();
}

void MediaPlayer::loadPlaylist(const std::string &directory)
{
    if (!std::filesystem::exists(directory))
        return;

    for (const auto &entry : std::filesystem::directory_iterator(directory))
    {
        if (entry.path().extension() == ".mp3")
        {
            playlist.addSong(Song(entry.path().stem().string(),
                                  "Unknown Artist", 0, entry.path().string()));
        }
    }
}