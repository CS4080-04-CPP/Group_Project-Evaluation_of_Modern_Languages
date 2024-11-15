#include "Main.h"

std::vector<Object> collidableObjects;
static bool isInitialized = false;
int var = -600;

void SFMLApp::renderLevelOne()
{

    if (!isInitialized)
    {
        Floor.setPosition(0, 1000);
        Floor2.setPosition(1450, 750);
        Floor3.setPosition(1050, 450);

        Sky.setPosition(0,0);
        Trees.setPosition(0, 40);

        Background1.setPosition(0,700);
        Background1.toggleTileMode();
        Background1.setTileRepeats(4, 1);

        isInitialized = true;
    }

    if (var < 2000) {
        var += 1; // Increase the variable by 100
    }
    else {
        var = -600; // Reset the variable when it reaches 1400
    }

    std::cout << hostCharacter->getPositionY() << std::endl;
    sf::Vector2f tempVector(0.0f, 1000.0f);
    if (hostCharacter->getPositionY() <= -20)
    {
        hostCharacter->setPosition(hostCharacter->getPosition() + tempVector);
        StateChange = 3;
    }

    cloud1.setPosition(var, sin(var/9)*4 + 20);

    Sky.draw(window);
    cloud1.draw(window);
    //Background1.draw(window);
    //Trees.draw(window);

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