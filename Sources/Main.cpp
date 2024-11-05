#include "Main.h"

using namespace std;

int screenWidth = 1920;
int screenHeight = 1080;
int StateChange;

bool Connected;
bool Host;
bool HostCharacterSelection;
bool ClientCharacterSelection;
bool isGrounded; 

// Declare shared pointers for character objects
std::shared_ptr<Character> hostCharacter = std::make_shared<Character>("HostCharacter", sf::Vector2f(0.f, 0.f), 0);
std::shared_ptr<Character> clientCharacter = std::make_shared<Character>("ClientCharacter", sf::Vector2f(0.f, 0.f), 0);

//Initilize an InputManager
InputManager inputManager;

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
    loadResources(window);

    isGrounded = false; 
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

    sf::Clock clock;


    while (isRunning && window.isOpen())
    {

        sf::Time deltaTime = clock.restart();

        processEvents();     // Handle input
        render();            // Draw everything to the window
        update(window);      // Update states

        sf::sleep(sf::seconds(1.f / 60.f) - deltaTime);

    }

}

// Destructor
SFMLApp::~SFMLApp()
{
    // Lifetime: Implicit resource deallocation occurs here as the class instance goes out of scope.
    // In cases where resources are dynamically allocated (e.g., using new), 
    // this is where explicit memory cleanup would take place.

}