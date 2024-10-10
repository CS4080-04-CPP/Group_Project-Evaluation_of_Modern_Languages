#include "Main.h"

bool Socket_enabled;

void renderMainMenus(sf::RenderWindow& window, bool& mainMenuState)
{
    // Load the font
    sf::Font font;
    if (!font.loadFromFile("Resources/Pacifico.ttf")) // Load a font
    {
        std::cerr << "Error: Could not load font." << std::endl;
        return; // Early exit if font loading fails
    }

    // Create text objects
    sf::Text singlePlayer("Single Player", font, 40);
    sf::Text coOp("Co-Op", font, 40);
    sf::Text exit("Exit", font, 40);
    sf::Text host("Host", font, 60);
    sf::Text connect("Connect", font, 60);

    // Set initial color to black
    singlePlayer.setFillColor(sf::Color::Black);
    coOp.setFillColor(sf::Color::Black);
    exit.setFillColor(sf::Color::Black);
    host.setFillColor(sf::Color::Black);
    connect.setFillColor(sf::Color::Black);

    // Set positions
    singlePlayer.setPosition(screenWidth / 2 + 600, screenHeight / 2 - 300); // Center text
    coOp.setPosition(screenWidth / 2 + 650, screenHeight / 2 - 240); // Center text
    exit.setPosition(screenWidth / 2 + 650, screenHeight / 2 - 180); // Center text
    host.setPosition(screenWidth / 2 + 600, screenHeight / 2 - 300); // Center text
    connect.setPosition(screenWidth / 2 + 600, screenHeight / 2 - 220); // Center text

    // Get the current mouse position relative to the window
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    // Change color if mouse is hovering over the text
    if (singlePlayer.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        singlePlayer.setFillColor(sf::Color::Red); // Change to red
    }

    if (coOp.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        coOp.setFillColor(sf::Color::Red); // Change to red
    }

    if (exit.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        exit.setFillColor(sf::Color::Red); // Change to red
    }

    if (host.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        host.setFillColor(sf::Color::Red); // Change to red
    }

    if (connect.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        connect.setFillColor(sf::Color::Red); // Change to red
    }

    // Draw the texts
    if (mainMenuState)
    {

        window.draw(singlePlayer);
        window.draw(coOp);
        window.draw(exit);
    }
    else
    {

        if (Socket_Enabled == true)
        {

            window.draw(host);
            window.draw(connect);
        }
    }
}