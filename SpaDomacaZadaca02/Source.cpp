#include <SFML/Graphics.hpp>
#include "game_of_life.h"
#include<vector>
#include <chrono>
#include <thread>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "The Game of Life");
	window.setFramerateLimit(60);

	std::vector<std::vector<bool>> grid(10000, std::vector<bool>(100, false));
	game_of_life the_game(&window, grid);
	the_game.napravi_sucelje();

	while (window.isOpen())
	{
;
		sf::Event event;
		while (window.pollEvent(event))

		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		the_game.napravi_red();
		the_game.azuriraj_sucelje();
		std::this_thread::sleep_for(std::chrono::seconds(2));
		window.display();
	}

	return 0;
}