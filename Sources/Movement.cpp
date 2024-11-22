#include "Main.h"

std::shared_ptr<Character> currentCharacter;
float previousVelocityY = 0.0f;

void moveMents(const std::vector<Object>& collidableObjects, sf::Sprite tempPlayerSprite)
{

    // Determine which character is currently active
    if (hostCharacter->isHost())
        currentCharacter = hostCharacter;
    else if (clientCharacter->isHost())
        currentCharacter = clientCharacter;

    if (currentCharacter != nullptr)
    {

        sf::Vector2f velocity = currentCharacter->getVelocity();

        // Handle horizontal input
        if (inputManager.isMoveLeft())
        {

            if (walkingSound.getStatus() != sf::Sound::Playing && isGrounded)
            {

                walkingSound.play(); // Play walking sound if it's not already playing
            }

            velocity.x -= 0.3; // Move left
        }
        else if (inputManager.isMoveRight())
        {

            if (walkingSound.getStatus() != sf::Sound::Playing && isGrounded)
            {

                walkingSound.play(); // Play walking sound if it's not already playing
            }

            velocity.x += 0.3; // Move right
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
            {

                // Stop walking sound if character is not moving
                if (walkingSound.getStatus() == sf::Sound::Playing)
                {
                    walkingSound.stop();
                }

                velocity.x = 0;
            }

            if (std::abs(previousVelocityY) > 0.5f && std::abs(velocity.y) < 0.2f)
            {
                // Detected a sudden stop
                if (landingSound.getStatus() != sf::Sound::Playing)
                {
                    landingSound.play(); // Play landing sound
                }
                // Update previous velocity only when movement is ongoing               
                previousVelocityY = 0;
            }
            else
                previousVelocityY = velocity.y;

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

            // Check collision with the top of the object
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
                    }
                }
            }

            // Check collision with the right side of the character
            if (velocity.x > 0) // Moving right
            {

                if (charBounds.left + charBounds.width > objBounds.left &&
                    charBounds.left < objBounds.left + objBounds.width)
                {

                    // Check that the character is not standing on top or below the object
                    if (charBounds.top >= objBounds.top && charBounds.top + charBounds.height <= objBounds.top + objBounds.height)
                    {

                        // Ensure the character is within the bounds of the object (not just to the left of it)
                        if (charBounds.left + charBounds.width > objBounds.left &&
                            charBounds.left < objBounds.left + objBounds.width)
                        {

                            // Move the character to the left of the object (ensuring no overlap)
                            sf::Vector2f newPosition(objBounds.left - charBounds.width - 1, currentCharacter->getPositionY());
                            currentCharacter->setPosition(newPosition);
                            velocity.x = 0; // Stop horizontal movement
                        }
                    }
                }
            }

            // Check collision with the left side of the character
            if (velocity.x < 0) // Moving left
            {

                if (charBounds.left < objBounds.left + objBounds.width &&
                    charBounds.left + charBounds.width > objBounds.left)
                {

                    // Check that the character is not standing on top or below the object
                    if (charBounds.top >= objBounds.top && charBounds.top + charBounds.height <= objBounds.top + objBounds.height)
                    {

                        // Ensure the character is within the bounds of the object (not just to the right of it)
                        if (charBounds.left + charBounds.width > objBounds.left &&
                            charBounds.left < objBounds.left + objBounds.width)
                        {

                            // Move the character to the right of the object (ensuring no overlap)
                            sf::Vector2f newPosition(objBounds.left + objBounds.width + 1, currentCharacter->getPositionY());
                            currentCharacter->setPosition(newPosition);
                            velocity.x = 0; // Stop horizontal movement
                        }
                    }
                }
            }

            // Check collision with the bottom of the object
            if (velocity.y < 0) // Moving upward
            {

                if (charBounds.top < objBounds.top + objBounds.height &&
                    charBounds.top + charBounds.height > objBounds.top + objBounds.height &&
                    charBounds.left + charBounds.width - 1 > objBounds.left &&
                    charBounds.left < objBounds.left + objBounds.width + 1)
                {

                    // Move the character to the bottom of the object
                    sf::Vector2f newPosition(currentCharacter->getPositionX(), objBounds.top + objBounds.height + 1);
                    currentCharacter->setPosition(newPosition);
                    velocity.y = 0; // Stop upward movement
                }
            }

            // Check top and horizontal collision (left-right bounds)
            if (charBounds.top + charBounds.height > objBounds.top && charBounds.top < objBounds.top + objBounds.height && !(
                charBounds.left + charBounds.width - 1 > objBounds.left && charBounds.left < objBounds.left + objBounds.width + 1 &&
                charBounds.top <= objBounds.top - objBounds.height))
            {

                // Character is off the object horizontally, so turn off grounded
                isGrounded = false; // Ensure grounded status is false when horizontally off the object

            }

            // Check for jump input
            if (inputManager.isJump() && isGrounded)
            {

                if (jumpingSound.getStatus() != sf::Sound::Playing)
                {
                    jumpingSound.play(); // Play jumping sound
                }

                velocity.y = -20; // Set jump velocity (negative for upward movement)
                isGrounded = false; // Character is now in the air
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