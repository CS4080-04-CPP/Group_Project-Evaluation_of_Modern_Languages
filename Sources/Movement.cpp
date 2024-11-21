#include "Main.h"
#include <SFML/Audio.hpp>
#include <iostream>

// Declare sound objects and buffers
std::shared_ptr<Character> currentCharacter;
sf::Sound walkingSound;
sf::Sound landingSound;
sf::Sound jumpingSound;
sf::SoundBuffer walkingBuffer;
sf::SoundBuffer landingBuffer;
sf::SoundBuffer jumpingBuffer;

bool isGrounded = false; // Assume initially, character is not grounded

void loadSounds() {
    // Load sound buffers (call this once, typically at initialization)
    if (!walkingBuffer.loadFromFile("Resources/Cutewalking.mp3")) {
        std::cerr << "Failed to load walking sound!" << std::endl;
    }
    if (!landingBuffer.loadFromFile("Resources/Landing - Sound Effect.mp3")) {
        std::cerr << "Failed to load landing sound!" << std::endl;
    }
    if (!jumpingBuffer.loadFromFile("Resources/Jumping (1).mp3")) {
        std::cerr << "Failed to load jumping sound!" << std::endl;
    }

    // Set the buffers for the sounds
    walkingSound.setBuffer(walkingBuffer);
    landingSound.setBuffer(landingBuffer);
    jumpingSound.setBuffer(jumpingBuffer);
}

void moveMents(const std::vector<Object>& collidableObjects, sf::Sprite tempPlayerSprite)
{
    // Ensure sounds are loaded before using them
    static bool soundsLoaded = false;
    if (!soundsLoaded) {
        loadSounds();
        soundsLoaded = true;
    }

    // Determine which character is currently active
    if (hostCharacter->isHost())
        currentCharacter = hostCharacter;
    else if (clientCharacter->isHost())
        currentCharacter = clientCharacter;

    if (currentCharacter != nullptr)
    {
        sf::Vector2f velocity = currentCharacter->getVelocity();

        // Handle horizontal input (moving left and right)
        if (inputManager.isMoveLeft())
        {
            velocity.x -= 0.3; // Move left
            if (walkingSound.getStatus() != sf::Sound::Playing)
            {
                walkingSound.play(); // Play walking sound if it's not already playing
            }
        }
        else if (inputManager.isMoveRight())
        {
            velocity.x += 0.3; // Move right
            if (walkingSound.getStatus() != sf::Sound::Playing)
            {
                walkingSound.play(); // Play walking sound if it's not already playing
            }
        }
        else
        {
            // Apply deceleration when no input
            if (velocity.x > 0)
                velocity.x -= 0.4;
            else if (velocity.x < 0)
                velocity.x += 0.4;

            // Stop movement if below threshold
            if (std::abs(velocity.x) < 0.2)
                velocity.x = 0;

            // Stop walking sound if character is not moving
            if (walkingSound.getStatus() == sf::Sound::Playing)
            {
                walkingSound.stop();
            }
        }

        // Clamp horizontal velocity
        if (velocity.x > 9) velocity.x = 9;
        else if (velocity.x < -9) velocity.x = -9;

        // Apply gravity only if the character is not grounded
        if (!isGrounded)
        {
            velocity.y += 0.5; // Adjust gravity strength as needed
        }

        // Move character based on velocity
        currentCharacter->move(velocity.x, velocity.y);

        // Check for collisions with all objects in the collidableObjects list
        for (const Object& obj : collidableObjects)
        {
            sf::FloatRect charBounds = tempPlayerSprite.getGlobalBounds();
            sf::FloatRect objBounds = obj.getSprite().getGlobalBounds();

            // Check collision with the top of the object (Landing detection)
            if (velocity.y > 0) // Falling
            {
                if (charBounds.top + charBounds.height > objBounds.top && charBounds.top < objBounds.top + objBounds.height)
                {
                    // Check top and horizontal collision (left-right bounds)
                    if (charBounds.top + charBounds.height > objBounds.top && charBounds.top < objBounds.top + objBounds.height &&
                        charBounds.left + charBounds.width - 1 > objBounds.left && charBounds.left < objBounds.left + objBounds.width + 1 &&
                        charBounds.top <= objBounds.top - objBounds.height)
                    {
                        // Move character to the top of the object
                        sf::Vector2f newPosition(currentCharacter->getPositionX(), objBounds.top - charBounds.height);
                        currentCharacter->setPosition(newPosition);
                        velocity.y = 0; // Stop downward velocity
                        isGrounded = true; // Set grounded because we hit the top of the object

                        // Play landing sound if not already playing
                        if (landingSound.getStatus() != sf::Sound::Playing)
                        {
                            landingSound.play(); // Play landing sound
                        }
                    }
                }
            }

            // Check for jump input
            if (inputManager.isJump() && isGrounded)
            {
                velocity.y = -20; // Set jump velocity (negative for upward movement)
                isGrounded = false; // Character is now in the air

                // Play jumping sound if not already playing
                if (jumpingSound.getStatus() != sf::Sound::Playing)
                {
                    jumpingSound.play(); // Play jumping sound
                }
            }

            // Apply gravity when not grounded
            if (!isGrounded)
            {
                currentCharacter->setVelocity(velocity.x, velocity.y);
            }
            else
            {
                // Prevent jittering by stopping vertical movement when grounded
                currentCharacter->setVelocity(velocity.x, 0); // Set vertical velocity to 0 if grounded
            }
        }
    }
}
