#include "Main.h"

using namespace std;

int screenWidth = 1920;
int screenHeight = 1080;

bool Connected;
bool Host;
bool HostCharacterSelection;
bool ClientCharacterSelection;
bool isGrounded; 

// Declare shared pointers for character objects
std::shared_ptr<Character> hostCharacter = std::make_shared<Character>("HostCharacter", sf::Vector2f(0.f, 0.f), 0);
std::shared_ptr<Character> clientCharacter = std::make_shared<Character>("ClientCharacter", sf::Vector2f(0.f, 0.f), 0);

// Declare vectors to determine what object instances are collidable with a charcter.
std::vector<Object> collidableObjectsLevelOne;
std::vector<Object> collidableObjectsLevelTwo;

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

    isGrounded = false;                 // Turns gravity off when touching the ground, otherwise it jitters.
    isRunning = true;                   // When the window closes, this kills the program.
    
    currentState = State::MAIN_MENU;    // Begins the program at the Main Menu State.

    delayedState = State::LEVEL_ONE;    // This is used to keep track of individual players 
                                        // states while in the pause menu.

    mainMenuState = true;               // Determines if the Main Menu's background is blurred (not necessary just fun).

}

// Main game loop
void SFMLApp::run()
{

    sf::Clock clock;


    while (isRunning && window.isOpen())
    {

        sf::Time deltaTime = clock.restart();

        processEvents();     // Handle inputs
        render();            // Draw everything to the window
        update(window);      // Update states and Animation

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

    std::cout << "Resources successfully released in SFMLApp destructor." << std::endl;


}