#include "Field.h"
#include "Tetramino.h"
Field::Field(RenderWindow& window)
{

	//setting up tetris
	texture_background.loadFromFile("C:/Users/User/source/repos/GitRepos/PetProjects/SFMLTetris/Resources/Textures/background.png");
	sprite_background.setTexture(texture_background);
	texture_frame.loadFromFile("C:/Users/User/source/repos/GitRepos/PetProjects/SFMLTetris/Resources/Textures/frame.png");
	sprite_frame.setTexture(texture_frame);
	m_tex.loadFromFile("C:/Users/User/source/repos/GitRepos/PetProjects/SFMLTetris/Resources/Textures/tiles.png");
	m_spr.setTexture(m_tex);

	//setting up score counter
	m_font.loadFromFile("C:/Users/User/source/repos/GitRepos/PetProjects/SFMLTetris/Resources/Fonts/BAUHS93.TTF");
	m_counter.setFont(m_font);
	m_counter.setCharacterSize(24);
	m_counter.setFillColor(Color::Magenta);
	m_counter.move(9, 18 * 22);

	//setting up settings window
	m_screenSize = Vector2f(window.getSize());
	m_textureSettings.loadFromFile("C:/Users/User/source/repos/GitRepos/PetProjects/SFMLTetris/Resources/Textures/background-texture-sand-pesok-beach-marine-fon.jpg", IntRect(100, 100, m_screenSize.x, m_screenSize.y));
	m_spriteSettings.setTexture(m_textureSettings);

}
void Field::displayTetrisPlayfield(RenderWindow& window, Tetramino& tetramino, float& timer)
{
	window.draw(sprite_frame);
	window.draw(sprite_background);
	tetramino.update(timer);
	tetramino.drawIn(window);
	window.draw(m_counter);

	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
		{
			if (map[i][j] == 0) continue;
			m_spr.setTextureRect(IntRect((map[i][j] - 1) * 18, 0, 18, 18));
			m_spr.setPosition(j * 18, i * 18);
			m_spr.move(28, 31); // смещение
			window.draw(m_spr);
		}
	deleteRows();

}

void Field::displaySettingsMenu(RenderWindow& window)
{

	bool returnToPlaying = 0;

	while (window.isOpen() && !returnToPlaying)
	{

		Event event;
		while (window.pollEvent(event) && !returnToPlaying)
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape) returnToPlaying = true;
			}
		}
		window.draw(m_spriteSettings);
		window.display();
	}

}

void Field::deleteRows()
{
	int burntLines = 0;
	int rowIndex = HEIGHT - 1;
	for (int i = HEIGHT - 1; i > 0; --i)
	{
		int count = 0;
		for (int j = 0; j < WIDTH; ++j)
		{
			if (map[i][j]) count++;
			map[rowIndex][j] = map[i][j];
		}
		if (count < WIDTH) rowIndex--;
		else burntLines += 1;
	}
	updatePointsEarned(burntLines);
}

void Field::updatePointsEarned(int burntLines)
{
	if (burntLines == 1) m_pointsEarned += 100;
	else if (burntLines == 2) m_pointsEarned += 300;
	else if (burntLines == 3) m_pointsEarned += 700;
	else if (burntLines == 4) m_pointsEarned += 1500;
	//restart of the game
	else if (burntLines == -1) m_pointsEarned = 0;

	m_counter.setString("Score : " + std::to_string(m_pointsEarned));
}

void Field::restartTetris(Tetramino& tetramino)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			map[i][j] = 0;
		}
	}
	tetramino.tetraminoInit();
	updatePointsEarned(-1);


}

bool Field::checkEndGame()
{
	bool endGame = false;
	int filledInUpperRow = 0;
	for (int i = 0; i < WIDTH; i++)
	{
		if (map[1][i]) filledInUpperRow++;
	}
	if (filledInUpperRow > 0) endGame = true;
	return endGame;
}

int Field::map[Field::HEIGHT][Field::WIDTH] = { 0 };