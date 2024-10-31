#include "Main.h"


void renderLevel_One(sf::RenderWindow& window)
{

    if (Socket_Enabled == false)
    {
        if (hostCharacter->getCharacterType() == 1)
        {
            window.draw(tempPlayerASprite);
             tempPlayerASprite.setPosition(hostCharacter->getPosition());
        }
        if (hostCharacter->getCharacterType() == 2)
        {
            window.draw(tempPlayerBSprite);
             tempPlayerBSprite.setPosition(hostCharacter->getPosition());
        }

        moveMents();
    }
    else
    {
        if (hostCharacter->getCharacterType() == 1)
        {
            window.draw(tempPlayerASprite);
             tempPlayerASprite.setPosition(hostCharacter->getPosition());
        }
        else if (hostCharacter->getCharacterType() == 2)
        {
            window.draw(tempPlayerBSprite);
             tempPlayerBSprite.setPosition(hostCharacter->getPosition());
        }

        if (clientCharacter->getCharacterType() == 1)
        {
            window.draw(tempPlayerASprite);
             tempPlayerASprite.setPosition(clientCharacter->getPosition());
        }
        else if (clientCharacter->getCharacterType() == 2)
        {
            window.draw(tempPlayerBSprite);
             tempPlayerBSprite.setPosition(clientCharacter->getPosition());
        }

        moveMents();
    }
}