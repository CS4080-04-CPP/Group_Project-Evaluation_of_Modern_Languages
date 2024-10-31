#include "Main.h"

// Handle LEVEL_Menu state events
void handleLevelSelectEvents(sf::RenderWindow& window, const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
    {
        StateChange = 2;
    }
}