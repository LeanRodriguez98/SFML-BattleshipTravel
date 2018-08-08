#include "Game.h"
#include <iostream>
Game::Game(Vector2i resolution, String title)
{
	gameWindow = new RenderWindow(VideoMode(resolution.x, resolution.y), title);
	maxFps = FPSLIMIT;
	gameLoop = true;
	gameWindow->setFramerateLimit(maxFps);
	player = new Player();
	events = new Event();
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
		Draw();
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
