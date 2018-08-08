#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include <time.h>
#include <iterator>
using namespace sf;
using namespace std;
#define FPSLIMIT 60
#define BULLETARRAYSIZE 100
#define BULLETSIZEY 10
#define ASTEROIDARRAYSIZE 20
#define ASTEROIDSPAWNTIME 1

class Game
{
public:
	Game(Vector2i resolution, String title);
	void GameLoop();
	void Draw();
	void Input();
	void SpawnAsteroids();
private:
	Player * player;
	RenderWindow * gameWindow;
	Event * events;
	int maxFps;
	bool gameLoop;
	Bullet *bulletArray[BULLETARRAYSIZE];
	Asteroid *asteroidArray[ASTEROIDARRAYSIZE];

	Texture * backgroundTexture;
	Sprite * backgroundSprite;
	Clock * gameClock;
	Time * gameTime;
};
