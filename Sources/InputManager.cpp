#include "InputManager.h"
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream> // Required for std::cerr

void InputManager::processInput(sf::Window& window, bool isOnGround)
{
    // Create static sound buffers and sounds to avoid reloading files every frame
    static sf::SoundBuffer walkingBuffer;
    static sf::SoundBuffer landingBuffer;
    static sf::SoundBuffer jumpingBuffer;
    static sf::Sound walkingSound;
    static sf::Sound landingSound;
    static sf::Sound jumpingSound;

    // Load sound buffers once (make sure this happens before you play sounds)
    static bool isInitialized = false;
    if (!isInitialized)
    {
        if (!walkingBuffer.loadFromFile("C:\\Users\\solar\\Downloads\\Cutewalking.mp3"))
        {
            std::cerr << "Failed to load walking sound!" << std::endl;
        }
        if (!landingBuffer.loadFromFile("C:\\Users\\solar\\Downloads\\Landing - Sound Effect.mp3"))
        {
            std::cerr << "Failed to load landing sound!" << std::endl;
        }
        if (!jumpingBuffer.loadFromFile("C:\\Users\\solar\\Downloads\\Jumping (1).mp3"))
        {
            std::cerr << "Failed to load jumping sound!" << std::endl;
        }

        walkingSound.setBuffer(walkingBuffer);
        landingSound.setBuffer(landingBuffer);
        jumpingSound.setBuffer(jumpingBuffer);

        isInitialized = true;
    }

    // Only process input if the window is in focus
    if (!window.hasFocus())
    {
        moveLeft = false;
        moveRight = false;
        jump = false;
        return;
    }

    // Handle A key for moving left
    bool isWalkingLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    if (isWalkingLeft && walkingSound.getStatus() != sf::Sound::Playing)
    {
        walkingSound.play();
    }

    // Handle D key for moving right
    bool isWalkingRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    if (isWalkingRight && walkingSound.getStatus() != sf::Sound::Playing)
    {
        walkingSound.play();
    }

    // Handle Space key for jumping
    bool isJumping = sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    if (isJumping && !jump && isOnGround)
    {
        jumpingSound.play();
    }

    // Immediate landing sound
    static bool wasInAir = false; // Tracks if the player was in the air
    if (!isOnGround)
    {
        wasInAir = true; // Player is airborne
    }
    else if (wasInAir) // Player lands
    {
        if (landingSound.getStatus() != sf::Sound::Playing) // Ensure no overlapping
        {
            landingSound.stop(); // Stop any previous instance immediately
            landingSound.play(); // Play the landing sound immediately
        }
        wasInAir = false; // Reset air state after landing
    }

    // Update movement flags
    moveLeft = isWalkingLeft;
    moveRight = isWalkingRight;
    jump = isJumping;
}
