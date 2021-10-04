#include <iostream>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include <string>
#include <random>
#include <ctime>
using namespace sf;

static const int HEIGHT = 20;
static const int WIDTH = 10;
static int map[HEIGHT][WIDTH] = { 0 };

int getRandomNumber(int min, int max)
{
	static const double fraction = 1 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand( ) * fraction * (max - min + 1) + min);
}

class Piece
{
	int pieceX;
	int pieceY;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
public:
	Piece(int x = 0, int y = 0, int color = 0, std::string textureFileName = "D:\\Навчання\\С++\\Textures\\tiles.png")
	{
		m_texture.loadFromFile(textureFileName);
		m_sprite.setTexture(m_texture);
		setSpriteTextureRect(color);
		setPosition(x, y);

	}


	void setPosition(int x, int y)
	{
		pieceX = x;
		pieceY = y;
		m_sprite.setPosition(pieceX * 18, pieceY * 18);
	}
	void setSpriteTextureRect(int color)
	{
		m_sprite.setTextureRect(IntRect(color * 18, 0, 18, 18));
	}


	Sprite& getSprite( ) { return m_sprite; }
	const Texture& getTexture( ) { return m_texture; }
	const int getPieceX( ) { return pieceX; }
	const int getPieceY( ) { return pieceY; }
};

class Tetramino
{
	Piece array[4];
	int m_color;
	int m_types[7][4]
	{
		{1,3,5,7},
		{2,4,5,7}, 
		{3,5,4,6}, 
		{3,5,4,7}, 
		{2,3,5,7}, 
		{3,5,7,6}, 
		{2,3,4,5} 
	};
public:
	Tetramino( )
	{
		
		m_color = getRandomNumber(0, 6);
		for (int i = 0; i < 4; ++i)
		{
			array[i].setPosition(m_types[m_color][i] % 2, m_types[m_color][i] / 2);
			array[i].setSpriteTextureRect(m_color);
		}
	}
	Piece& getElement(int index) { return array[index]; }
};


int main( )
{
	srand(static_cast<unsigned int>(time(0)));
	rand( );
	RenderWindow window(VideoMode(320, 480), "The Game!");

	Tetramino tetramino;


	while (window.isOpen( ))
	{
	
		Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == Event::Closed)
				window.close( );
		}

		
		window.clear(Color::Blue);

		for (int i = 0; i < 4; ++i)
		{
			window.draw(tetramino.getElement(i).getSprite( ));
		}
		
		window.display( );
	}

	return 0;
}