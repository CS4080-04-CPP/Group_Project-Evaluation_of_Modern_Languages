#include "Main.h"

void moveMents(Character& character)
{
    // Handle keyboard input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // Move up
    {
        character.move(0.f, -10.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // Move down
    {
        character.move(0.f, 10.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // Move left
    {
        character.move(-10.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Move right
    {
        character.move(10.f, 0.f);
    }
}

// Handle PLAYING state events
void handlePlayingEvents(sf::RenderWindow& window)
{
    if (Host)
        moveMents(*hostCharacter);
    else
        moveMents(*clientCharacter);

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        mainMenuState = true;
        Socket_Enabled = false;
    }
}
