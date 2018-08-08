#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;

class Enemy
{
public:
	Enemy(float, float);
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
