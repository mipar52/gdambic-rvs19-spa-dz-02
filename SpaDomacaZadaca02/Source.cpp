#include <SFML/Graphics.hpp>
#include "game_of_life.h"
#include<vector>
#include <cstdlib>
#include <io.h>
#include <chrono>
#include <thread>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "The Game of Life");
	window.setFramerateLimit(60);

	game_of_life the_game;
	std::vector<std::vector<bool>> grid(50, std::vector<bool>(20, false));
	the_game.napravi_sucelje(grid);

	while (window.isOpen())
	{
;
		sf::Event event;
		while (window.pollEvent(event))

		{
			while (true) {
				the_game.napravi_red(grid);
				the_game.azuriraj_sucelje(grid);
				std::this_thread::sleep_for(std::chrono::microseconds(100000));

				// leep(10000);
			   //  usleep(10000); // Sleep for 100,000 microseconds (0.1 seconds)
			}
			/*
						bool dalje;
			do {


				cout << "Dalje (1/0): ";
				cin >> dalje;
			} while (dalje);
			
			*/

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//cvijet.draw();
		window.display();
	}

	return 0;
}