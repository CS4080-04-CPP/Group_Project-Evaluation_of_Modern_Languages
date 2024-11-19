#ifndef SFML_APP_H
#define SFML_APP_H

// Include necessary SFML headers
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "Character.h"
#include "Object.h" 
#include "InputManager.h"

#include <iostream>
#include <string>
#include <sstream>

#include <thread>
#include <memory>
#include <mutex>

// Define application class
class SFMLApp
{
public:
    // Constructor and Destructor
    SFMLApp();
    ~SFMLApp();

    // Enumeration for game states
    enum class State
    {

        MAIN_MENU,
        LEVEL_SELECT,
        LEVEL_ONE,
        LEVEL_TWO
    };

    // Current state of the application
    State currentState;
    State delayedState;

    // Main loop
    void run();

private:

    // Window object
    sf::RenderWindow window;

    // Event handling function
    void processEvents();

    // Update logic
    void update(sf::Window& window);

    // Rendering functions
    void render();
    void loadResources();

    // Rendering methods for different states
    void renderMainMenu();
    void renderLevelMenu();
    void renderLevelOne();
    void renderLevelTwo();

    void UpdateAnimationsJacob(sf::Sprite);
    void UpdateAnimationsMichelle(sf::Sprite);

    void  handleMainMenuEvents(sf::Event event);
    void  handleLevelSelectEvents(sf::Event event, State state);
    void  handleLevelEvents(sf::Event event);

    // Scaleble Sprites and Textures

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

    // Loop variables
    bool isRunning;
    bool mainMenuState;

};


// Objects and Backgrounds
extern Object Floor;
extern Object Floor2;
extern Object Floor3;
extern Object Floor4;
extern Object Floor5;
extern Object Floor6;
extern Object RightWall;
extern Object LeftWall;
extern Object Sky;
extern Object Sky2;
extern Object cloud1;
extern Object cursorSprite;

extern Object JacobForward;
extern Object JacobLeft;
extern Object JacobRight;

extern Object MichelleForward;
extern Object MichelleLeft;
extern Object MichelleRight;


extern bool Socket_Enabled;
extern bool Connected;
extern bool Host;
extern bool HostCharacterSelection;
extern bool ClientCharacterSelection;
extern bool isGrounded;

extern int screenWidth;
extern int screenHeight;

extern std::vector<Object> collidableObjectsLevelOne;
extern std::vector<Object> collidableObjectsLevelTwo;

extern InputManager inputManager;
extern std::mutex characterMutex;

void moveMents(const std::vector<Object>& collidableObjects, sf::Sprite tempPlayerASprite);

void hostGameLogic(Character& character, Character& character2);
void connectGameLogic(Character& character, Character& character2);

#endif // SFML_APP_H