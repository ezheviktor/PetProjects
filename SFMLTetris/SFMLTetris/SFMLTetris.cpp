//int getRandomNumber(int min, int max)
//{
//	static const double fraction = 1 / (static_cast<double>(RAND_MAX) + 1.0);
//	return static_cast<int>(rand( ) * fraction * (max - min + 1) + min);
//}
//
//void getPassedTime(Clock& clock, float& timer)
//{
//	float time = clock.getElapsedTime( ).asSeconds( );
//	clock.restart( );
//	timer += time;
//}

//class Field
//{
//	// змінити m_spr на Piece
//	Sprite m_spr, sprite_background, sprite_frame;
//	Texture m_tex, texture_background, texture_frame;
//	static const int HEIGHT = 20;
//	static const int WIDTH = 10;
//	static int map[HEIGHT][WIDTH];
//public:
//	Field( )
//	{
//		texture_background.loadFromFile("D:/Навчання/С++/Textures/background.png");
//		sprite_background.setTexture(texture_background);
//		texture_frame.loadFromFile("D:/Навчання/С++/Textures/frame.png");
//		sprite_frame.setTexture(texture_frame);
//		m_tex.loadFromFile("D:/Навчання/С++/Textures/tiles.png");
//		m_spr.setTexture(m_tex);
//	}
//	void displayEverything(RenderWindow& window)
//	{
//		window.draw(sprite_frame);
//		window.draw(sprite_background);
//		for (int i = 0; i < HEIGHT; i++)
//			for (int j = 0; j < WIDTH; j++)
//			{
//				if (map[i][j] == 0) continue;
//				m_spr.setTextureRect(IntRect((map[i][j]-1) * 18, 0, 18, 18));
//				m_spr.setPosition(j * 18, i * 18);
//				m_spr.move(28, 31); // смещение
//				window.draw(m_spr);
//			}
//		deleteRows( );
//
//	}
//
//	void deleteRows( )
//	{
//		int rowIndex=HEIGHT-1;
//		for (int i = HEIGHT - 1; i > 0; --i)
//		{
//			int count = 0;
//			for (int j = 0; j < WIDTH; ++j)
//			{
//				if (map[i][j]) count++;
//				map[rowIndex][j] = map[i][j];
//			}
//			if (count < WIDTH) rowIndex--;
//		}
//	}
//
//	static const int getMapHEIGHT( ) { return HEIGHT; }
//	static const int getMapWIDTH( ) { return WIDTH; }
//	static const int getMapValueAt(int heightIndex, int widthIndex) { return map[heightIndex][widthIndex]; }
//	static void setMapValueAt(int heightIndex, int widthIndex, int newValue) { map[heightIndex][widthIndex] = newValue; }
//};
//int Field::map[Field::HEIGHT][Field::WIDTH] = { 0 };

//class Piece
//{
//	int m_pieceX;
//	int m_pieceY;
//	sf::Sprite m_sprite;
//	// винести m_texture з piece і переробити частину з ініціалізацією текстури в piece і Field::displayEverything
//	sf::Texture m_texture;
//public:
//
//
//	Piece(int x = 0, int y = 0, int color = 0, std::string fileName = "D:/Навчання/С++/Textures/tiles.png")
//	{
//		m_texture.loadFromFile(fileName);
//		m_sprite.setTexture(m_texture);
//		setSpriteTextureRect(color);
//		setPosition(x, y);
//
//	}
//
//	void setPosition(int x, int y)
//	{
//		int shiftX = 28;
//		int shiftY = 31;
//		m_pieceX = x;
//		m_pieceY = y;
//		m_sprite.setPosition((m_pieceX * 18) +shiftX, (m_pieceY * 18 )+shiftY);
//	}
//	void setSpriteTextureRect(int color)
//	{
//		m_sprite.setTextureRect(IntRect(color * 18, 0, 18, 18));
//	}
//
//
//	Sprite& getSprite( ) { return m_sprite; }
//	const Texture& getTexture( ) { return m_texture; }
//	const int getPieceX( ) { return m_pieceX; }
//	const int getPieceY( ) { return m_pieceY; }
//};

//class Tetramino
//{
//	Piece array[4];
//	int m_color;
//	int m_types[7][4]
//	{
//		{1,3,5,7},
//		{2,4,5,7},
//		{3,5,4,6},
//		{3,5,4,7},
//		{2,3,5,7},
//		{3,5,7,6},
//		{2,3,4,5}
//	};
//public:
//	Tetramino( ) { tetraminoInit( ); }
//
//	void tetraminoInit( )
//	{
//		m_color = getRandomNumber(0, 6);
//		for (int i = 0; i < 4; ++i)
//		{
//			array[i].setPosition(m_types[m_color][i] % 2, m_types[m_color][i] / 2);
//			array[i].setSpriteTextureRect(m_color);
//		}
//	}
//	void drawIn(RenderWindow& window)
//	{
//		for (int i = 0; i < 4; ++i)
//		{
//			window.draw(array[i].getSprite( ));
//		}
//	}
//
//	bool checkBorders(int coordinates[4][2])
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			if (coordinates[i][0] < 0 || coordinates[i][0] >= Field::getMapWIDTH( ) /*WIDTH*/ || coordinates[i][1] >= Field::getMapHEIGHT( )/*HEIGHT*/) return 0;
//			else if (Field::getMapValueAt(coordinates[i][1], coordinates[i][0])) return 0;
//		}
//		return 1;
//	}
//
//	void move(std::string&& option, int dX = 0, int dY = 0)
//	{
//		int newCoordinates[4][2];
//		for (int i = 0; i < 4; ++i)
//		{
//			if (option == "vectorM")
//			{
//				newCoordinates[i][0] = array[i].getPieceX( ) + dX;
//				newCoordinates[i][1] = array[i].getPieceY( ) + dY;
//			}
//			else if (option == "rotationM")
//			{
//				newCoordinates[i][0] = array[1].getPieceX( ) - (array[i].getPieceY( ) - array[1].getPieceY( ));
//				newCoordinates[i][1] = array[1].getPieceY( ) + array[i].getPieceX( ) - array[1].getPieceX( );
//			}
//		}
//		if (checkBorders(newCoordinates))
//		{
//			for (int i = 0; i < 4; ++i)
//			{
//				array[i].setPosition(newCoordinates[i][0], newCoordinates[i][1]);
//			}
//		}
//		else if (!checkBorders(newCoordinates) && dY)
//		{
//			for (int i = 0; i < 4; i++) Field::setMapValueAt(array[i].getPieceY( ), array[i].getPieceX( ), m_color+1);
//			tetraminoInit( );
//		}
//	}
//
//	void update(float& timer)
//	{
//		float updateDelay = 0.3;
//		if (timer > updateDelay)
//		{
//			move("vectorM", 0, 1);
//			timer = 0;
//		}
//	}
//};

//static const int HEIGHT = 20;
//static const int WIDTH = 10;
//static int map[HEIGHT][WIDTH] = { 0 };
//class Timer
//	{
//		Clock m_clock;
//		float m_passedTime = 0
//			, m_delay = 0.3;
//	public:
//		void getPassedTime()
//		{
//			float time = m_clock.getElapsedTime( ).asSeconds( );
//			m_clock.restart( );
//			m_passedTime += time;
//		}
//	};
// //


/*Piece& getElement(int index) { return array[index]; }*/
//void rotate( )
//	{
//		int newArr[4][2];
//		for (int i = 0; i < 4; ++i)
//		{
//			newArr[i][0] = array[1].getPieceX( ) - (array[i].getPieceY( ) - array[1].getPieceY( ));
//			newArr[i][1] = array[1].getPieceY( ) + array[i].getPieceX( ) - array[1].getPieceX( );
//		}
//		if (checkBorders(newArr))
//		{
//			for (int i = 0; i < 4; ++i)
//			{
//				array[i].setPosition(newArr[i][0], newArr[i][1]);
//			}
//		}
//	}

//class Timer
//{
//	Clock m_clock;
//	float m_timer=0
//		, m_delay=0.3;
//public:
//	void print( )
//	{
//		std::cout << m_clock.getElapsedTime( ).asMicroseconds( ) << " microseconds have passed. " << m_timer << '\t' << m_delay << std::endl;
//	}
//	void getPassedTime(Clock& clock, float& timer)
//	{
//		float time = clock.getElapsedTime( ).asSeconds( );
//		clock.restart( );
//		timer += time;
//	}
//	float getTimer( )
//	{
//
//	}
//};
//#include <iostream>
//#include <vector>
//#include <array>
//#include <SFML/Graphics.hpp>
//#include <string>
//#include <random>
//#include <ctime>

#include "Piece.h"
#include "General.h"
#include "Field.h"
#include "Tetramino.h"

int main()
{
	srand(time(NULL));
	rand();
	Clock clock;
	float timer = 0;
	RenderWindow window(VideoMode(320, 480), "The Game!");

	Tetramino tetramino;
	Field field(window);

	//std::thread mainTetrisCycle(&Field::displayTetrisPlayfield,field, window, tetramino, timer );

	while (window.isOpen())
	{
		getPassedTime(clock, timer);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Right) tetramino.move("vectorM", 1, 0);
				if (event.key.code == Keyboard::Left) tetramino.move("vectorM", -1, 0);
				if (event.key.code == Keyboard::Down) tetramino.move("vectorM", 0, 1);
				if (event.key.code == Keyboard::Up) tetramino.move("rotationM");
				if (event.key.code == Keyboard::Escape) field.displaySettingsMenu(window);
			}
		}


		window.clear(Color::White);


		//std::string a = "D:/Навчання/С++/Fonts/";
		field.displayTetrisPlayfield(window, tetramino, timer);

		if (field.checkEndGame()) field.restartTetris(tetramino);

		window.display();
	}

	return 0;
}