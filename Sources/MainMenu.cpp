#include "MainMenu.h"


// Initialize the window
void SFMLApp::initWindow()
{
    // Create an 800x600 window with the title "SFML Application"
    window.create(sf::VideoMode(800, 600), "SFML Application");
}

// Main game loop
void SFMLApp::run()
{
    while (isRunning && window.isOpen())
    {
        processEvents();  // Handle input
        update();         // Update game state
        render();         // Draw everything to the window
    }
}

void SFMLApp::render()
{

    window.clear();
    window.display();
}

// Process all window events (input handling)
void SFMLApp::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Close window or press escape key to exit
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
            window.close();
            isRunning = false;
        }
    }
}

void SFMLApp::update()
{

}

SFMLApp::SFMLApp()
{

    initWindow();
    isRunning = true;
}

SFMLApp::~SFMLApp(){}