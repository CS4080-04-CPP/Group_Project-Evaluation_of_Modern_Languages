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

    // Initialization function
    void initWindow();

    // Event handling function
    void processEvents();

    // Update logic
    void update();

    // Rendering function
    void render();

    // Your loop variables
    bool isRunning;
};

#endif // SFML_APP_H