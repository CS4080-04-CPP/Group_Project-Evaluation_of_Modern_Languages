#include "MainMenu.h"
#include <iostream>

// Constructor
SFMLApp::SFMLApp()
{
    initWindow();
    loadResources();
    isRunning = true;
}

// Destructor
SFMLApp::~SFMLApp()
{
}

// Initialize the window
void SFMLApp::initWindow()
{

    window.create(sf::VideoMode(1920, 1080), "SFML Application");
    window.setFramerateLimit(60); 
    window.setMouseCursorVisible(false);

}

// Load the resources (textures, sprites)
void SFMLApp::loadResources()
{
    // Load the bubble texture
    if (!cursorTexture.loadFromFile("Resources/cursor.png"))
    {
        std::cerr << "Error: Could not load cursor texture." << std::endl;
        isRunning = false;
    }

    // Set up the sprite
    cursorSprite.setTexture(cursorTexture);
    cursorSprite.setOrigin(cursorTexture.getSize().x / 2.f, cursorTexture.getSize().y / 2.f); // Set origin to center

    // Load the background texture
    if (!backgroundTexture.loadFromFile("Resources/background.png"))
    {
        std::cerr << "Error: Could not load background texture." << std::endl;
        isRunning = false;
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Resize the background to fit the window
    resizeBackground();
}

// Resize the background sprite to match the window size
void SFMLApp::resizeBackground()
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();

    // Scale the background to fit the window
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    backgroundSprite.setScale(scaleX+1, scaleY+1);
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

// Rendering function
void SFMLApp::render()
{
    window.clear();

    window.draw(backgroundSprite);

    // Get the current mouse position
    sf::Vector2i localMousePos = sf::Mouse::getPosition(window);
   
    cursorSprite.setPosition(static_cast<float>(localMousePos.x), static_cast<float>(localMousePos.y));
    window.draw(cursorSprite);

    window.display();
}

// Event handling function
void SFMLApp::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Handle window resize
        if (event.type == sf::Event::Resized)
        {
            // Resize the background when the window is resized
            resizeBackground();
        }

        // Close window or press escape key to exit
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
            window.close();
            isRunning = false;
        }
    }
}

// Update logic
void SFMLApp::update()
{
    // No specific update logic needed for this version
}