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
	font = new Font();
	textPoints = new Text();
	backgroundTexture = new Texture();
	backgroundSprite = new Sprite();
	backgroundTexture->loadFromFile("Background.png");
	backgroundSprite->setTexture(*backgroundTexture);
	font->loadFromFile("SpaceFont.ttf");
	textPoints->setFont(*font);
	textPoints->setPosition(50, 500);
	textPoints->setCharacterSize(32);
	textPoints->setString("points: " + to_string(points));
	points = 0;
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
		//Colisions();
		Draw();
	}
}

void Game::Colisions() 
{
	for (int i = 0; i < ENEMYARRAYSIZE; i++)
	{
		if (enemyArray[i] != NULL) {
			
			for (int j = 0; j < BULLETARRAYSIZE; j++)
			{
				if (bulletArray[j] != NULL) {
					if (enemyArray[i]->GetSprite().getGlobalBounds().intersects(bulletArray[j]->GetSprite().getGlobalBounds()))
					{
						delete enemyArray[i];
						delete bulletArray[j];
						enemyArray[i] = NULL;
						bulletArray[j] = NULL;
						points += 100;
						break;
					}
				}
			}
			
		}
	}

	for (int i = 0; i < BULLETARRAYSIZE; i++) 
	{
		if (bulletArray[i] != NULL) 
		{
			if (bulletArray[i]->GetPosition().x > ScreenResolution->x)
			{
				delete bulletArray[i];
				bulletArray[i] = NULL;
			}
		}
	}

	for (int i = 0; i < ENEMYBULLETARRAYSIZE; i++)
	{
		if (enemyBulletArray[i] != NULL)
		{
			if (enemyBulletArray[i]->GetPosition().x < 0)
			{
				delete enemyBulletArray[i];
				enemyBulletArray[i] = NULL;
			}
		}
	}


	for (int i = 0; i < ENEMYARRAYSIZE; i++)
	{
		if (enemyArray[i] != NULL)
		{
			if (enemyArray[i]->GetPosition().x < 0)
			{
				delete enemyArray[i];
				enemyArray[i] = NULL;
			}
		}
	}

	for (int i = 0; i < ASTEROIDARRAYSIZE; i++)
	{
		if (asteroidArray[i] != NULL)
		{
			if (asteroidArray[i]->GetPosition().x < 0)
			{
				delete asteroidArray[i];
				asteroidArray[i] = NULL;
			}
		}
	}

	for (int i = 0; i < ASTEROIDARRAYSIZE; i++)
	{
		if (asteroidArray[i] != NULL) {

			for (int j = 0; j < BULLETARRAYSIZE; j++)
			{
				if (bulletArray[j] != NULL) {
					if (asteroidArray[i]->GetSprite().getGlobalBounds().intersects(bulletArray[j]->GetSprite().getGlobalBounds()))
					{
						delete asteroidArray[i];
						delete bulletArray[j];
						asteroidArray[i] = NULL;
						bulletArray[j] = NULL;
						points += 250;
						break;
					}
				}
			}

		}
	}

	for (int i = 0; i < ENEMYBULLETARRAYSIZE; i++)
	{
		if (enemyBulletArray[i] != NULL) {

			for (int j = 0; j < BULLETARRAYSIZE; j++)
			{
				if (bulletArray[j] != NULL) {
					if (enemyBulletArray[i]->GetSprite().getGlobalBounds().intersects(bulletArray[j]->GetSprite().getGlobalBounds()))
					{
						delete enemyBulletArray[i];
						delete bulletArray[j];
						enemyBulletArray[i] = NULL;
						bulletArray[j] = NULL;
						points += 150;
						break;
					}
				}
			}

		}
	}


	for (int i = 0; i < ENEMYBULLETARRAYSIZE; i++)
	{
		if (enemyBulletArray[i] != NULL && player != NULL) {
			if (enemyBulletArray[i]->GetSprite().getGlobalBounds().intersects(player->GetSprite().getGlobalBounds()))
			{
				delete enemyBulletArray[i];
				delete player;
				player = NULL;
				enemyBulletArray[i] = NULL;
				break;
			}
		}
	}

	for (int i = 0; i < ENEMYARRAYSIZE; i++)
	{
		if (enemyArray[i] != NULL && player != NULL) {
			if (enemyArray[i]->GetSprite().getGlobalBounds().intersects(player->GetSprite().getGlobalBounds()))
			{
				delete enemyArray[i];
				delete player;
				player = NULL;
				enemyArray[i] = NULL;
				break;
			}
		}
	}

	for (int i = 0; i < ASTEROIDARRAYSIZE; i++)
	{
		if (asteroidArray[i] != NULL && player != NULL) {
			if (asteroidArray[i]->GetSprite().getGlobalBounds().intersects(player->GetSprite().getGlobalBounds()))
			{
				delete asteroidArray[i];
				delete player;
				player = NULL;
				asteroidArray[i] = NULL;
				break;
			}
		}
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
	if (player != NULL)
	{
		gameWindow->draw(player->GetSprite());
	}
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
	if (textPoints != NULL)
	{
		textPoints->setString("points: " + to_string(points));

		gameWindow->draw(*textPoints);
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
			break;
		case Event::KeyPressed:
			if (player != NULL)
			{
				if (Keyboard::isKeyPressed(Keyboard::W) && player->GetPosition().y - player->GetSprite().getGlobalBounds().height > 0)
				{
					player->SetPosition(0, -1);
				}
				if (Keyboard::isKeyPressed(Keyboard::A) && player->GetPosition().x - (player->GetSprite().getGlobalBounds().width/4) > 0)
				{
					player->SetPosition(-1, 0);
				}
				if (Keyboard::isKeyPressed(Keyboard::S) && player->GetPosition().y + (player->GetSprite().getGlobalBounds().height * 1.5) < ScreenResolution->y)
				{
					player->SetPosition(0, 1);
				}
				if (Keyboard::isKeyPressed(Keyboard::D) && player->GetPosition().x + (player->GetSprite().getGlobalBounds().width * 1.2) < ScreenResolution->x)
				{
					player->SetPosition(1, 0);
				}
				if (Keyboard::isKeyPressed(Keyboard::Space))
				{
					for (int i = 0; i < BULLETARRAYSIZE; i++)
					{
						if (bulletArray[i] == NULL) {
							bulletArray[i] = new Bullet(true, player->GetPosition().x + player->GetSprite().getGlobalBounds().width, player->GetPosition().y + player->GetSprite().getGlobalBounds().height / 2 - BULLETSIZEY / 2);
							break;
						}
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

	delete ScreenResolution;
	delete backgroundTexture;
	delete backgroundSprite;
	delete asteroidClock;
	delete asteroidTime;
	delete enemyClock;
	delete enemyTime;
	delete font;
	delete textPoints;
	for (int i = 0; i < BULLETARRAYSIZE; i++)
	{
		if (bulletArray[i] != NULL)
			delete bulletArray[i];
	}
	for (int i = 0; i < ENEMYARRAYSIZE; i++)
	{
		if (enemyArray[i] != NULL)
			delete enemyArray[i];
	}
	for (int i = 0; i < ENEMYBULLETARRAYSIZE; i++)
	{
		if (enemyBulletArray[i] != NULL)
			delete enemyBulletArray[i];
	}
	for (int i = 0; i < ASTEROIDARRAYSIZE; i++)
	{
		if (asteroidArray[i] != NULL)
			delete asteroidArray[i];
	}
	//La computadora da un error que dice: "no se encontro delete_array.cpp"

	/*delete[] bulletArray;
	delete[] enemyArray;
	delete[] enemyBulletArray;
	delete[] asteroidArray;*/

}
