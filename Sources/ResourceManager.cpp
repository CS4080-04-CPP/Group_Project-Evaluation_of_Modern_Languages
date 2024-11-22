#include "Main.h"

Object Floor("Resources/TempTerrain.png");
Object Floor2("Resources/Terrain.png");
Object Floor3("Resources/Terrain.png");
Object Floor4("Resources/Terrain.png");
Object Floor5("Resources/Terrain.png");
Object Floor6("Resources/Terrain.png");
Object Sky("Resources/Sky.png");
Object Sky2("Resources/Sky2.png");
Object LeftWall("Resources/Wall.png");
Object RightWall("Resources/Wall.png");
Object cloud1("Resources/cloud1.png");
Object cursorSprite("Resources/cursor.png");

Object JacobForward("Resources/Jacob.png");
Object JacobLeft("Resources/Jacob_left.png");
Object JacobRight("Resources/Jacob_right.png");

Object MichelleForward("Resources/Michelle.png");
Object MichelleLeft("Resources/Michelle_Left.png");
Object MichelleRight("Resources/Michelle_Right.png");

Object characterSelectBoxLeftInActive("Resources/characterSelectBoxInActive.png");
Object characterSelectBoxRightInActive("Resources/characterSelectBoxInActive.png");


sf::SoundBuffer walkingBuffer;
sf::SoundBuffer landingBuffer;
sf::SoundBuffer jumpingBuffer;
sf::Sound walkingSound;
sf::Sound landingSound;
sf::Sound jumpingSound;


void SFMLApp::loadResources()
{

    // Load sound buffers (call this once, typically at initialization)
    if (!walkingBuffer.loadFromFile("Resources/Walking.mp3")) {
        std::cerr << "Failed to load walking sound!" << std::endl;
    }
    if (!landingBuffer.loadFromFile("Resources/Landing.mp3")) {
        std::cerr << "Failed to load landing sound!" << std::endl;
    }
    if (!jumpingBuffer.loadFromFile("Resources/Jumping.mp3")) {
        std::cerr << "Failed to load jumping sound!" << std::endl;
    }

    // Set the buffers for the sounds
    walkingSound.setBuffer(walkingBuffer);
    landingSound.setBuffer(landingBuffer);
    jumpingSound.setBuffer(jumpingBuffer);

    LeftWall.setPosition(-60, 0);
    RightWall.setPosition(1920, 0);

    Floor.setPosition(0, 1010);
    Floor2.setPosition(1450, 750);
    Floor3.setPosition(1050, 450);
    Floor4.setPosition(1350, 150);
    Floor5.setPosition(800, 800);
    Floor6.setPosition(400, 500);
    Sky.setPosition(0, 0);
    Sky2.setPosition(0, 0);

    characterSelectBoxLeftInActive.setPosition(screenWidth / 2 - 250, screenHeight / 2 - 250);
    characterSelectBoxRightInActive.setPosition(screenWidth / 2 + 50, screenHeight / 2 - 250);
    characterSelectBoxLeftInActive.setScale(2, 2);
    characterSelectBoxRightInActive.setScale(2, 2);

    JacobForward.centerOrigin();
    JacobLeft.centerOrigin();
    JacobRight.centerOrigin();

    MichelleForward.centerOrigin();
    MichelleLeft.centerOrigin();
    MichelleRight.centerOrigin();

    collidableObjectsLevelOne.push_back(LeftWall);
    collidableObjectsLevelOne.push_back(RightWall);
    collidableObjectsLevelOne.push_back(Floor);
    collidableObjectsLevelOne.push_back(Floor2);
    collidableObjectsLevelOne.push_back(Floor3);
    collidableObjectsLevelOne.push_back(Floor4);
  

    collidableObjectsLevelTwo.push_back(Floor5);
    collidableObjectsLevelTwo.push_back(Floor6);
    collidableObjectsLevelTwo.push_back(LeftWall);
    collidableObjectsLevelTwo.push_back(RightWall);

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

    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();

    // Type Conversion: Implicit type conversion between unsigned integers and floats during scaling.
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    backgroundSprite.setScale(scaleX, scaleY);
    backgroundBlurSprite.setScale(scaleX, scaleY);

    SelectbackgroundSpriteLeft.setPosition(screenWidth / 2 - 250, screenHeight / 2 - 250);
    SelectbackgroundSpriteLeft.setScale(2, 2);
    SelectbackgroundSpriteRight.setPosition(screenWidth / 2 + 50, screenHeight / 2 - 250);
    SelectbackgroundSpriteRight.setScale(2, 2);

    SelectbackgroundSpriteLeftActive.setPosition(screenWidth / 2 - 250, screenHeight / 2 - 250);
    SelectbackgroundSpriteLeftActive.setScale(2, 2);
    SelectbackgroundSpriteRightActive.setPosition(screenWidth / 2 + 50, screenHeight / 2 - 250);
    SelectbackgroundSpriteRightActive.setScale(2, 2);


}

