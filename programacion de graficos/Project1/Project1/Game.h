#ifndef GAME_H
#define GAME_H
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "Enemy.h"
#include <time.h>
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
	void Colisions();
	void MainMenuDraw();
	void MenusInput();
	void FinalScreenDraw();
	void DeleteEntitis();
private:
	enum Screen{ MainMenuScreen, GameScreen, FinalScreen,PauseScreen };
	Screen actualScreen;
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
	Font * font;
	Text * textPoints;
	Text * titleText;
	Text * pressSpaceToStartText;
	Text * gameOverText;
	Text * pressSpaceToRestartText;
	SoundBuffer * shootBuffer;
	Sound * shootSound;
	SoundBuffer * enemyShootBuffer;
	Sound * enemyShootSound;
	SoundBuffer * playerExplotionBuffer;
	Sound * playerExplotionSound;
	SoundBuffer * enemyExplotionBuffer;
	Sound * enemyExplotionSound;
	SoundBuffer * asteroidBuffer;
	Sound * asteroidSound;
	Music * backgroundMusic;

	int maxFps;
	int points;
	bool gameLoop;
};
#endif