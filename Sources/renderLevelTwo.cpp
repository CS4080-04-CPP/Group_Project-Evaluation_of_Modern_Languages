#include "Main.h"

int var = -600;

void SFMLApp::renderLevelTwo()
{

    // First handle state transitions for going between levels.

    delayedState = State::LEVEL_TWO;

    sf::Vector2f tempVector2(0.0f, 860.0f);
    if (hostCharacter->getPositionY() >= 860 && Host)
    {

        hostCharacter->setPosition(hostCharacter->getPosition() - tempVector2);
        hostCharacter->setLevel(1);
        currentState = State::LEVEL_ONE;
    }
    else if (clientCharacter->getPositionY() >= 860 && !Host)
    {

        clientCharacter->setPosition(clientCharacter->getPosition() - tempVector2);
        clientCharacter->setLevel(1);
        currentState = State::LEVEL_ONE;
    }

    // Then deal with rendering the level.

    Sky2.draw(window);
    LeftWall.draw(window);
    RightWall.draw(window);

    if (var < 2000) { var += 1; } else { var = -600; }
    cloud1.setPosition(var, sin(var / 9) * 4 + 20);
    cloud1.draw(window);

    Floor5.draw(window);
    Floor6.draw(window);

    // Draw Characters based on character type, host, client, and if you are in single player or not.

    if (Socket_Enabled == false)
    {

        if (hostCharacter->getCharacterType() == 1)
        {
                
            window.draw(tempPlayerASprite);
            tempPlayerASprite.setPosition(hostCharacter->getPosition());
            UpdateAnimationsJacob(tempPlayerASprite);
            moveMents(collidableObjectsLevelTwo, tempPlayerASprite);               
        }

        if (hostCharacter->getCharacterType() == 2)
        {

            window.draw(tempPlayerBSprite);
            tempPlayerBSprite.setPosition(hostCharacter->getPosition());
            UpdateAnimationsMichelle(tempPlayerBSprite);
            moveMents(collidableObjectsLevelTwo, tempPlayerBSprite);
        }
    }
    else
    {

        if (hostCharacter->getCharacterType() == 1 && hostCharacter->getLevel() == 2)
        {
            
            window.draw(tempPlayerASprite);
            tempPlayerASprite.setPosition(hostCharacter->getPosition());

            if (hostCharacter->isHost())
            {

                UpdateAnimationsJacob(tempPlayerASprite);
                if (clientCharacter->getLevel() == 2)
                    UpdateAnimationsMichelle(tempPlayerBSprite2);
                moveMents(collidableObjectsLevelTwo, tempPlayerASprite);
            }

        }
        else if (hostCharacter->getCharacterType() == 2 && hostCharacter->getLevel() == 2)
        {

            window.draw(tempPlayerBSprite);
            tempPlayerBSprite.setPosition(hostCharacter->getPosition());
            
            if (hostCharacter->isHost())
            {

                UpdateAnimationsJacob(tempPlayerBSprite);
                if (clientCharacter->getLevel() == 2)
                    UpdateAnimationsMichelle(tempPlayerASprite2);
                moveMents(collidableObjectsLevelTwo, tempPlayerBSprite);
            }
        }

        if (clientCharacter->getCharacterType() == 1 && clientCharacter->getLevel() == 2)
        {

            window.draw(tempPlayerASprite2);
            tempPlayerASprite2.setPosition(clientCharacter->getPosition());

            if (clientCharacter->isHost())
            {

                if (hostCharacter->getLevel() == 2)
                    UpdateAnimationsJacob(tempPlayerBSprite);
                UpdateAnimationsMichelle(tempPlayerASprite2);
                moveMents(collidableObjectsLevelTwo, tempPlayerASprite2);
            }
        }
        else if (clientCharacter->getCharacterType() == 2 && clientCharacter->getLevel() == 2)
        {

            window.draw(tempPlayerBSprite2);
            tempPlayerBSprite2.setPosition(clientCharacter->getPosition());
            
            if (clientCharacter->isHost())
            {

                if (hostCharacter->getLevel() == 2)
                    UpdateAnimationsJacob(tempPlayerASprite);
                UpdateAnimationsMichelle(tempPlayerBSprite2);
                moveMents(collidableObjectsLevelTwo, tempPlayerBSprite2);
            }
        }
    }
}
