#include "Main.h"

std::vector<Object> collidableObjects;
static bool isInitialized = false;

void renderLevel_One(sf::RenderWindow& window)
{

    if (!isInitialized)
    {
        initializeFloor();
        isInitialized = true;
    }

    Floor.draw(window);

    collidableObjects.push_back(Floor);

    if (Socket_Enabled == false)
    {
        if (hostCharacter->getCharacterType() == 1)
        {
            window.draw(tempPlayerASprite);
             tempPlayerASprite.setPosition(hostCharacter->getPosition());
             moveMents(collidableObjects, tempPlayerASprite);
            
        }
        if (hostCharacter->getCharacterType() == 2)
        {
            window.draw(tempPlayerBSprite);
             tempPlayerBSprite.setPosition(hostCharacter->getPosition());
             moveMents(collidableObjects, tempPlayerBSprite);
        }

    }
    else
    {
        if (hostCharacter->getCharacterType() == 1)
        {
            window.draw(tempPlayerASprite);
             tempPlayerASprite.setPosition(hostCharacter->getPosition());
             if (hostCharacter->isHost()) moveMents(collidableObjects, tempPlayerASprite);
        }
        else if (hostCharacter->getCharacterType() == 2)
        {
            window.draw(tempPlayerBSprite);
             tempPlayerBSprite.setPosition(hostCharacter->getPosition());
             if (hostCharacter->isHost()) moveMents(collidableObjects, tempPlayerBSprite);
        }

        if (clientCharacter->getCharacterType() == 1)
        {
            window.draw(tempPlayerASprite);
             tempPlayerASprite.setPosition(clientCharacter->getPosition());
             if (clientCharacter->isHost()) moveMents(collidableObjects, tempPlayerASprite);
        }
        else if (clientCharacter->getCharacterType() == 2)
        {
            window.draw(tempPlayerBSprite);
             tempPlayerBSprite.setPosition(clientCharacter->getPosition());
             if (clientCharacter->isHost()) moveMents(collidableObjects, tempPlayerBSprite);
        }
    }
}