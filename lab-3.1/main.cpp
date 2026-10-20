#include "MediaPlayer.h"

int main()
{
    MediaPlayer player;
    player.loadPlaylist("music");
    player.run();
    return 0;
}