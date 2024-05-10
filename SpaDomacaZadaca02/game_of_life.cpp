#include "game_of_life.h"
#include <io.h>
#include <chrono>
#include <thread>

using namespace std;

void game_of_life::napravi_red(vector<vector<bool>>& sucelje)
{
    for (int i = 0; i < stupac; ++i) {
        for (int j = 0; j < red; ++j) {
              std::this_thread::sleep_for(std::chrono::microseconds(100));
            cout << (sucelje[i][j] ? ziva_celija : mrtva_celija) << ' ';
        }
        cout << std::endl;
    }
}

void game_of_life::napravi_sucelje(vector<vector<bool>>& sucelje)
{
    for (int i = 0; i < stupac; ++i) {
        for (int j = 0; j < red; ++j) {
            sucelje[i][j] = rand() % 2 == 0;
        }
    }
}

void game_of_life::azuriraj_sucelje(vector<vector<bool>>& sucelje)
{
    vector<vector<bool>> novo_sucelje(sucelje); // Create a copy of the grid
    for (int i = 0; i < stupac; ++i) {
        for (int j = 0; j < red; ++j) {
            int zivi_susjed = prebroji_zive_susjede(sucelje, i, j);
            if (sucelje[i][j]) {
                if (zivi_susjed < 2 || zivi_susjed > 3) {
                    novo_sucelje[i][j] = false; // Cell dies due to underpopulation or overpopulation
                }
            }
            else {
                if (zivi_susjed == 3) {
                    novo_sucelje[i][j] = true; // Cell becomes alive due to reproduction
                }
            }
        }
    }
    sucelje = novo_sucelje; // Update the original grid with the new state
}

int game_of_life::prebroji_zive_susjede(vector<vector<bool>>& sucelje, int x, int y)
{
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Skip the current cell
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < stupac && ny >= 0 && ny < red && sucelje[nx][ny]) {
                ++count;
            }
        }
    }
    return count;
}
