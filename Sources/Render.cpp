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
    case State::PLAYING:
        renderGame();
        break;
    }

    if (StateChange == 1)
    {
        currentState = State::LEVEL_SELECT;
    }
    else if (StateChange == 2)
    {
        currentState = State::PLAYING;
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


// Render the main menu
void SFMLApp::renderMainMenu()
{
    window.draw(mainMenuState ? backgroundSprite : backgroundBlurSprite);
    
    renderMainMenus(window, mainMenuState, SelectbackgroundSpriteLeft, SelectbackgroundSpriteRight, SelectbackgroundSpriteLeftActive, SelectbackgroundSpriteRightActive);
}

// Render the level select screen
void SFMLApp::renderLevelMenu()
{
    window.draw(backgroundBlurSprite);
    renderLevelMenus(window);
}

// Render the game
void SFMLApp::renderGame()
{
    renderLevel_One(window);
}