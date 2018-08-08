#include "Player.h"
#include "Bullet.h"
#include <iostream>
using namespace std;
Player::Player()
{
	playerTexture = new Texture();
	playerSprite = new Sprite();
	position = new Vector2f();
	position->x = 100;
	position->y = 100;
	playerTexture->loadFromFile("Ship.png");
	playerSprite->setTexture(*playerTexture);
	playerSprite->setPosition(position->x,position->y);
	playerSprite->setScale(1.5, 1.5);
	speed = 10;
}

void Player::SetPosition(float x,float y)
{		
	playerSprite->move(speed * x, speed * y);
	*position = (Vector2f)playerSprite->getPosition();

}
Vector2f Player::GetPosition()
{
	return *position;
}


Sprite Player::GetSprite() 
{
	return *playerSprite;
}