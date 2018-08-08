#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;
class Bullet
{
public:
	Bullet(bool,float,float);	
	~Bullet();
	void Movement();
	Sprite GetSprite();
private:
	Texture * bulletTexture;
	Sprite * bulletSprite;
	Vector2f * position;
	float speed;
	bool ally;
};

