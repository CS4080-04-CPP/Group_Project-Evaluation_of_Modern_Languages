#include "Main.h"

void SFMLApp::render()
{
    window.clear();

    // Render the current state
    switch (currentState)
    {
    case State::MAIN_MENU:

        renderMainMenu();

        break;
    case State::LEVEL_SELECT:

        renderLevelMenu();

        break;
    case State::LEVEL_ONE:

        renderLevelOne();

        break;
    case State::LEVEL_TWO:

        renderLevelTwo();

        break;
    }

    if (currentState == State::MAIN_MENU || currentState == State::LEVEL_SELECT)
    {
        
        // Draw cursor
        sf::Vector2i localMousePos = sf::Mouse::getPosition(window);
        float scaledMouseX = static_cast<float>(localMousePos.x);
        float scaledMouseY = static_cast<float>(localMousePos.y);
        cursorSprite.setPosition(scaledMouseX, scaledMouseY);
        cursorSprite.draw(window);
    }

    window.display();
}
