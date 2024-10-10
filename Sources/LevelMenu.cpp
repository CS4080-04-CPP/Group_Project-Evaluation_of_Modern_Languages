#include "Main.h"

void renderLevelMenus(sf::RenderWindow& window)
{
	// Render level selection options here
	// Example: Draw "Press 1 for Level 1", "Press 2 for Level 2"
	sf::Font font;
	font.loadFromFile("Resources/Pacifico.ttf"); // Load a font
	sf::Text text("Select Level: Press 1 for Level 1, Press 2 for Level 2", font, 30);
	text.setFillColor(sf::Color::White);
	text.setPosition(screenWidth / 2 - 300, screenHeight / 2); // Center text
	window.draw(text);
}