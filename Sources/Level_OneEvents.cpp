#include "Main.h"


// Handle PLAYING state events
void SFMLApp::handlePlayingEvents(sf::Event event)
{   

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        StateChange = 1;
    }
}
