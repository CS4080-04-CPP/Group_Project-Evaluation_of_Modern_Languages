#include "Main.h"

int i2 = 0;

void SFMLApp::UpdateAnimationsMichelle(sf::Sprite character)
{
	// Use sine of time to calculate rotation
	i2++;
	if (i2 > 15) i2 = 0;

	float jiggleValue = std::sin(i2 / 3.0f) / 5;


	MichelleForward.centerOrigin();
	MichelleLeft.centerOrigin();
	MichelleRight.centerOrigin();
	MichelleForward.setPosition(character.getPosition().x + 56, character.getPosition().y + 83 + (jiggleValue * 4));
	MichelleLeft.setPosition(character.getPosition().x + 56, character.getPosition().y + 83 + (jiggleValue * 4));
	MichelleRight.setPosition(character.getPosition().x + 56, character.getPosition().y + 83 + (jiggleValue * 4));

	if (inputManager.isMoveLeft())
	{

		// Apply rotation
		MichelleLeft.rotate(jiggleValue * 4);

		// Render
		MichelleLeft.draw(window);
	}
	else if (inputManager.isMoveRight())
	{

		// Apply rotation
		MichelleRight.rotate(jiggleValue * 4);

		// Render
		MichelleRight.draw(window);
	}
	else
	{

		// Render
		MichelleForward.draw(window);
	}
}
