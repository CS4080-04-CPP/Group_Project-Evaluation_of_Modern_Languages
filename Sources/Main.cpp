#include "Main.h"

using namespace std;

int screenWidth = 1920;
int screenHeight = 1080;

int main()
{
    // Create an instance of SFMLApp
    SFMLApp app;

    // Assume at first the player is by themselves.
    bool Socket_Enabled = false;

    // Run the application
    app.run();
    return 0;
}

// Constructor
SFMLApp::SFMLApp()
{

    initWindow();
    loadResources();

    isRunning = true;
    currentState = State::MAIN_MENU;    // Begins the program at the Main Menu State.
    mainMenuState = true;               // Determines if the background is blurred.
}

// Initialize the window
void SFMLApp::initWindow()
{

    window.create(sf::VideoMode(screenWidth, screenHeight), "Programing_Concepts_Game_Demo");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
}

// Main game loop
void SFMLApp::run()
{
    while (isRunning && window.isOpen())
    {

        processEvents();  // Handle input
        update();         // Update game state
        render();         // Draw everything to the window
    }

}

// Destructor
SFMLApp::~SFMLApp()
{
    // Lifetime: Implicit resource deallocation occurs here as the class instance goes out of scope.
    // In cases where resources are dynamically allocated (e.g., using new), 
    // this is where explicit memory cleanup would take place.
}