#include "Main.h"

int i = 0;

void SFMLApp::UpdateAnimationsJacob(sf::Sprite character)
{

	// Use sine of time to calculate rotation
	i++;
	if (i > 15) i = 0;

	float jiggleValue = std::sin(i / 3.0f) / 5;
	static sf::Vector2f prevPosition;

	JacobForward.setPosition(character.getPosition().x + 56, character.getPosition().y + 83 + (jiggleValue * 4));
	JacobLeft.setPosition(character.getPosition().x + 56, character.getPosition().y + 83 + (jiggleValue * 4));
	JacobRight.setPosition(character.getPosition().x + 56, character.getPosition().y + 83+ (jiggleValue * 4));
	
	sf::Vector2f currentPosition = character.getPosition();
	float dx = currentPosition.x - prevPosition.x;

	
	if (dx < -0.1f) // Moving left
	{

		JacobLeft.rotate(jiggleValue * 4);
		JacobLeft.draw(window);
	}
	else if (dx > 0.1f) // Moving right
	{

		JacobRight.rotate(jiggleValue * 4);
		JacobRight.draw(window);
	}
	else // Standing still
	{

		JacobForward.draw(window);
	}

	// Update previous position
	prevPosition = currentPosition;
}
