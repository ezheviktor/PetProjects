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