#include "Main.h"

// Handle LEVEL_Menu state events
void SFMLApp::handleLevelSelectEvents(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        StateChange = 2;
    }


    
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        std::cout << "Mouse Position: (" << mousePos.x << ", " << mousePos.y << ")" << std::endl; // Debug print

        if (mousePos.x >= 1564 && mousePos.x <= 1771 && mousePos.y >= 242 && mousePos.y <= 292)
        {
            StateChange = 2;
        }
        if (mousePos.x >= 1564 && mousePos.x <= 1685 && mousePos.y >= 306 && mousePos.y <= 361)
        {
            StateChange = 0;
        }
    }
}