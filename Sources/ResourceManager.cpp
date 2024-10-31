#include "Main.h"

sf::Texture cursorTexture;
sf::Sprite cursorSprite;

sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;

sf::Texture backgroundBlurTexture;
sf::Sprite backgroundBlurSprite;

sf::Texture SelectbackgroundTexture;
sf::Sprite SelectbackgroundSpriteLeft;
sf::Sprite SelectbackgroundSpriteRight;

sf::Texture SelectbackgroundTextureActive;
sf::Sprite SelectbackgroundSpriteLeftActive;
sf::Sprite SelectbackgroundSpriteRightActive;

sf::Sprite tempPlayerASprite;
sf::Sprite tempPlayerBSprite;
sf::Texture tempPlayerATexture;
sf::Sprite tempPlayerASprite2;
sf::Texture tempPlayerBTexture;
sf::Sprite tempPlayerBSprite2;

sf::Text singlePlayer;
sf::Text coOp;
sf::Text Exitw;

void loadResources(sf::RenderWindow& window)
{
    // Load the cursor texture
    if (!cursorTexture.loadFromFile("Resources/cursor.png"))
    {
        std::cerr << "Error: Could not load cursor texture." << std::endl;
    }

    // Types: Demonstrates object-oriented manipulation of types like sf::Sprite and sf::Texture.
    cursorSprite.setTexture(cursorTexture);
    cursorSprite.setOrigin(cursorTexture.getSize().x / 2.f, cursorTexture.getSize().y / 2.f); // Set origin to center

    // Load the background texture
    if (!backgroundTexture.loadFromFile("Resources/background.png"))
    {
        std::cerr << "Error: Could not load background texture." << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);

    // Load temp PlayerA texture
    if (!tempPlayerATexture.loadFromFile("Resources/CharacterA_Temp.png"))
    {
        std::cerr << "Error: Could not load background texture." << std::endl;
    }

    tempPlayerASprite.setTexture(tempPlayerATexture);
    tempPlayerASprite2.setTexture(tempPlayerATexture);

    // Load temp PlayerB texture
    if (!tempPlayerBTexture.loadFromFile("Resources/CharacterB_Temp.png"))
    {
        std::cerr << "Error: Could not load background texture." << std::endl;
    }

    tempPlayerBSprite.setTexture(tempPlayerBTexture);
    tempPlayerBSprite2.setTexture(tempPlayerBTexture);


    // Load the background_blur texture
    if (!backgroundBlurTexture.loadFromFile("Resources/background_blur.png"))
    {
        std::cerr << "Error: Could not load background texture." << std::endl;
    }

    backgroundBlurSprite.setTexture(backgroundBlurTexture);

    // Load the background texture
    if (!SelectbackgroundTexture.loadFromFile("Resources/characterSelectBox.png"))
    {
        std::cerr << "Error: Could not load background texture." << std::endl;
    }

    SelectbackgroundSpriteLeft.setTexture(SelectbackgroundTexture);
    SelectbackgroundSpriteRight.setTexture(SelectbackgroundTexture);

    // Load the background texture
    if (!SelectbackgroundTextureActive.loadFromFile("Resources/characterSelectBoxActive.png"))
    {
        std::cerr << "Error: Could not load background texture." << std::endl;
    }

    SelectbackgroundSpriteLeftActive.setTexture(SelectbackgroundTextureActive);
    SelectbackgroundSpriteRightActive.setTexture(SelectbackgroundTextureActive);

    // Resize the background to fit the window
    resizeBackground(window);
}

void resizeBackground(sf::RenderWindow& window)
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();

    // Type Conversion: Implicit type conversion between unsigned integers and floats during scaling.
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    backgroundSprite.setScale(scaleX, scaleY);
    backgroundBlurSprite.setScale(scaleX, scaleY);

    SelectbackgroundSpriteLeft.setPosition(screenWidth / 2 - 250, screenHeight / 2 - 250);
    SelectbackgroundSpriteLeft.setScale(2,2);
    SelectbackgroundSpriteRight.setPosition(screenWidth / 2 + 50, screenHeight / 2 - 250);
    SelectbackgroundSpriteRight.setScale(2, 2);

    SelectbackgroundSpriteLeftActive.setPosition(screenWidth / 2 - 250, screenHeight / 2 - 250);
    SelectbackgroundSpriteLeftActive.setScale(2, 2);
    SelectbackgroundSpriteRightActive.setPosition(screenWidth / 2 + 50, screenHeight / 2 - 250);
    SelectbackgroundSpriteRightActive.setScale(2, 2);

}