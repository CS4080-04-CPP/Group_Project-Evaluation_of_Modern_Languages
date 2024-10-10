#include "Main.h"

void SFMLApp::loadResources()
{
    // Load the cursor texture
    if (!cursorTexture.loadFromFile("Resources/cursor.png"))
    {
        std::cerr << "Error: Could not load cursor texture." << std::endl;
        isRunning = false;
    }

    // Types: Demonstrates object-oriented manipulation of types like sf::Sprite and sf::Texture.
    cursorSprite.setTexture(cursorTexture);
    cursorSprite.setOrigin(cursorTexture.getSize().x / 2.f, cursorTexture.getSize().y / 2.f); // Set origin to center

    // Load the background texture
    if (!backgroundTexture.loadFromFile("Resources/background.png"))
    {
        std::cerr << "Error: Could not load background texture." << std::endl;
        isRunning = false;
    }

    backgroundSprite.setTexture(backgroundTexture);

    // Load the background_blur texture
    if (!backgroundBlurTexture.loadFromFile("Resources/background_blur.png"))
    {
        std::cerr << "Error: Could not load background texture." << std::endl;
        isRunning = false;
    }

    backgroundBlurSprite.setTexture(backgroundBlurTexture);

    // Resize the background to fit the window
    resizeBackground();
}

void SFMLApp::resizeBackground()
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();

    // Type Conversion: Implicit type conversion between unsigned integers and floats during scaling.
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    backgroundSprite.setScale(scaleX, scaleY);
    backgroundBlurSprite.setScale(scaleX, scaleY);

}