#include "InputManager.h"
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream> // Required for std::cerr

void InputManager::processInput(sf::Window& window)
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
    if (isJumping && !jump)
    {
        jumpingSound.play();
    }

    // Simulate landing sound when jump key is released
    if (jump && !isJumping)
    {
        landingSound.play();
    }

    // Update movement flags
    moveLeft = isWalkingLeft;
    moveRight = isWalkingRight;
    jump = isJumping;
}
