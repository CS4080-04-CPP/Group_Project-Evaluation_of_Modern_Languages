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

    if (StateChange == 1)
    {
        currentState = State::LEVEL_SELECT;
    }
    else if (StateChange == 2)
    {
        currentState = State::LEVEL_ONE;
    }
    else if (StateChange == 3)
    {
        currentState = State::LEVEL_TWO;
    }
    else 
    {
        currentState = State::MAIN_MENU;
    }

    // Draw cursor
    sf::Vector2i localMousePos = sf::Mouse::getPosition(window);
    float scaledMouseX = static_cast<float>(localMousePos.x);
    float scaledMouseY = static_cast<float>(localMousePos.y);
    cursorSprite.setPosition(scaledMouseX, scaledMouseY);
    window.draw(cursorSprite);

    window.display();
}