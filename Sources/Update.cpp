#include "Main.h"

// Update logic
void SFMLApp::update()
{
    // Update logic based on current state
    switch (currentState)
    {
    case State::MAIN_MENU:
        // No specific update logic needed for the main menu
        break;
    case State::LEVEL_SELECT:
        // Update level select logic if necessary
        break;
    case State::PLAYING:
        // Update game logic here
        break;
    }
}