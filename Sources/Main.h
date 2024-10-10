#ifndef SFML_APP_H
#define SFML_APP_H

// Include necessary SFML headers
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>

extern bool Socket_Enabled;

void renderMainMenus(sf::RenderWindow& window, bool& mainMenuState);
void renderLevelMenus(sf::RenderWindow& window);
void renderLevel_One(sf::RenderWindow& window);
void hostGameLogic();
void connectGameLogic();

// Define your application class
class SFMLApp
{
public:
    // Constructor and Destructor
    SFMLApp();
    ~SFMLApp();

    void loadResources();
    void resizeBackground();

    // Main loop
    void run();

private:
    // Enumeration for game states
    enum class State
    {
        MAIN_MENU,
        LEVEL_SELECT,
        PLAYING
    };

    // Current state of the application
    State currentState;

    // Window object
    sf::RenderWindow window;

    // Texture and Sprites
    sf::Texture cursorTexture;
    sf::Sprite cursorSprite;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::Texture backgroundBlurTexture; 
    sf::Sprite backgroundBlurSprite;

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

#endif // SFML_APP_H