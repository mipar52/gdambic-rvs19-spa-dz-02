#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include<vector>
#include <SFML/Graphics.hpp>

using namespace std;
class game_of_life {
private:
	static const unsigned int stupac = 150;
	static const unsigned int red = 100;
	vector<vector<bool>> sucelje;

	sf::RenderWindow* window;

public:
	game_of_life(sf::RenderWindow *window, vector<vector<bool>>& sucelje);
	void napravi_red();
	void napravi_sucelje();
	void azuriraj_sucelje();
	int prebroji_zive_susjede(int x, int y);
};

#endif
