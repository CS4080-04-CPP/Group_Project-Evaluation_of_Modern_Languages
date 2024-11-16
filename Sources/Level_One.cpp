#include "Main.h"

std::vector<Object> collidableObjectsLevelOne;


void SFMLApp::renderLevelOne()
{
    
    sf::Vector2f tempVector(0.0f, 860.0f);
    if (hostCharacter->getPositionY() <= -20 && Host)
    {
        hostCharacter->setPosition(hostCharacter->getPosition() + tempVector);
        StateChange = 3;
    }
    else if (clientCharacter->getPositionY() <= -20 && !Host)
    {
        clientCharacter->setPosition(clientCharacter->getPosition() + tempVector);
        StateChange = 3;
    }


    Sky.draw(window);
    LeftWall.draw(window);
    RightWall.draw(window);

    Floor.draw(window);
    Floor2.draw(window);
    Floor3.draw(window);
    Floor4.draw(window);

    
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
        if (hostCharacter->getCharacterType() == 1)
        {
            window.draw(tempPlayerASprite);
             tempPlayerASprite.setPosition(hostCharacter->getPosition());
             if (hostCharacter->isHost()) moveMents(collidableObjectsLevelOne, tempPlayerASprite);
        }
        else if (hostCharacter->getCharacterType() == 2)
        {
            window.draw(tempPlayerBSprite);
             tempPlayerBSprite.setPosition(hostCharacter->getPosition());
             if (hostCharacter->isHost()) moveMents(collidableObjectsLevelOne, tempPlayerBSprite);
        }

        if (clientCharacter->getCharacterType() == 1)
        {
            window.draw(tempPlayerASprite);
             tempPlayerASprite.setPosition(clientCharacter->getPosition());
             if (clientCharacter->isHost()) moveMents(collidableObjectsLevelOne, tempPlayerASprite);
        }
        else if (clientCharacter->getCharacterType() == 2)
        {
            window.draw(tempPlayerBSprite);
             tempPlayerBSprite.setPosition(clientCharacter->getPosition());
             if (clientCharacter->isHost()) moveMents(collidableObjectsLevelOne, tempPlayerBSprite);
        }
    }
}