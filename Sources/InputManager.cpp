#include "InputManager.h"

void InputManager::processInput(sf::Window& window)
{
    // Only process input if the window is in focus
    if (!window.hasFocus())
    {
        moveLeft = false;
        moveRight = false;
        jump = false;
        return;
    }

    // Handle A key for moving left
    moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left);

    // Handle D key for moving right
    moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

    // Handle Space key for jumping
    jump = sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W);
}