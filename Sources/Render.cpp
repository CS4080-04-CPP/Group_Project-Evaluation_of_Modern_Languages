#include "Main.h"

void SFMLApp::render()
{
    window.clear();

    window.draw(mainMenuState ? backgroundSprite : backgroundBlurSprite);

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


// Render the main menu
void SFMLApp::renderMainMenu()
{
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