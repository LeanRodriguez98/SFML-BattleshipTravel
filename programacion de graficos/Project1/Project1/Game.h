#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
using namespace sf;
using namespace std;
class Game
{
public:
	Game(Vector2i resolution, String title);
	void GameLoop();
	void Draw();
	void Input();
private:
	Player * player;
	RenderWindow * gameWindow;
	Event * events;
	int maxFps;
	bool gameLoop;
	
};
