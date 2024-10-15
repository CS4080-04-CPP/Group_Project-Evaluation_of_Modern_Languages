#include "Main.h"
#include "Character.h"


void renderLevel_One(sf::RenderWindow& window, sf::Sprite& tempPlayerASprite, sf::Sprite& tempPlayerBSprite, sf::Sprite& tempPlayerASprite2, sf::Sprite& tempPlayerBSprite2)
{
        
        //std::cout << "host: " << hostCharacter->getPosition().x << " " << hostCharacter->getPosition().y << std::endl;
        //std::cout << "Client: " << clientCharacter->getPosition().x << " " << clientCharacter->getPosition().y << std::endl;
    
    std::cout << std::endl << hostCharacter->getCharacterType() << " " << clientCharacter->getCharacterType() << std::endl;
   
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

     
    }
}