#include "Main.h"


void SFMLApp::renderLevelOne()
{

    // First handle state transitions for going between levels (this can not be done in LevelEvents).

    delayedState = State::LEVEL_ONE;
    
    sf::Vector2f tempVector(0.0f, 860.0f);
    if (hostCharacter->getPositionY() <= -20 && Host)
    {

        hostCharacter->setPosition(hostCharacter->getPosition() + tempVector);
        hostCharacter->setLevel(2);
        currentState = State::LEVEL_TWO;
    }
    else if (clientCharacter->getPositionY() <= -20 && !Host)
    {

        clientCharacter->setPosition(clientCharacter->getPosition() + tempVector);
        clientCharacter->setLevel(2);
        currentState = State::LEVEL_TWO;
    }

    // Then deal with rendering the level.

    Sky.draw(window);
    LeftWall.draw(window);
    RightWall.draw(window);

    Floor.draw(window);
    Floor2.draw(window);
    Floor3.draw(window);
    Floor4.draw(window);

    // Draw Characters based on character type, host, client, and if you are in single player or not.

    if (Socket_Enabled == false)
    {

        if (hostCharacter->getCharacterType() == 1)
        {

            window.draw(tempPlayerASprite);
            tempPlayerASprite.setPosition(hostCharacter->getPosition());
            moveMents(collidableObjectsLevelOne, tempPlayerASprite);
        }
        if (hostCharacter->getCharacterType() == 2)
        {

            window.draw(tempPlayerBSprite);
            tempPlayerBSprite.setPosition(hostCharacter->getPosition());
            moveMents(collidableObjectsLevelOne, tempPlayerBSprite);
        }
    }
    else
    {

        if (hostCharacter->getCharacterType() == 1 && hostCharacter->getLevel() == 1)
        {

            window.draw(tempPlayerASprite);
            tempPlayerASprite.setPosition(hostCharacter->getPosition());
            
            if (hostCharacter->isHost()) moveMents(collidableObjectsLevelOne, tempPlayerASprite);

        }
        else if (hostCharacter->getCharacterType() == 2 && hostCharacter->getLevel() == 1)
        {

            window.draw(tempPlayerBSprite);
            tempPlayerBSprite.setPosition(hostCharacter->getPosition());
            
            if (hostCharacter->isHost()) moveMents(collidableObjectsLevelOne, tempPlayerBSprite);

        }

        if (clientCharacter->getCharacterType() == 1 && clientCharacter->getLevel() == 1)
        {

            window.draw(tempPlayerASprite);
            tempPlayerASprite.setPosition(clientCharacter->getPosition());
            
            if (clientCharacter->isHost()) moveMents(collidableObjectsLevelOne, tempPlayerASprite);

        }
        else if (clientCharacter->getCharacterType() == 2 && clientCharacter->getLevel() == 1)
        {

            window.draw(tempPlayerBSprite);
            tempPlayerBSprite.setPosition(clientCharacter->getPosition());

            if (clientCharacter->isHost()) moveMents(collidableObjectsLevelOne, tempPlayerBSprite);

        }
    }
}