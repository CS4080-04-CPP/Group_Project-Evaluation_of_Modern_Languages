#include "Main.h"

bool Socket_enabled;
int q = 0;

// Render the main menu
void SFMLApp::renderMainMenu()
{

    window.draw(mainMenuState ? backgroundSprite : backgroundBlurSprite);

    // Load the font
    sf::Font font;
    if (!font.loadFromFile("Resources/Pacifico.ttf")) // Load a font
    {

        std::cerr << "Error: Could not load font." << std::endl;
        return; // Early Exitw if font loading fails
    }

    sf::Font font2;
    if (!font2.loadFromFile("Resources/KGHAPPY.ttf")) // Load a font
    {
        std::cerr << "Error: Could not load font." << std::endl;
        return; // Early Exitw if font loading fails
    }

    // Create text objects
    sf::Text singlePlayer("Single Player", font, 40);
    sf::Text coOp("Co-Op", font, 40);
    sf::Text Exitw("Exit", font, 40);                 // originally it was called Exit,
    sf::Text host("Host", font, 60);                  // but as you can imagine that caused problems.
    sf::Text connect("Connect", font, 60);
    sf::Text playerSelect("Character Select", font2, 60);
    sf::Text playerSelectJacob("Jacob", font2, 24);
    sf::Text playerSelectMichelle("Michelle", font2, 24);

    // Set initial color to black
    singlePlayer.setFillColor(sf::Color::Black);
    coOp.setFillColor(sf::Color::Black);
    Exitw.setFillColor(sf::Color::Black);
    host.setFillColor(sf::Color::Black);
    connect.setFillColor(sf::Color::Black);
    playerSelect.setFillColor(sf::Color::Black);
    playerSelectJacob.setFillColor(sf::Color::Black);
    playerSelectMichelle.setFillColor(sf::Color::Black);

    // Set positions
    singlePlayer.setPosition(screenWidth / 2 + 600, screenHeight / 2 - 300); 
    coOp.setPosition(screenWidth / 2 + 650, screenHeight / 2 - 240);
    Exitw.setPosition(screenWidth / 2 + 650, screenHeight / 2 - 180); 
    host.setPosition(screenWidth / 2 + 600, screenHeight / 2 - 300); 
    connect.setPosition(screenWidth / 2 + 600, screenHeight / 2 - 220); 
    playerSelect.setPosition(screenWidth / 2 - 300, screenHeight / 2 - 400); 
    playerSelectJacob.setPosition(screenWidth / 2 - 180, screenHeight / 2 - 245);
    playerSelectMichelle.setPosition(screenWidth / 2 + 105, screenHeight / 2 - 245);

    // Get the current mouse position relative to the window
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    // Change color if mouse is hovering over the text
    if (singlePlayer.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {

        singlePlayer.setFillColor(sf::Color::Red); // Change to red
    }

    if (coOp.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {

        coOp.setFillColor(sf::Color::Red); // Change to red
    }

    if (Exitw.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y - 10)))
    {

        Exitw.setFillColor(sf::Color::Red); // Change to red
    }

    if (host.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {

        host.setFillColor(sf::Color::Red); // Change to red
    }

    if (connect.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {

        connect.setFillColor(sf::Color::Red); // Change to red
    }

    // Draw the texts
    if (mainMenuState)
    {

        window.draw(singlePlayer);
        window.draw(coOp);
        window.draw(Exitw);
    }
    else
    {

        if (Socket_Enabled == true && Connected == false)
        {

            window.draw(host);
            window.draw(connect);
        }
        
        if (Socket_Enabled == false || Connected == true)
        {

            q++;
            if (q > 15) q = 0;

            float jiggleValue = std::sin(q / 3.0f) / 5;

            window.draw(playerSelect);
            
            JacobForward.setPosition(820, 440 + jiggleValue * 4);
            MichelleForward.setPosition(1130, 440 + jiggleValue * 4);

            if (mousePos.x >= 717 && mousePos.x <= 959 && mousePos.y >= 308 && mousePos.y <= 578 && hostCharacter->getCharacterType() != 1 &&
                                                                                                    clientCharacter->getCharacterType() != 1)
            {

                window.draw(SelectbackgroundSpriteLeftActive);

                if (hostCharacter->getCharacterType() != 2 && clientCharacter->getCharacterType() != 2)
                {

                    window.draw(SelectbackgroundSpriteRight);
                    MichelleForward.draw(window);
                }
                else
                    characterSelectBoxRightInActive.draw(window);


                JacobForward.draw(window);
                
            }
            else if (mousePos.x >= 1019 && mousePos.x <= 1257 && mousePos.y >= 303 && mousePos.y <= 577 && hostCharacter->getCharacterType() != 2 &&
                                                                                                           clientCharacter->getCharacterType() != 2)
            {

                window.draw(SelectbackgroundSpriteRightActive);

                if (hostCharacter->getCharacterType() != 1 && clientCharacter->getCharacterType() != 1)
                {

                    window.draw(SelectbackgroundSpriteLeft);
                    JacobForward.draw(window);
                }
                else
                    characterSelectBoxLeftInActive.draw(window);                    

                MichelleForward.draw(window);
                
            }
            else if (hostCharacter->getCharacterType() == 1 || clientCharacter->getCharacterType() == 1)
            {

                window.draw(SelectbackgroundSpriteRight);
                MichelleForward.draw(window);
                JacobForward.draw(window);
                characterSelectBoxLeftInActive.draw(window);
            }
            else if (hostCharacter->getCharacterType() == 2 || clientCharacter->getCharacterType() == 2)
            {
                window.draw(SelectbackgroundSpriteLeft);
                JacobForward.draw(window);
                MichelleForward.draw(window);
                characterSelectBoxRightInActive.draw(window);
                                             
            }
            else
            {

                window.draw(SelectbackgroundSpriteLeft);
                window.draw(SelectbackgroundSpriteRight);
                JacobForward.draw(window);
                MichelleForward.draw(window);              
            }

            window.draw(playerSelectJacob);
            window.draw(playerSelectMichelle);
            //JacobForward.draw(window);
            //MichelleForward.draw(window);
        }
    }
}