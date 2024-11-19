#include "Main.h"
#include "Character.h"


// Function to handle main menu events (buttons and where they are pixel wise)
void SFMLApp::handleMainMenuEvents(sf::Event event)
{
    
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        // Co-Op, buttons, detaches a thread to run independely of the program based on who's client and who's host.

        if (Socket_Enabled && mousePos.x >= 1571 && mousePos.x <= 1690 && mousePos.y >= 255 && mousePos.y <= 300)
        {

            std::thread hostThread(hostGameLogic, std::ref(*clientCharacter), std::ref(*hostCharacter));
            hostThread.detach();
        }

        if (Socket_Enabled && mousePos.x >= 1567 && mousePos.x <= 1759 && mousePos.y >= 332 && mousePos.y <= 387)
        {

            std::thread clientThread(connectGameLogic, std::ref(*hostCharacter), std::ref(*clientCharacter));
            clientThread.detach();           
            Host = false;
        }

        // Main menu buttons, single player, co-op, and exit.

        if (mainMenuState)
        {

            if (mousePos.x >= 1578 && mousePos.x <= 1789 && mousePos.y >= 260 && mousePos.y <= 293)
            {

                mainMenuState = false;
            }

            if (mousePos.x >= 1612 && mousePos.x <= 1719 && mousePos.y >= 315 && mousePos.y <= 357)
            {

                Socket_Enabled = true;
                mainMenuState = false;
            }

            if (mousePos.x >= 1611 && mousePos.x <= 1696 && mousePos.y >= 375 && mousePos.y <= 411)
            {

                isRunning = false;
            }
        }
        else if (!Socket_Enabled || Connected)
        {

            // Character selection logic
            if (mousePos.x >= 717 && mousePos.x <= 959 && mousePos.y >= 308 && mousePos.y <= 578)
            {
               
                if (Connected == false) // Single-player or no connection
                {

                    initializeCharacter(hostCharacter, "Character A", sf::Vector2f(100.f, 800.f), 1);
                    currentState = State::LEVEL_ONE;
                }
                else if (Host) // Host player creates character A
                {

                    initializeCharacter(hostCharacter, "Character A", sf::Vector2f(100.f, 800.f), 1);
                    currentState = State::LEVEL_ONE;             
                }
                else // Client player creates character A
                {

                    initializeCharacter(clientCharacter, "Character A", sf::Vector2f(300.f, 800.f), 1);
                    currentState = State::LEVEL_ONE;
                }

                mainMenuState = true;
            }
            // Character B selection logic
            else if (mousePos.x >= 1019 && mousePos.x <= 1257 && mousePos.y >= 303 && mousePos.y <= 577)
            {                

                if (Connected == false) // Single-player or no connection
                {

                    initializeCharacter(hostCharacter, "Character B", sf::Vector2f(100.f, 800.f), 2);
                    currentState = State::LEVEL_ONE;
                }
                else if (Host) // Host player creates character B
                {
                    
                    initializeCharacter(hostCharacter, "Character B", sf::Vector2f(100.f, 800.f), 2);
                    currentState = State::LEVEL_ONE;
                }
                else // Client player creates character B
                {
                    
                    initializeCharacter(clientCharacter, "Character B", sf::Vector2f(300.f, 800.f), 2);
                    currentState = State::LEVEL_ONE;
                }

                mainMenuState = true;
            }
        }
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        mainMenuState = true;
        Socket_Enabled = false;
    }
}