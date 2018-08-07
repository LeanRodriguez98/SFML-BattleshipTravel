#include "Game.h"
Game::Game(Vector2i resolution, String title) 
{
	gameWindow = new RenderWindow(VideoMode(resolution.x, resolution.y), title);
	maxFps = 60;
	gameLoop = true;
	gameWindow->setFramerateLimit(maxFps);
	GameLoop();
}

void Game::GameLoop() 
{
	while (gameWindow->isOpen())
	{
		Draw();
	}
}

void Game::Draw() 
{
	gameWindow->clear(Color::Black);
	gameWindow->display();
}