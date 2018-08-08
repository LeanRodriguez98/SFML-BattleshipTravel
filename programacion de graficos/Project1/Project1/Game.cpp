#include "Game.h"
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
	titleText = new Text();
	pressSpaceToStartText = new Text();
	gameOverText = new Text();
	pressSpaceToRestartText = new Text();
	backgroundTexture = new Texture();
	backgroundSprite = new Sprite();
	shootBuffer = new SoundBuffer();
	shootSound = new Sound();

	enemyShootBuffer = new SoundBuffer();
	enemyShootSound = new Sound();

	playerExplotionBuffer = new SoundBuffer();
	playerExplotionSound = new Sound();

	enemyExplotionBuffer = new SoundBuffer();
	enemyExplotionSound = new Sound();

	asteroidBuffer = new SoundBuffer();
	asteroidSound = new Sound();


	backgroundMusic = new Music();
	actualScreen = MainMenuScreen;
	backgroundTexture->loadFromFile("Background.png");
	backgroundSprite->setTexture(*backgroundTexture);
	font->loadFromFile("SpaceFont.ttf");
	textPoints->setFont(*font);
	textPoints->setPosition(50, 500);
	textPoints->setCharacterSize(32);
	points = 0;
	textPoints->setString("points: " + to_string(points));

	titleText->setFont(*font);
	titleText->setPosition(ScreenResolution->x / 8, ScreenResolution->y / 4);
	titleText->setCharacterSize(50);
	titleText->setString("BattleshipTravel!");
	
	pressSpaceToStartText->setFont(*font);
	pressSpaceToStartText->setPosition(ScreenResolution->x / 8, (ScreenResolution->y /4)*3);
	pressSpaceToStartText->setCharacterSize(40);
	pressSpaceToStartText->setString("Press Space To Start");


	gameOverText->setFont(*font);
	gameOverText->setPosition(ScreenResolution->x / 6, ScreenResolution->y / 4);
	gameOverText->setCharacterSize(80);
	gameOverText->setString("GAME OVER");

	pressSpaceToRestartText->setFont(*font);
	pressSpaceToRestartText->setPosition(ScreenResolution->x / 8 - 10, (ScreenResolution->y / 4) * 3);
	pressSpaceToRestartText->setCharacterSize(40);
	pressSpaceToRestartText->setString("Press Space To Restart");

	shootBuffer->loadFromFile("Shoot.wav");
	shootSound->setBuffer(*shootBuffer);
	shootSound->setVolume(10);

	enemyShootBuffer->loadFromFile("Shoot2.wav");
	enemyShootSound->setBuffer(*enemyShootBuffer);
	enemyShootSound->setVolume(10);

	playerExplotionBuffer->loadFromFile("Explosion.wav");
	playerExplotionSound->setBuffer(*playerExplotionBuffer);
	playerExplotionSound->setVolume(10);

	enemyExplotionBuffer->loadFromFile("Explosion2.wav");
	enemyExplotionSound->setBuffer(*enemyExplotionBuffer);
	enemyExplotionSound->setVolume(10);

	asteroidBuffer->loadFromFile("Asteroid.wav");
	asteroidSound->setBuffer(*asteroidBuffer);
	asteroidSound->setVolume(10);

	backgroundMusic->openFromFile("BackgroundMusic.wav");
	backgroundMusic->setVolume(5);
	backgroundMusic->setLoop(true);
	backgroundMusic->play();
	GameLoop();
}

void Game::GameLoop()
{
	while (gameWindow->isOpen())
	{
		switch (actualScreen)
		{
		case MainMenuScreen:
			MainMenuDraw();
			MenusInput();
			break;
		case GameScreen:
			Input();
			SpawnEnemys();
			EnemyShoot();
			SpawnAsteroids();
			Colisions();
			Draw();
			break;
		case FinalScreen:
			FinalScreenDraw();
			MenusInput();
			break;
		case PauseScreen:
			MenusInput();

		}
		
	}
}
void Game::FinalScreenDraw() 
{
	gameWindow->clear(Color::Black);
	gameWindow->draw(*backgroundSprite);
	gameWindow->draw(*gameOverText);
	gameWindow->draw(*pressSpaceToRestartText);
	gameWindow->display();
}

void Game::MainMenuDraw() 
{
	gameWindow->clear(Color::Black);
	gameWindow->draw(*backgroundSprite);
	gameWindow->draw(*titleText);
	gameWindow->draw(*pressSpaceToStartText);
	gameWindow->display();
}

void Game::MenusInput() 
{
	while (gameWindow->pollEvent(*events))
	{
		switch (events->type)
		{
		case Event::Closed:
			gameWindow->close();
			break;
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				if (actualScreen == MainMenuScreen)
				{
					actualScreen = GameScreen;
				}
				if (actualScreen == FinalScreen)
				{				
					actualScreen = MainMenuScreen;
					player = new Player();
					points = 0;
					DeleteEntitis();
				}
				
			}
			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				if (actualScreen == PauseScreen)
				{
					actualScreen = GameScreen;
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape)) 
			{
				gameWindow->close();
			}
			break;
		case Event::JoystickButtonPressed:

			if (actualScreen == MainMenuScreen)
			{
				actualScreen = GameScreen;
			}
			if (actualScreen == FinalScreen)
			{
				actualScreen = MainMenuScreen;
				player = new Player();
				points = 0;
				DeleteEntitis();
			}

			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				if (actualScreen == PauseScreen)
				{
					actualScreen = GameScreen;
				}
			}
			if (sf::Joystick::isButtonPressed(0, 7))
			{
				gameWindow->close();
			}
		}
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
						enemyExplotionSound->play();

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
				actualScreen = FinalScreen;
				playerExplotionSound->play();

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
				actualScreen = FinalScreen;
				playerExplotionSound->play();
				enemyExplotionSound->play();
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
				actualScreen = FinalScreen;
				playerExplotionSound->play();
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
					if (enemyBulletArray[j] == NULL)
					{
						enemyBulletArray[j] = new Bullet(false, enemyArray[i]->GetPosition().x, enemyArray[i]->GetPosition().y + enemyArray[i]->GetSprite().getGlobalBounds().height / 2 - BULLETSIZEY / 2);
						enemyShootSound->play();					
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
				asteroidSound->play();
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
				if ((Keyboard::isKeyPressed(Keyboard::W)) && player->GetPosition().y - player->GetSprite().getGlobalBounds().height > 0)
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
				if (Keyboard::isKeyPressed(Keyboard::Space) || sf::Joystick::isButtonPressed(0, 0))
				{
					for (int i = 0; i < BULLETARRAYSIZE; i++)
					{
						if (bulletArray[i] == NULL) {
							bulletArray[i] = new Bullet(true, player->GetPosition().x + player->GetSprite().getGlobalBounds().width, player->GetPosition().y + player->GetSprite().getGlobalBounds().height / 2 - BULLETSIZEY / 2);
							break;
						}
					}
					shootSound->play();
				}
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					gameWindow->close();
				}
				if (Keyboard::isKeyPressed(Keyboard::P))
				{
					actualScreen = PauseScreen;				
				}
			}
			break;		
		case Event::JoystickButtonPressed:

			if (sf::Joystick::isButtonPressed(0, 0))
			{
				for (int i = 0; i < BULLETARRAYSIZE; i++)
				{
					if (bulletArray[i] == NULL) {
						bulletArray[i] = new Bullet(true, player->GetPosition().x + player->GetSprite().getGlobalBounds().width, player->GetPosition().y + player->GetSprite().getGlobalBounds().height / 2 - BULLETSIZEY / 2);
						break;
					}
				}
				shootSound->play();
			}
			if (sf::Joystick::isButtonPressed(0, 6))
			{
				actualScreen = PauseScreen;
			}
			if (sf::Joystick::isButtonPressed(0, 7))
			{
				gameWindow->close();
			}	

		}

		Vector2f moveSpeed(sf::Joystick::getAxisPosition(0, Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
		if (moveSpeed.y < -70 && player->GetPosition().y - player->GetSprite().getGlobalBounds().height > 0)
		{
			player->SetPosition(0, -0.2);
		}
		if (moveSpeed.x < -70 && player->GetPosition().x - (player->GetSprite().getGlobalBounds().width / 4) > 0)
		{
			player->SetPosition(-0.2, 0);
		}
		if (moveSpeed.y > 70 && player->GetPosition().y + (player->GetSprite().getGlobalBounds().height * 1.5) < ScreenResolution->y)
		{
			player->SetPosition(0, 0.2);
		}
		if (moveSpeed.x  > 70 && player->GetPosition().x + (player->GetSprite().getGlobalBounds().width * 1.2) < ScreenResolution->x)
		{
			player->SetPosition(0.2, 0);
		}
	}
} 
void Game::DeleteEntitis()
{
	for (int i = 0; i < BULLETARRAYSIZE; i++)
	{
		if (bulletArray[i] != NULL)
		{		
		delete bulletArray[i];
		bulletArray[i] = NULL;
		}
	}
	for (int i = 0; i < ENEMYARRAYSIZE; i++)
	{
		if (enemyArray[i] != NULL)
		{
			delete enemyArray[i];
			enemyArray[i] = NULL;
		}
	}
	for (int i = 0; i < ENEMYBULLETARRAYSIZE; i++)
	{
		if (enemyBulletArray[i] != NULL)
		{
			delete enemyBulletArray[i];
			enemyBulletArray[i] = NULL;
		}
	
	}
	for (int i = 0; i < ASTEROIDARRAYSIZE; i++)
	{
		if (asteroidArray[i] != NULL)
		{
			delete asteroidArray[i];
			asteroidArray[i] = NULL;
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
	delete titleText;
	delete pressSpaceToStartText;
	delete gameOverText;
	delete pressSpaceToRestartText;
	delete shootBuffer;
	delete shootSound;
	delete backgroundMusic;
	delete enemyShootBuffer;
	delete enemyShootSound;
	delete playerExplotionBuffer;
	delete playerExplotionSound;
	delete enemyExplotionBuffer;
	delete enemyExplotionSound;
	delete asteroidBuffer;
	delete asteroidSound;
	DeleteEntitis();
	//La computadora da un error que dice: "no se encontro delete_array.cpp"

	/*delete[] bulletArray;
	delete[] enemyArray;
	delete[] enemyBulletArray;
	delete[] asteroidArray;*/

}
