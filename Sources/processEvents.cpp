#include "Main.h"

bool Socket_Enabled;

// Event handling function
void SFMLApp::processEvents()
{
    sf::Event event;

    while (window.pollEvent(event))
    {

        if (event.type == sf::Event::Closed)
        {
            window.close();
            isRunning = false;
        }

        switch (currentState)
        {

        case State::MAIN_MENU:

            handleMainMenuEvents(event);

            break;
        case State::LEVEL_SELECT:

            handleLevelSelectEvents(event);

            break;
        case State::PLAYING:

            handlePlayingEvents(event);

            break;
        }

    }

}

