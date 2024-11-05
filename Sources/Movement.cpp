#include "Main.h"

std::shared_ptr<Character> currentCharacter;

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
            velocity.x -= 0.3; // Move left
        }
        else if (inputManager.isMoveRight())
        {
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
                velocity.x = 0;
        }

        // Check for jump input
        if (inputManager.isJump() && isGrounded)
        {
            velocity.y = -20; // Set jump velocity (negative for upward movement)
            isGrounded = false; // Character is now in the air
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

        // Check for collisions with all collidable objects
        for (const Object& obj : collidableObjects)
        {
            sf::FloatRect charBounds = tempPlayerSprite.getGlobalBounds();
            sf::FloatRect objBounds = obj.getSprite().getGlobalBounds();

            // Check if character's vertical bounds are intersecting with the object's vertical bounds
            if (charBounds.top + charBounds.height > objBounds.top && charBounds.top < objBounds.top + objBounds.height)
            {
                // Check if the character is falling
                if (velocity.y > 0) // Assuming positive y velocity indicates falling
                {
                    // Ensure that the character's bottom is below the object's top
                    if (charBounds.top + charBounds.height - velocity.y <= objBounds.top)
                    {
                        // Calculate the new position for the character
                        sf::Vector2f newPosition(currentCharacter->getPositionX(), objBounds.top - charBounds.height);
                        currentCharacter->setPosition(newPosition);

                        // Reset vertical velocity on collision
                        velocity.y = 0; // Only set velocity.y to 0 here
                        isGrounded = true; // Set isGrounded to true

                        // Debug message for collision
                        std::cout << "Collision detected! Moving character to: "
                            << newPosition.x << ", " << newPosition.y << std::endl;

                        // Optionally, you could break the loop here if you only want to handle the first collision
                        break;
                    }
                }
            }
        }
        
        // If the character is not colliding with any objects, set isGrounded to false
        if (!isGrounded)
        {
            // Continue to apply gravity if no collision was detected
            currentCharacter->setVelocity(velocity.x, velocity.y);
        }
        else
        {
            // Only set the velocity if grounded to prevent jittering
            currentCharacter->setVelocity(velocity.x, 0); // Set vertical velocity to 0 if grounded
        }
    }
}