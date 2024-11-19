#include "Main.h"

void SFMLApp::renderLevelMenu()
{

	window.draw(backgroundBlurSprite);

	sf::Font font;
	font.loadFromFile("Resources/Pacifico.ttf"); // Load a font

	sf::Text text("Resume", font, 60);
	text.setFillColor(sf::Color::Black);
	text.setPosition(screenWidth / 2 + 600, screenHeight / 2 - 320); // Center text

	sf::Text text2("Exit", font, 60);
	text2.setFillColor(sf::Color::Black);
	text2.setPosition(screenWidth / 2 + 600, screenHeight / 2 - 250); // Center text

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	// Change color if mouse is hovering over the text
	if (text.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{

		text.setFillColor(sf::Color::Red); // Change to red
	}

	if (text2.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{

		text2.setFillColor(sf::Color::Red); // Change to red
	}
	
	window.draw(text);
	window.draw(text2);
}