#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace std;
using namespace sf;
int main() {
	bool gameOver = false;
	RenderWindow window(VideoMode(800, 600), "BattleshipTraveler");
	while (!gameOver)
	{
		window.display();
	}

	return 0;
}