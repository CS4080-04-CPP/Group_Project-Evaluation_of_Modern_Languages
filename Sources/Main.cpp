#include "Main.h"

using namespace std;

int screenWidth = 1920;
int screenHeight = 1080;
int StateChange;

bool Connected;
bool Host;
bool HostCharacterSelection;
bool ClientCharacterSelection;

int main()
{
    // Create an instance of SFMLApp
    SFMLApp app;

    // Assume at first the player is by themselves.
    bool Socket_Enabled = false;
    Connected = false;

    //Single player uses host game logic.
    Host = true;

    // Boolean that controls when Level changes occur.
    StateChange = 0;

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

    window.create(sf::VideoMode(screenWidth, screenHeight), "Programing_Concepts_Game_Demo", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
}

// Main game loop
void SFMLApp::run()
{
    while (isRunning && window.isOpen())
    {

        processEvents();  // Handle input
        update();         // Update Animation state
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