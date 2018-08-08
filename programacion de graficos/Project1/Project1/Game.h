#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "Enemy.h"
#include <time.h>
#include <iterator>
using namespace sf;
using namespace std;
#define FPSLIMIT 60
#define BULLETARRAYSIZE 100
#define BULLETSIZEY 10
#define ASTEROIDARRAYSIZE 20
#define ASTEROIDSPAWNTIME 1
#define ASTEROIDSIZEY 16
#define ENEMYARRAYSIZE 20
#define ENEMYSIZEY 18
#define ENEMYSPAWNTIME 2
#define ENEMYFRAMERATE 0.4
#define ENEMYBULLETARRAYSIZE 100
class Game
{
public:
	Game(Vector2i resolution, String title);
	~Game();
	void GameLoop();
	void Draw();
	void Input();
	void SpawnAsteroids();
	void SpawnEnemys();
	void EnemyShoot();
private:
	Player * player;
	RenderWindow * gameWindow;
	Event * events;	
	Bullet *bulletArray[BULLETARRAYSIZE];
	Asteroid *asteroidArray[ASTEROIDARRAYSIZE];
	Enemy * enemyArray[ENEMYARRAYSIZE];
	Bullet * enemyBulletArray[ENEMYBULLETARRAYSIZE];
	Vector2i * ScreenResolution;
	Texture * backgroundTexture;
	Sprite * backgroundSprite;
	Clock * asteroidClock;
	Time * asteroidTime;
	Clock * enemyClock;
	Time * enemyTime;
	int maxFps;
	bool gameLoop;
};
