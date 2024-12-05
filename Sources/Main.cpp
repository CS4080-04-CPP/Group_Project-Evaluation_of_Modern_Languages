#include "Main.h"

// Using namespaces allows for easier access to system commands,
// they will not be used past main, but for example
// std::cout << "", becomes cout << "";
using namespace std;

// To Avoid complex resource scaling, it is fixed at 1080p.
int screenWidth = 1920;
int screenHeight = 1080;

// All these variables set outside of the main function are
// extern variables. These are variables that do not fit in the SFML class
// and need to talk to other classes. Consider them public variables.
bool Connected;
bool Host;
bool HostCharacterSelection;
bool ClientCharacterSelection;
bool isGrounded; 

// These are class initilizers which needed to be public extern variables

//Initilize an InputManager
InputManager inputManager;

// Declare shared pointers for character objects
std::shared_ptr<Character> hostCharacter = std::make_shared<Character>("HostCharacter", sf::Vector2f(0.f, 0.f), 0);
std::shared_ptr<Character> clientCharacter = std::make_shared<Character>("ClientCharacter", sf::Vector2f(0.f, 0.f), 0);

// Originally these were not public, but my movement infastructer needed them.

// Declare vectors to determine what object instances are collidable with a charcter.
std::vector<Object> collidableObjectsLevelOne;
std::vector<Object> collidableObjectsLevelTwo;

int main()
{

    // Create an instance of SFMLApp
    SFMLApp app;

    // Assume at first the player is by themselves.
    bool Socket_Enabled = false;
    Connected = false;

    //Single player uses host game logic.
    Host = true;

    // Run the application
    app.run();

    return 0;
}

// Constructor
SFMLApp::SFMLApp()
{

    window.create(sf::VideoMode(screenWidth, screenHeight), "Programing_Concepts_Game_Demo", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    loadResources();                    // Loads all the resources before the program begins.
                                        // Had this demo been larger, it would have loaded dynamically

    isGrounded = false;                 // Turns gravity off when touching the ground, otherwise it jitters.
    isRunning = true;                   // When the window closes, this kills the program.
    
    currentState = State::MAIN_MENU;    // Begins the program at the Main Menu State.

    delayedState = State::LEVEL_ONE;    // This is used to keep track of an individual players 
                                        // states while in the pause menu. So when in level one, 
                                        // you hit escape it needs to remember you were at level one.

    mainMenuState = true;               // Determines if the Main Menu's background is blurred (not necessary just fun).
}

// Main game loop
void SFMLApp::run()
{

    sf::Clock clock;

    while (isRunning && window.isOpen())
    {

        sf::Time deltaTime = clock.restart();

        update(window);      // Update inputs
        processEvents();     // Handle inputs
        render();            // Draw resources to window        

        sf::sleep(sf::seconds(1.f / 60.f) - deltaTime); // Framerate Target
    }
}

// Destructor
SFMLApp::~SFMLApp()
{

    // Clear collidable objects
    collidableObjectsLevelOne.clear();
    collidableObjectsLevelTwo.clear();

    // SFML's textures and sprites automatically clean up when the object goes out of scope.
    // This is just an example for if they did not.

    // Release textures and sprites
    backgroundTexture = sf::Texture(); // Reset texture to release memory
    backgroundBlurTexture = sf::Texture();
    tempPlayerATexture = sf::Texture();
    tempPlayerBTexture = sf::Texture();
    SelectbackgroundTexture = sf::Texture();
    SelectbackgroundTextureActive = sf::Texture();

    // Reset sprites to default state
    backgroundSprite = sf::Sprite();
    backgroundBlurSprite = sf::Sprite();
    tempPlayerASprite = sf::Sprite();
    tempPlayerASprite2 = sf::Sprite();
    tempPlayerBSprite = sf::Sprite();
    tempPlayerBSprite2 = sf::Sprite();
    SelectbackgroundSpriteLeft = sf::Sprite();
    SelectbackgroundSpriteRight = sf::Sprite();
    SelectbackgroundSpriteLeftActive = sf::Sprite();
    SelectbackgroundSpriteRightActive = sf::Sprite();

    std::cout << "Resources successfully released in destructor." << std::endl;


}