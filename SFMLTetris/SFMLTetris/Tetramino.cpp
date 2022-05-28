#include "Tetramino.h"
#include "Field.h"

Tetramino::Tetramino() { tetraminoInit(); }

void Tetramino::tetraminoInit()
{
	int newColor;
	bool generateColorAgain;
	do
	{
		newColor = getRandomNumber(0, 6);
		if (newColor == m_color)
			generateColorAgain = getRandomNumber(0, 1);
		else
			generateColorAgain = 0;

	} while (generateColorAgain);

	m_color = newColor;
	for (int i = 0; i < 4; ++i)
	{
		array[i].setPosition((m_types[m_color][i] % 2) + 4, m_types[m_color][i] / 2);
		array[i].setSpriteTextureRect(m_color);
	}
	/*this->move("vectorM", 4, 0);*/
}
void Tetramino::drawIn(RenderWindow& window)
{
	for (int i = 0; i < 4; ++i)
	{
		window.draw(array[i].getSprite());
	}
}

bool Tetramino::checkBorders(int coordinates[4][2])
{
	for (int i = 0; i < 4; i++)
	{
		if (coordinates[i][0] < 0 ||
			coordinates[i][0] >= Field::getMapWIDTH() /*WIDTH*/ ||
			coordinates[i][1] >= Field::getMapHEIGHT()/*HEIGHT*/) return 0;
		else if (Field::getMapValueAt(coordinates[i][1], coordinates[i][0])) return 0;
	}
	return 1;
}

void Tetramino::move(std::string&& option, int dX, int dY)
{
	int newCoordinates[4][2];
	for (int i = 0; i < 4; ++i)
	{
		if (option == "vectorM")
		{
			newCoordinates[i][0] = array[i].getPieceX() + dX;
			newCoordinates[i][1] = array[i].getPieceY() + dY;
		}
		else if (option == "rotationM")
		{
			newCoordinates[i][0] = array[1].getPieceX() - (array[i].getPieceY() - array[1].getPieceY());
			newCoordinates[i][1] = array[1].getPieceY() + array[i].getPieceX() - array[1].getPieceX();
		}
	}

	bool tetrStillInField = checkBorders(newCoordinates);
	if (tetrStillInField)
	{
		for (int i = 0; i < 4; ++i)
		{
			array[i].setPosition(newCoordinates[i][0], newCoordinates[i][1]);
		}
	}
	else if (!tetrStillInField && dY)
	{
		for (int i = 0; i < 4; i++) Field::setMapValueAt(array[i].getPieceY(), array[i].getPieceX(), m_color + 1);
		tetraminoInit();
	}
}

void Tetramino::update(float& timer)
{
	float updateDelay = 0.3;
	if (timer > updateDelay)
	{
		move("vectorM", 0, 1);
		timer = 0;
	}
}