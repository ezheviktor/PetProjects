#pragma once
#include "General.h"

class Piece
{
	int m_pieceX;
	int m_pieceY;
	sf::Sprite m_sprite;
	// винести m_texture з piece і переробити частину з ініціалізацією текстури в piece і Field::displayEverything
	sf::Texture m_texture;
public:
	Piece(int x = 0, int y = 0, int color = 0, std::string fileName = "C:/Users/User/source/repos/GitRepos/PetProjects/SFMLTetris/Resources/Textures/tiles.png");

	void setPosition(int x, int y);
	void setSpriteTextureRect(int color);

	Sprite& getSprite() { return m_sprite; }
	const Texture& getTexture() { return m_texture; }
	const int getPieceX() { return m_pieceX; }
	const int getPieceY() { return m_pieceY; }
};
