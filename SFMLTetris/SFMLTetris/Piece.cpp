#include "General.h"
#include "Piece.h"

Piece::Piece(int x, int y, int color, std::string fileName)
{
	m_texture.loadFromFile(fileName);
	m_sprite.setTexture(m_texture);
	setSpriteTextureRect(color);
	setPosition(x, y);

}

void Piece::setPosition(int x, int y)
{
	int shiftX = 28;
	int shiftY = 31;
	m_pieceX = x;
	m_pieceY = y;
	m_sprite.setPosition((m_pieceX * 18) + shiftX, (m_pieceY * 18) + shiftY);
}

void Piece::setSpriteTextureRect(int color)
{
	m_sprite.setTextureRect(IntRect(color * 18, 0, 18, 18));
}