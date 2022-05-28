#include "Button.h"


Button::Button(Field& field, std::string& fileName, int coordX, int CoordY, int width, int height)
{
	m_textureButton.loadFromFile("C:/Users/User/source/repos/GitRepos/PetProjects/SFMLTetris/Resources/Textures/rectangle-game-supercell-son-of-a-dark-wizard-clash-royale.jpg");
	m_spriteButton.setTexture(m_textureButton);
	m_spriteButton.setScale(1 / 2.5, 1 / 3.0);
	double buttonCoordX = (field.getScreenSize().x - m_spriteButton.getGlobalBounds().width) / 2.0;
	m_spriteButton.move(Vector2f(buttonCoordX, field.getScreenSize().y / 7));
}