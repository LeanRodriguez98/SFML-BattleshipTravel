#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace sf;
int main() {
	
	Game * game;
	game = new Game(Vector2i(800, 600), "BattleshipTravel");
	delete game;
	return 0;
}