#include "Main.h"


// Handle PLAYING state events
void handlePlayingEvents(sf::RenderWindow& window, const sf::Event& event)
{   

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        StateChange = 1;
    }
}
