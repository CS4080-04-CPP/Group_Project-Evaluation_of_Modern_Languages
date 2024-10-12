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
    renderMainMenus(window, mainMenuState);
}

// Render the level select screen
void SFMLApp::renderLevelMenu()
{
    renderLevelMenus(window);
}

// Render the game (placeholder for gameplay rendering)
void SFMLApp::renderGame()
{
    renderLevel_One(window);
}