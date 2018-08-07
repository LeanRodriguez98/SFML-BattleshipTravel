#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;

class Player
{
public:
	Player();
	void SetPosition(float,float);
	Vector2f GetPosition();
	void Shoot();
	Sprite GetSprite();

private:
	Texture* playerTexture;
	Sprite* playerSprite;
	Vector2f* position;
	float speed;
};
