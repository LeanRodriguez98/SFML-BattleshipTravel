#include "Bullet.h"
Bullet::Bullet(bool _ally, float x_position, float y_position) 
{
	bulletTexture = new Texture();
	bulletSprite = new Sprite();
	position = new Vector2f();
	position->x = x_position;
	position->y = y_position;
	bulletTexture->loadFromFile("Bullet.png");
	bulletSprite->setTexture(*bulletTexture);
	bulletSprite->setPosition(x_position, y_position);
	speed = 30;
	ally = _ally;
}

void Bullet::Movement() 
{
	if (ally)
	{
		bulletSprite->move(speed, 0);
	}
	else
	{
		bulletSprite->move(-speed, 0);
	}
	*position = (Vector2f)bulletSprite->getPosition();

}

Vector2f Bullet::GetPosition()
{
	return *position;
}

Sprite Bullet::GetSprite()
{
	return *bulletSprite;
}

Bullet::~Bullet() 
{
	delete bulletTexture;
	delete bulletSprite;
	delete position;
}