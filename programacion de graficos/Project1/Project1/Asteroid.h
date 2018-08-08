#ifndef ASTEROID_H
#define ASTEROID_H
#include "SFML\Graphics.hpp"
using namespace sf;
class Asteroid
{
public:
	Asteroid(float, float);
	~Asteroid();
	void Movement();
	Vector2f GetPosition();
	Sprite GetSprite();
private:
	Texture * asteroidTexture;
	Sprite * asteroidSprite;
	Vector2f * position;
	float speed;
	
};
#endif 

