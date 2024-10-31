#ifndef SFML_APP_H
#define SFML_APP_H

// Include necessary SFML headers
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "Character.h"
#include "InputManager.h"

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

    // Rendering function
    void render();

    // Rendering methods for different states
    void renderMainMenu();
    void renderLevelMenu();
    void renderGame();

    // Loop variables
    bool isRunning;
    bool mainMenuState;
    
};

extern bool Socket_Enabled;
extern bool Connected;
extern bool Host;
extern bool HostCharacterSelection;
extern bool ClientCharacterSelection;

extern int screenWidth;
extern int screenHeight;
extern int StateChange;

extern InputManager inputManager;
extern std::mutex characterMutex;

void  handleMainMenuEvents(sf::RenderWindow& window, const sf::Event& event, bool& mainMenuState, bool& Socket_Enabled, bool& isRunning);
void  handleLevelSelectEvents(sf::RenderWindow& window, const sf::Event& event);
void  handlePlayingEvents(sf::RenderWindow& window, const sf::Event& event);

void renderMainMenus(sf::RenderWindow& window, bool& mainMenuState, sf::Sprite& SelectbackgroundSpriteLeft, sf::Sprite& SelectbackgroundSpriteRight
    , sf::Sprite& SelectbackgroundSpriteLeftActive, sf::Sprite& SelectbackgroundSpriteRightActive);
void renderLevelMenus(sf::RenderWindow& window);
void renderLevel_One(sf::RenderWindow& window);

void loadResources(sf::RenderWindow& window);
void resizeBackground(sf::RenderWindow& window);
void moveMents();

void hostGameLogic(Character& character, Character& character2);
void connectGameLogic(Character& character, Character& character2);

// Texture and Sprites
extern sf::Texture cursorTexture;
extern sf::Sprite cursorSprite;

extern sf::Texture backgroundTexture;
extern sf::Sprite backgroundSprite;

extern sf::Texture backgroundBlurTexture;
extern sf::Sprite backgroundBlurSprite;

extern sf::Texture SelectbackgroundTexture;
extern sf::Sprite SelectbackgroundSpriteLeft;
extern sf::Sprite SelectbackgroundSpriteRight;

extern sf::Texture SelectbackgroundTextureActive;
extern sf::Sprite SelectbackgroundSpriteLeftActive;
extern sf::Sprite SelectbackgroundSpriteRightActive;


extern sf::Sprite tempPlayerASprite;
extern sf::Sprite tempPlayerBSprite;
extern sf::Texture tempPlayerATexture;
extern sf::Sprite tempPlayerASprite2;
extern sf::Texture tempPlayerBTexture;
extern sf::Sprite tempPlayerBSprite2;

extern sf::Text singlePlayer;
extern sf::Text coOp;
extern sf::Text Exitw;

#endif // SFML_APP_H