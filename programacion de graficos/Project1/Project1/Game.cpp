#include "Game.h"
#include <iostream>
Game::Game(Vector2i resolution, String title)
{
	gameWindow = new RenderWindow(VideoMode(resolution.x, resolution.y), title);
	maxFps = 60;
	gameLoop = true;
	gameWindow->setFramerateLimit(maxFps);
	player = new Player();
	events = new Event;

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
	gameWindow->draw(player->GetSprite());
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
			exit(1);
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
			break;
		}
	}
} 
