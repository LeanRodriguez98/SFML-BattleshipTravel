#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;
using namespace std;
class Game 
{
public:
	Game(Vector2i resolution, String title);
	void GameLoop();
	void Draw();
private:
	RenderWindow * gameWindow;
	int maxFps;
	bool gameLoop;
};