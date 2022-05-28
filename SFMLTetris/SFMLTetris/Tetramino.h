#pragma once
#include "General.h"
#include "Piece.h"

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
	Tetramino();

	void tetraminoInit();
	void drawIn(RenderWindow& window);

	bool checkBorders(int coordinates[4][2]);

	void move(std::string&& option, int dX = 0, int dY = 0);

	void update(float& timer);
};