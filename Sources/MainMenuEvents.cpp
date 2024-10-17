#include "Main.h"
#include "Character.h"

// Declare shared pointers for character objects
std::shared_ptr<Character> hostCharacter = std::make_shared<Character>("HostCharacter", sf::Vector2f(0.f, 0.f), 0);
std::shared_ptr<Character> clientCharacter = std::make_shared<Character>("ClientCharacter", sf::Vector2f(200.f, 0.f), 0);


// Function to handle main menu events
void handleMainMenuEvents(sf::RenderWindow& window, const sf::Event& event, bool& mainMenuState, bool& Socket_Enabled, bool& isRunning)
{
    

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

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

        std::cout << "Mouse Position: (" << mousePos.x << ", " << mousePos.y << ")" << std::endl; // Debug print

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

                characterSelect = 1; // Select Character A
                if (Connected == false) // Single-player or no connection
                {
                    initializeCharacter(hostCharacter, "Character A", sf::Vector2f(0.f, 0.f), 1);
                    StateChange = 2;
                }
                else if (Host) // Host player creates character A
                {
                    initializeCharacter(hostCharacter, "Character A", sf::Vector2f(0.f, 0.f), 1);  
                    if (hostCharacter) {
                        std::cout << "Character position after initialization: ("
                            << hostCharacter->getPosition().x << ", "
                            << hostCharacter->getPosition().y << ")\n";
                    }
                    StateChange = 2;
                    
                }
                else // Client player creates character A
                {
                    initializeCharacter(clientCharacter, "Character A", sf::Vector2f(200.f, 0.f), 1);
                    if (clientCharacter) {
                        std::cout << "Character position after initialization: ("
                            << clientCharacter->getPosition().x << ", "
                            << clientCharacter->getPosition().y << ")\n";
                    }
                    StateChange = 2;
                    
                }
            }
            // Character B selection logic
            else if (mousePos.x >= 1019 && mousePos.x <= 1257 && mousePos.y >= 303 && mousePos.y <= 577)
            {                

                characterSelect = 2; // Select Character B
                if (Connected == false) // Single-player or no connection
                {
                    initializeCharacter(hostCharacter, "Character B", sf::Vector2f(0.f, 0.f), 2);
                    StateChange = 2;
                }
                else if (Host) // Host player creates character B
                {
                    
                    initializeCharacter(hostCharacter, "Character B", sf::Vector2f(0.f, 0.f), 2); 
                    if (hostCharacter) {
                        std::cout << "Character position after initialization: ("
                            << hostCharacter->getPosition().x << ", "
                            << hostCharacter->getPosition().y << ")\n";
                    }
                    StateChange = 2;
                }
                else // Client player creates character B
                {
                    
                    initializeCharacter(clientCharacter, "Character B", sf::Vector2f(200.f, 0.f), 2);
                    if (clientCharacter) {
                        std::cout << "Character position after initialization: ("
                            << clientCharacter->getPosition().x << ", "
                            << clientCharacter->getPosition().y << ")\n";
                    }
                    StateChange = 2;
                }
            }
            else
            {
                characterSelect = 0; // No character selected
            }
        }
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        mainMenuState = true;
        Socket_Enabled = false;
    }
}