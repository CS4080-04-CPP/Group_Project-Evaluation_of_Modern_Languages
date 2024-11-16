#include "Main.h"

std::vector<Object> collidableObjectsLevelTwo;

int var = -600;

void SFMLApp::renderLevelTwo()
{

    if (var < 2000) {var += 1;}else {var = -600;}

    Sky2.draw(window);
    LeftWall.draw(window);
    RightWall.draw(window);

    cloud1.setPosition(var, sin(var / 9) * 4 + 20);
    cloud1.draw(window);

    Floor5.draw(window);


    sf::Vector2f tempVector2(0.0f, 860.0f);
    if (hostCharacter->getPositionY() >= 860 && Host)
    {
        hostCharacter->setPosition(hostCharacter->getPosition() - tempVector2);
        StateChange = 2;

    }
    else if (clientCharacter->getPositionY() >= 860 && !Host)
    {
        clientCharacter->setPosition(clientCharacter->getPosition() - tempVector2);
        StateChange = 2;
    }

    if (Socket_Enabled == false)
    {
        if (hostCharacter->getCharacterType() == 1)
        {
            window.draw(tempPlayerASprite);
             tempPlayerASprite.setPosition(hostCharacter->getPosition());
             moveMents(collidableObjectsLevelTwo, tempPlayerASprite);
            
        }
        if (hostCharacter->getCharacterType() == 2)
        {
            window.draw(tempPlayerBSprite);
             tempPlayerBSprite.setPosition(hostCharacter->getPosition());
             moveMents(collidableObjectsLevelTwo, tempPlayerBSprite);
        }

    }
    else
    {
        if (hostCharacter->getCharacterType() == 1)
        {
            window.draw(tempPlayerASprite);
             tempPlayerASprite.setPosition(hostCharacter->getPosition());
             if (hostCharacter->isHost()) moveMents(collidableObjectsLevelTwo, tempPlayerASprite);
        }
        else if (hostCharacter->getCharacterType() == 2)
        {
            window.draw(tempPlayerBSprite);
             tempPlayerBSprite.setPosition(hostCharacter->getPosition());
             if (hostCharacter->isHost()) moveMents(collidableObjectsLevelTwo, tempPlayerBSprite);
        }

        if (clientCharacter->getCharacterType() == 1)
        {
            window.draw(tempPlayerASprite);
             tempPlayerASprite.setPosition(clientCharacter->getPosition());
             if (clientCharacter->isHost()) moveMents(collidableObjectsLevelTwo, tempPlayerASprite);
        }
        else if (clientCharacter->getCharacterType() == 2)
        {
            window.draw(tempPlayerBSprite);
             tempPlayerBSprite.setPosition(clientCharacter->getPosition());
             if (clientCharacter->isHost()) moveMents(collidableObjectsLevelTwo, tempPlayerBSprite);
        }
    }
}