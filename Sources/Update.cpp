#include "Main.h"


// Update logic
void SFMLApp::update(sf::Window& window)
{

    // Update logic based on current state
    switch (currentState)
    {
    case State::MAIN_MENU:
        
        break;
    case State::LEVEL_SELECT:
        
        break;
    case State::LEVEL_ONE:
        inputManager.processInput(window);

    case State::LEVEL_TWO:
        inputManager.processInput(window);
        
        break;
    }
}