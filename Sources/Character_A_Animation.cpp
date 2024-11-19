#include "Main.h"

int i = 0;

void SFMLApp::UpdateAnimationsJacob(sf::Sprite character)
{

	// Use sine of time to calculate rotation
	i++;
	if (i > 15) i = 0;

	float jiggleValue = std::sin(i / 3.0f) / 5;


	JacobForward.centerOrigin();
	JacobLeft.centerOrigin();
	JacobRight.centerOrigin();
	JacobForward.setPosition(character.getPosition().x + 56, character.getPosition().y + 83 + (jiggleValue * 4));
	JacobLeft.setPosition(character.getPosition().x + 56, character.getPosition().y + 83 + (jiggleValue * 4));
	JacobRight.setPosition(character.getPosition().x + 56, character.getPosition().y + 83+ (jiggleValue * 4));
	
	if (inputManager.isMoveLeft())
	{

		// Apply rotation
		JacobLeft.rotate(jiggleValue * 4);

		// Render
		JacobLeft.draw(window);
	}
	else if (inputManager.isMoveRight())
	{

		// Apply rotation
		JacobRight.rotate(jiggleValue * 4);

		// Render
		JacobRight.draw(window);
	}
	else
	{

		// Render
		JacobForward.draw(window);
	}	
}
