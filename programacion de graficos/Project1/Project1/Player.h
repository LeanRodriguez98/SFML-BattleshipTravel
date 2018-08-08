#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;

class Player
{
public:
	Player();
	~Player();
	void SetPosition(float,float);
	Vector2f GetPosition();	
	Sprite GetSprite();

private:
	Texture* playerTexture;
	Sprite* playerSprite;
	Vector2f* position;
	float speed;
};
