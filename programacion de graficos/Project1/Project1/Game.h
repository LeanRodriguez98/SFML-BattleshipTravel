#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "Bullet.h"
#include <list>
#include <vector>
#include <iterator>
using namespace sf;
using namespace std;
#define FPSLIMIT 60
#define BULLETARRAYSIZE 100
#define BULLETSIZEY 10

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
	Bullet *bulletArray[BULLETARRAYSIZE];
	Texture * backgroundTexture;
	Sprite * backgroundSprite;
};
