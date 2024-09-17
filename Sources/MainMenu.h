#ifndef SFML_APP_H
#define SFML_APP_H

// Include necessary SFML headers
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

// Define your application class
class SFMLApp
{
public:
    // Constructor and Destructor
    SFMLApp();
    ~SFMLApp();

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

    // Initialization function
    void initWindow();
    void loadResources();

    // Event handling function
    void processEvents();

    // Update logic
    void update();

    // Rendering function
    void render();

    // Resize the background to fit the window
    void resizeBackground();

    // Loop variables
    bool isRunning;
};

#endif // SFML_APP_H