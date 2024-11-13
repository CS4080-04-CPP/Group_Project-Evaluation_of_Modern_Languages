#include "Main.h"

std::vector<Object> collidableObjects;
static bool isInitialized = false;
int var = -400;

void renderLevel_One(sf::RenderWindow& window)
{

    

    if (!isInitialized)
    {
        Floor.setPosition(0, 1025);
        Floor2.setPosition(450, 800);
        Floor3.setPosition(300, 850);

        Sky.setPosition(0,0);

        Background1.setPosition(0,700);
        Background1.toggleTileMode();
        Background1.setTileRepeats(4, 1);

        isInitialized = true;
    }

    if (var < 1800) {
        var += 1; // Increase the variable by 100
    }
    else {
        var = -400; // Reset the variable when it reaches 1400
    }

    cloud1.setPosition(var, sin(var/9)*4 + 20);

    Sky.draw(window);
    cloud1.draw(window);
    Background1.draw(window);

    Floor.draw(window);
    Floor2.draw(window);
    Floor3.draw(window);
    

    collidableObjects.push_back(Floor);
    collidableObjects.push_back(Floor2);
    collidableObjects.push_back(Floor3);

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