#include "Main.h"

std::shared_ptr<Character> currentCharacter;

void moveMents()
{
    if (hostCharacter->isHost())
        currentCharacter = hostCharacter;
    else if (clientCharacter->isHost())
        currentCharacter = clientCharacter;

    if (currentCharacter != nullptr)
    {
        sf::Vector2f velocity = currentCharacter->getVelocity();

        if (inputManager.isMoveLeft())
        {
            velocity.x -= 0.3;
        }
        else if (inputManager.isMoveRight())
        {
            velocity.x += 0.3;
        }
        else
        {
            // Decelerate smoothly toward 0
            if (velocity.x > 0)
                velocity.x -= 0.4;
            else if (velocity.x < 0)
                velocity.x += 0.4;

            // Stop movement if velocity is below threshold to prevent wandering
            if (std::abs(velocity.x) < 0.2)
                velocity.x = 0;
        }

        // Clamp velocity to max limits
        if (velocity.x > 9) velocity.x = 9;
        else if (velocity.x < -9) velocity.x = -9;

        // Set the new velocity
        currentCharacter->setVelocity(velocity.x, velocity.y);

        // Move character
        currentCharacter->move(velocity.x, velocity.y);
    }
}