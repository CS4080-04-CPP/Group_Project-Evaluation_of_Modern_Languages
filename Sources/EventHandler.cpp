#include "Main.h"

bool Socket_Enabled;

// Handle events based on the current state
void SFMLApp::handleStateEvents(const sf::Event& event)
{
    switch (currentState)
    {

    case State::MAIN_MENU:

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            mainMenuState = true;
            Socket_Enabled = false;


        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {

            // Check if the mouse is over the text
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
        if (Socket_Enabled == true && event.type == sf::Event::MouseButtonPressed)
        {
            // Check if the mouse is over the "Connect"
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
        else if (mainMenuState == false && event.type == sf::Event::MouseButtonPressed && Socket_Enabled == false)
        {

            // TODO: Begin GAME on Local
        }
        break;
    case State::LEVEL_SELECT:
        // Handle level selection events...
        break;
    case State::PLAYING:
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            currentState = State::LEVEL_SELECT;
        }
        break;
    }
}

// Event handling function
void SFMLApp::processEvents()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Resized)
        {
            resizeBackground();
        }

        if (event.type == sf::Event::Closed)
        {
            window.close();
            isRunning = false;
        }

        handleStateEvents(event);
    }
}
