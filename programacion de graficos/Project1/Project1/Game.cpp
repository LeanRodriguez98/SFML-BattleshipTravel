#include "Game.h"
#include <iostream>
Game::Game(Vector2i resolution, String title)
{
	srand(time(NULL));
	ScreenResolution = new Vector2i();
	*ScreenResolution = resolution;
	gameWindow = new RenderWindow(VideoMode(resolution.x, resolution.y), title);
	maxFps = FPSLIMIT;
	gameLoop = true;
	gameWindow->setFramerateLimit(maxFps);
	player = new Player();
	events = new Event();
	asteroidClock = new Clock();
	asteroidTime = new Time();
	enemyClock = new Clock();
	enemyTime = new Time();
	backgroundTexture = new Texture();
	backgroundSprite = new Sprite();
	backgroundTexture->loadFromFile("Background.png");
	backgroundSprite->setTexture(*backgroundTexture);

	GameLoop();
}

void Game::GameLoop()
{
	while (gameWindow->isOpen())
	{
		Input();
		SpawnEnemys();
		EnemyShoot();
		SpawnAsteroids();
		Draw();
	}
}

void Game::EnemyShoot() 
{
	for (int i = 0; i < ENEMYARRAYSIZE; i++)
	{
		if (enemyArray[i] != NULL) {

			if (enemyArray[i]->GetFrameRate() > ENEMYFRAMERATE)
			{
				for (int j = 0; j < ENEMYBULLETARRAYSIZE; j++)
				{
					if (enemyBulletArray[j] == NULL) {
						enemyBulletArray[j] = new Bullet(false, enemyArray[i]->GetPosition().x, enemyArray[i]->GetPosition().y + enemyArray[i]->GetSprite().getGlobalBounds().height / 2 - BULLETSIZEY / 2);
						break;
					}
				}
			}
		}
	}
}

void Game::SpawnEnemys() 
{
	*enemyTime = enemyClock->getElapsedTime();
	if (enemyTime->asSeconds() > (float)ENEMYSPAWNTIME)
	{
		*enemyTime = enemyClock->restart();
		for (int i = 0; i < ENEMYARRAYSIZE; i++)
		{
			if (enemyArray[i] == NULL) {
				enemyArray[i] = new Enemy(ScreenResolution->x, rand() % ScreenResolution->y - ENEMYSIZEY);
				break;
			}
		}
	}
}

void Game::SpawnAsteroids()
{
	*asteroidTime = asteroidClock->getElapsedTime();
	if (asteroidTime->asSeconds() > (float)ASTEROIDSPAWNTIME)
	{
		*asteroidTime = asteroidClock->restart();
		for (int i = 0; i < ASTEROIDARRAYSIZE; i++)
		{
			if (asteroidArray[i] == NULL) {
				asteroidArray[i] = new Asteroid(ScreenResolution->x,rand()%ScreenResolution->y-ASTEROIDSIZEY);
				break;
			}
		}
	}
}


void Game::Draw()
{
	gameWindow->clear(Color::Black);
	gameWindow->draw(*backgroundSprite);
	gameWindow->draw(player->GetSprite());
	for (int i = 0; i < BULLETARRAYSIZE; i++)
	{
		if (bulletArray[i] != NULL) {
			gameWindow->draw(bulletArray[i]->GetSprite());
			bulletArray[i]->Movement();
		}
	}
	for (int i = 0; i < ASTEROIDARRAYSIZE; i++)
	{
		if (asteroidArray[i] != NULL) {
			gameWindow->draw(asteroidArray[i]->GetSprite());
			asteroidArray[i]->Movement();
		}
	}
	for (int i = 0; i < ENEMYARRAYSIZE; i++)
	{
		if (enemyArray[i] != NULL) {
			gameWindow->draw(enemyArray[i]->GetSprite());
			enemyArray[i]->Movement();
			enemyArray[i]->UpdateFrameRate();
		}
	}
	for (int i = 0; i < ENEMYBULLETARRAYSIZE; i++)
	{
		if (enemyBulletArray[i] != NULL) {
			gameWindow->draw(enemyBulletArray[i]->GetSprite());
			enemyBulletArray[i]->Movement();
		}
	}
	gameWindow->display();
}

void Game::Input()
{
	while (gameWindow->pollEvent(*events))
	{
		switch (events->type)
		{
		case Event::Closed:
			gameWindow->close();
			exit(1);///////////////////////////////////////////////////////////////
			break;
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::W)) 
			{
				player->SetPosition(0, -1);
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player->SetPosition(-1, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player->SetPosition(0, 1);
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player->SetPosition(1, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Space)) 
			{
				for (int i = 0; i < BULLETARRAYSIZE; i++)
				{
					if (bulletArray[i] == NULL) {
						bulletArray[i] = new Bullet(true, player->GetPosition().x + player->GetSprite().getGlobalBounds().width, player->GetPosition().y + player->GetSprite().getGlobalBounds().height/2 - BULLETSIZEY/2);
						break;
					}
				}			
			}
			break;			
		}
	}
} 

Game::~Game() 
{
	delete player;
	delete gameWindow;
	delete events;
	delete[] bulletArray;
	delete[] asteroidArray;
	delete[] enemyArray;
	delete[] enemyBulletArray;
	delete ScreenResolution;
	delete backgroundTexture;
	delete backgroundSprite;
	delete asteroidClock;
	delete asteroidTime;
	delete enemyClock;
	delete enemyTime;
}
