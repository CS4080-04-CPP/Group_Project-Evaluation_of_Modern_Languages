#ifndef SFML_APP_H
#define SFML_APP_H

// Include necessary SFML headers
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "Character.h"

#include <iostream>
#include <string>
#include <memory>
#include <mutex>

extern bool Socket_Enabled;
extern bool Connected;
extern bool Host;

extern bool HostCharacterSelection;
extern bool ClientCharacterSelection;

extern std::mutex characterMutex;


void renderMainMenus(sf::RenderWindow& window, bool& mainMenuState, sf::Sprite& SelectbackgroundSpriteLeft, sf::Sprite& SelectbackgroundSpriteRight
                    ,sf::Sprite& SelectbackgroundSpriteLeftActive, sf::Sprite& SelectbackgroundSpriteRightActive);
void renderLevelMenus(sf::RenderWindow& window);
void renderLevel_One(sf::RenderWindow& window, sf::Sprite& tempPlayerASprite, sf::Sprite& tempPlayerBSprite, sf::Sprite& tempPlayerASprite2, sf::Sprite& tempPlayerBSprite2);

void handleMainMenuEvents(sf::RenderWindow& window, const sf::Event& event, bool& mainMenuState, bool& Socket_Enabled, bool& isRunning);
void handleLevelSelectEvents(sf::RenderWindow& window);
void handlePlayingEvents(sf::RenderWindow& window);

void hostGameLogic(Character& character, Character& character2);
void connectGameLogic(Character& character, Character& character2);

// Define your application class
class SFMLApp
{
public:
    // Constructor and Destructor
    SFMLApp();
    ~SFMLApp();

    void loadResources();
    void resizeBackground();
    

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

    // Texture and Sprites
    sf::Texture cursorTexture;
    sf::Sprite cursorSprite;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::Texture backgroundBlurTexture; 
    sf::Sprite backgroundBlurSprite;

    sf::Texture SelectbackgroundTexture;
    sf::Sprite SelectbackgroundSpriteLeft;
    sf::Sprite SelectbackgroundSpriteRight;

    sf::Texture tempPlayerATexture;
    sf::Sprite tempPlayerASprite;
    sf::Sprite tempPlayerASprite2;

    sf::Texture tempPlayerBTexture;
    sf::Sprite tempPlayerBSprite;
    sf::Sprite tempPlayerBSprite2;

    sf::Texture SelectbackgroundTextureActive;
    sf::Sprite SelectbackgroundSpriteLeftActive;
    sf::Sprite SelectbackgroundSpriteRightActive;

    sf::Text singlePlayer; 
    sf::Text coOp;       
    sf::Text exit;       

    // Initialization function
    void initWindow();

    // Event handling function
    void processEvents();

    // Update logic
    void update();

    // Rendering function
    void render();

    // Handle events based on the current state
    void handleStateEvents(const sf::Event& event);

    // Rendering methods for different states
    void renderMainMenu();
    void renderLevelMenu();
    void renderGame();

    // Loop variables
    bool isRunning;
    bool mainMenuState;
    
};

extern int screenWidth;
extern int screenHeight;
extern int characterSelect;
extern int StateChange;

#endif // SFML_APP_H