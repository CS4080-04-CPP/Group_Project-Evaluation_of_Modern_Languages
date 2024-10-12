#include "Main.h"

// Handle MAIN_MENU state events
void handleMainMenuEvents(sf::RenderWindow& window, const sf::Event& event, bool& mainMenuState, bool& Socket_Enabled, bool& isRunning)
{

    if (Socket_Enabled == true && event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (mousePos.x >= 1571 && mousePos.x <= 1690 && mousePos.y >= 255 && mousePos.y <= 300)
            {
                hostGameLogic();
            }

            if (mousePos.x >= 1567 && mousePos.x <= 1759 && mousePos.y >= 332 && mousePos.y <= 387)
            {
                connectGameLogic();
            }
        }
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        mainMenuState = true;
        Socket_Enabled = false;
    }
    else if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            std::cout << "Mouse Position: (" << mousePos.x << ", " << mousePos.y << ")" << std::endl; // Debug print

            if (mainMenuState == true && mousePos.x >= 1578 && mousePos.x <= 1789 && mousePos.y >= 260 && mousePos.y <= 293)
            {
                mainMenuState = false;
            }

            if (mainMenuState == true && mousePos.x >= 1612 && mousePos.x <= 1719 && mousePos.y >= 315 && mousePos.y <= 357)
            {
                Socket_Enabled = true;
                mainMenuState = false;
                
            }

            if (mainMenuState == true && mousePos.x >= 1611 && mousePos.x <= 1696 && mousePos.y >= 375 && mousePos.y <= 410)
            {
                isRunning = false;
            }
        }
    }

    else if (mainMenuState == false && event.type == sf::Event::MouseButtonPressed && Socket_Enabled == false)
    {
        // TODO: Begin GAME without socket
    }
}
