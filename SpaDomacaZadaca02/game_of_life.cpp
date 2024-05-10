#include "game_of_life.h"
#include <io.h>
#include <chrono>
#include<ctime>

using namespace std;

game_of_life::game_of_life(sf::RenderWindow *window, vector<vector<bool>>& sucelje)
{
    this->window = window;
    this->sucelje = sucelje;
    srand(time(nullptr));
}

void game_of_life::napravi_red()
{
    float sirina_stanice = static_cast<float>(window->getSize().x) / stupac;
    float visina_stanice = static_cast<float>(window->getSize().y) / red;
    float dimenzije_stanice = min(sirina_stanice, visina_stanice);

    for (int i = 0; i < stupac; ++i) {
        for (int j = 0; j < red; ++j) {
            sf::RectangleShape oblik_stanice(sf::Vector2f(sirina_stanice, visina_stanice));
            oblik_stanice.setPosition(i * sirina_stanice, j * visina_stanice);
            if (sucelje[i][j]) {
                oblik_stanice.setFillColor(sf::Color::Cyan);
            }
            else {
                oblik_stanice.setFillColor(sf::Color::Black);
            }
            window->draw(oblik_stanice);
        }
    }
}

void game_of_life::napravi_sucelje()
{
    for (int i = 0; i < stupac; ++i) {
        for (int j = 0; j < red; ++j) {
            double randomValue = 1 + rand() % (100 - 1 + 1);
            if (randomValue <= 25) {
                sucelje[i][j] = true;
            }
            else {
                sucelje[i][j] = false;
            }
        }
    }
}

void game_of_life::azuriraj_sucelje()
{
    vector<vector<bool>> novo_sucelje(sucelje);
    for (int i = 0; i < stupac; ++i) {
        for (int j = 0; j < red; ++j) {
            int zivi_susjed = prebroji_zive_susjede(i, j);
            if (sucelje[i][j]) {
                if (zivi_susjed < 2 || zivi_susjed > 3) {
                    novo_sucelje[i][j] = false;
                }
            }
            else {
                if (zivi_susjed == 3) {
                    novo_sucelje[i][j] = true;
                }
            }
        }
    }
    sucelje = novo_sucelje;
}

int game_of_life::prebroji_zive_susjede(int x, int y)
{
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < stupac && ny >= 0 && ny < red && sucelje[nx][ny]) {
                ++count;
            }
        }
    }
    return count;
}
