#ifndef ENEMY_H
#define ENEMY_H
#include "SFML\Graphics.hpp"
using namespace sf;

class Enemy
{
public:
	Enemy(float, float);
	~Enemy();
	void Movement();
	Vector2f GetPosition();
	Sprite GetSprite();
	void UpdateFrameRate();
	float GetFrameRate();
private:
	Texture * enemyTexture;
	Sprite* enemySprite;
	Vector2f* position;
	Clock * shootClock;
	Time * shootTime;
	float speed;
	float frameRate;

};
#endif 
