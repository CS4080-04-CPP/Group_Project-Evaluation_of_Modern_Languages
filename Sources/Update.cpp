#include "Main.h"


// Update logic
void SFMLApp::update(sf::Window& window)
{

    // Handle input while playing
    if (currentState != State::MAIN_MENU && currentState != State::LEVEL_SELECT)
    {

        inputManager.processInput(window);
    }

}