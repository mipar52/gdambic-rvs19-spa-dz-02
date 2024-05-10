#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
#include<vector>
using namespace std;

class game_of_life {
private:
	static const unsigned int stupac = 50;
	static const unsigned int red = 20;
	const char ziva_celija = '0';
	const char mrtva_celija = ' ';

public:
	void napravi_red(vector<vector<bool>>& sucelje);
	void napravi_sucelje(vector<std::vector<bool>>& sucelje);
	void azuriraj_sucelje(vector<std::vector<bool>>& sucelje);

	int prebroji_zive_susjede(vector<std::vector<bool>>&, int x, int y);
	//game_of_life();
};

#endif
