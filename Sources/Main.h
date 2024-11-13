#ifndef SFML_APP_H
#define SFML_APP_H

// Include necessary SFML headers
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "Character.h"
#include "InputManager.h"
#include "Object.h" 

#include <iostream>
#include <string>
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
        PLAYING
    };

    // Current state of the application
    State currentState;

    // Main loop
    void run();

private:

    // Window object
    sf::RenderWindow window;    

    // Initialization function
    void initWindow();

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
    void renderGame();

    void  handleMainMenuEvents(sf::Event event);
    void  handleLevelSelectEvents(sf::Event event);
    void  handlePlayingEvents(sf::Event event);

    // Sprites and Textures
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


    // Loop variables
    bool isRunning;
    bool mainMenuState;
    
};

// Objects and Backgrounds
extern Object Floor;
extern Object Floor2;
extern Object Floor3;
extern Object Sky;
extern Object cloud1;
extern Object Background1;


extern bool Socket_Enabled;
extern bool Connected;
extern bool Host;
extern bool HostCharacterSelection;
extern bool ClientCharacterSelection;
extern bool isGrounded;

extern int screenWidth;
extern int screenHeight;
extern int StateChange;

extern InputManager inputManager;
extern std::mutex characterMutex;

void moveMents(const std::vector<Object>& collidableObjects, sf::Sprite tempPlayerASprite);

void hostGameLogic(Character& character, Character& character2);
void connectGameLogic(Character& character, Character& character2);

#endif // SFML_APP_H