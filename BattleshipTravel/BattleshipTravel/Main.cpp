#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Game.h"
using namespace std;
using namespace sf;
int main() {
	Game * game;
	game = new Game(Vector2i(800, 600), "BattleshipTravel");
	return 0;
}