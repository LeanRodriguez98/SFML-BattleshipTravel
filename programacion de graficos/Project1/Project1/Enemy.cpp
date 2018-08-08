#include "Enemy.h"
#include "Bullet.h"
using namespace std;
Enemy::Enemy(float x_position, float y_position)
{
	enemyTexture = new Texture();
	enemySprite = new Sprite();
	position = new Vector2f();
	shootClock = new Clock();
	shootTime = new Time();
	position->x = x_position;
	position->y = y_position;
	enemyTexture->loadFromFile("Enemy.png");
	enemySprite->setTexture(*enemyTexture);
	enemySprite->setPosition(position->x, position->y);
	enemySprite->setScale(2, 2);
	speed = 5;
	frameRate = 0.4;
}
void Enemy::UpdateFrameRate()
{
	if (shootTime->asSeconds() > frameRate)
		shootClock->restart();
	*shootTime = shootClock->getElapsedTime();	
}
void Enemy::Movement()
{
	enemySprite->move(-speed,0);
	*position = (Vector2f)enemySprite->getPosition();

}
Vector2f Enemy::GetPosition()
{
	return *position;
}


Sprite Enemy::GetSprite()
{
	return *enemySprite;
}

float Enemy::GetFrameRate() 
{
	return shootTime->asSeconds();
}

Enemy::~Enemy() 
{
	delete enemyTexture;
	delete enemySprite;
	delete position;
	delete shootClock;
	delete shootTime;
}