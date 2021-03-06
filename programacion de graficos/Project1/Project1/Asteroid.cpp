#include "Asteroid.h"
Asteroid::Asteroid(float x_position, float y_position)
{
	asteroidTexture = new Texture();
	asteroidSprite = new Sprite();
	position = new Vector2f();
	position->x = x_position;
	position->y = y_position;
	asteroidTexture->loadFromFile("Asteroid.png");
	asteroidSprite->setTexture(*asteroidTexture);
	asteroidSprite->setPosition(x_position, y_position);
	speed = 20;

}

void Asteroid::Movement()
{	
	asteroidSprite->move(-speed, 0);
	*position = (Vector2f)asteroidSprite->getPosition();
}

Vector2f Asteroid::GetPosition() 
{
	return *position;
}

Sprite Asteroid::GetSprite()
{
	return *asteroidSprite;
}

Asteroid::~Asteroid() 
{
	delete asteroidTexture;
	delete asteroidSprite;
	delete position;
}