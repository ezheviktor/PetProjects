#pragma once
#include "General.h"
#include "Tetramino.h"

class Field
{
	//screen related objects 
	Vector2f m_screenSize;

	//tetris playfield related objects
	// змінити m_spr на Piece
	Sprite m_spr, sprite_background, sprite_frame;
	Texture m_tex, texture_background, texture_frame;
	static const int HEIGHT = 20;
	static const int WIDTH = 10;
	static int map[HEIGHT][WIDTH];

	//settings related objects
	Texture m_textureSettings;
	Sprite m_spriteSettings;

	//pointsCounter related objects
	Font m_font;
	Text m_counter;
	int m_pointsEarned = 0;
public:
	Field(RenderWindow& window);
	void displayTetrisPlayfield(RenderWindow& window, Tetramino& tetramino, float& timer);
	void displaySettingsMenu(RenderWindow& window);
	void deleteRows();
	void updatePointsEarned(int burntLines);
	void restartTetris(Tetramino& tetramino);
	bool checkEndGame();

	static const int getMapHEIGHT() { return HEIGHT; }
	static const int getMapWIDTH() { return WIDTH; }
	static const int getMapValueAt(int heightIndex, int widthIndex) { return map[heightIndex][widthIndex]; }
	static void setMapValueAt(int heightIndex, int widthIndex, int newValue) { map[heightIndex][widthIndex] = newValue; }
	const Vector2f& getScreenSize() { return m_screenSize; }
};
