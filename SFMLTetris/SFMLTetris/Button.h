#pragma once
#include "General.h"
#include "Field.h"

class Button
{
	Sprite m_spriteButton;
	Texture m_textureButton;
	bool m_isPressed;
	int m_x, m_y;
public:
	Button(Field& field, std::string& fileName, int coordX, int CoordY, int width, int height);

	void checkIfpressed()
	{

	}
};
