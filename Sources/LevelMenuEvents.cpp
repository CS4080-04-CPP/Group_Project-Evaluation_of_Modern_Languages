#include "Main.h"

// Handle LEVEL_Menu state events
void SFMLApp::handleLevelSelectEvents(sf::Event event, State state)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {

        currentState = state;
    }
    
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (mousePos.x >= 1564 && mousePos.x <= 1771 && mousePos.y >= 242 && mousePos.y <= 292)
        {

            currentState = state;
        }

        if (mousePos.x >= 1564 && mousePos.x <= 1685 && mousePos.y >= 306 && mousePos.y <= 361)
        {
            sf::Vector2f temp = { 100.0f, 800.0f };
            sf::Vector2f temp2 = { 300.0f, 800.0f };
            Socket_Enabled = false;
            Connected = false;
            mainMenuState = true;
            hostCharacter->setCharacterType(0);
            clientCharacter->setCharacterType(0);
            hostCharacter->setPosition(temp);
            clientCharacter->setPosition(temp2);
            currentState = State::MAIN_MENU;
        }
    }
}