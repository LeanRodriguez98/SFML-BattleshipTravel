/*#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 600), "NoSeMeOcurreNingunNombre");
	
	Texture TexturaPersonajeBlanco;
	Texture TexturaPersonajeNegro;
	Texture TexturaMuroBlanco;
	Texture TexturaMuroNegro;
	Texture TexturaNexoBlanco;
	Texture TexturaNexoNegro;
	Texture TexturaEsferaBlanca;
	Texture TexturaEsferaNegra;
	Texture TexturaFondo;

	Font Fuente;

	if (!TexturaPersonajeBlanco.loadFromFile("personajeBlanco.png"))
	{
		cout << "No se pudo cargar la textura del personaje blanco" << endl;
		cout << "Presiona una tecla para salir" << endl;
		cin.get();
		return -1;
	}
	if (!TexturaPersonajeNegro.loadFromFile("personajeNegro.png"))
	{
		cout << "No se pudo cargar la textura del personaje negro" << endl;
		cout << "Presiona una tecla para salir" << endl;
		cin.get();
		return -1;
	}
	if (!TexturaMuroBlanco.loadFromFile("MuroBlanco.png"))
	{
		cout << "No se pudo cargar la textura del muro blanco" << endl;
		cout << "Presiona una tecla para salir" << endl;
		cin.get();
		return -1;
	}
	if (!TexturaMuroNegro.loadFromFile("MuroNegro.png"))
	{
		cout << "No se pudo cargar la textura del muro negro" << endl;
		cout << "Presiona una tecla para salir" << endl;
		cin.get();
		return -1;
	}
	if (!TexturaNexoBlanco.loadFromFile("NexoBlanco.png"))
	{
		cout << "No se pudo cargar la textura del nexo blanco" << endl;
		cout << "Presiona una tecla para salir" << endl;
		cin.get();
		return -1;
	}
	if (!TexturaNexoNegro.loadFromFile("NexoNegro.png"))
	{
		cout << "No se pudo cargar la textura del nexo negro" << endl;
		cout << "Presiona una tecla para salir" << endl;
		cin.get();
		return -1;
	}
	if (!TexturaEsferaBlanca.loadFromFile("EsferaBlanca.png"))
	{
		cout << "No se pudo cargar la textura de la esfera blanca" << endl;
		cout << "Presiona una tecla para salir" << endl;
		cin.get();
		return -1;
	}
	if (!TexturaEsferaNegra.loadFromFile("EsferaNegra.png"))
	{
		cout << "No se pudo cargar la textura del esfera negra" << endl;
		cout << "Presiona una tecla para salir" << endl;
		cin.get();
		return -1;
	}
	if (!TexturaFondo.loadFromFile("fondo.png"))
	{
		cout << "No se pudo cargar la textura del fondo" << endl;
		cout << "Presiona una tecla para salir" << endl;
		cin.get();
		return -1;
	}

	if (!Fuente.loadFromFile("coolvetica rg.ttf"))
	{
		cout << "No se pudo cargar la fuente" << endl;
		cout << "Presiona una tecla para salir" << endl;
		cin.get();
		return -1;
	}

	Sprite SpritePrsonajeBlanco;
	Sprite SpritePrsonajeNegro;
	Sprite SpriteMuroBlanco;
	Sprite SpriteMuroNegro;
	Sprite SpriteNexoBlanco;
	Sprite SpriteNexoNegro;
	Sprite SpriteEsferaBlanca1;
	Sprite SpriteEsferaBlanca2;
	Sprite SpriteEsferaBlanca3;
	Sprite SpriteEsferaBlanca4;
	Sprite SpriteEsferaBlanca5;
	Sprite SpriteEsferaNegra1;
	Sprite SpriteEsferaNegra2;
	Sprite SpriteEsferaNegra3;
	Sprite SpriteEsferaNegra4;
	Sprite SpriteEsferaNegra5;
	Sprite SpriteFondo;

	Text TextoPuntajeBlanco("Puntaje: ",Fuente,30);
	Text TextoPuntajeNegro("Puntaje: ",Fuente,30);
	Text TextoVictoriaBlanco("El  jugador blanco es\n		 el ganador", Fuente,30);
	Text TextoVictoriaNegro("El  jugador negro es\n		 el ganador", Fuente, 30);
	Text TextoReiniciar("Pulsa R para \n	reiniciar",Fuente,30);
	Text TextoSalir("Pulsa Escape \n	para salir", Fuente, 30);
	Text EMP("EMP", Fuente, 30);
	Text ATE("ATE", Fuente, 30);
	Text Inicio1("Pusla Enter p", Fuente, 30);
	Text Inicio2("ara comenzar", Fuente, 30);
	Text ControlesBlanco("Controles: \nMovimiento del \npersonaje \nA - Arriba \nZ - Abajo\nMovimiento del \nEscudo\nS - Arriba\nX - Abajo \nDisparos \nQ \nW \nE \nD \nC ", Fuente, 30);
	Text ControlesNegro("		 Controles: \nMovimiento del \n		  personaje \n		   6 - Arriba \n			3 - Abajo\nMovimiento del \n			  Escudo\n		   5 - Arriba\n		    2 - Abajo \n		    Disparos \n						  9 \n						  8 \n						  7 \n						  4 \n						  1", Fuente, 30);
	Text PuntosP1("El primer jugador e\n					 sera el", Fuente, 30);
	Text PuntosP2("n juntar 20 puntos \nganador", Fuente, 30);

	TextoPuntajeBlanco.setFillColor(Color::White);
	TextoPuntajeNegro.setFillColor(Color::Black);
	TextoVictoriaBlanco.setFillColor(Color::White);
	TextoVictoriaNegro.setFillColor(Color::Black);
	TextoReiniciar.setFillColor(Color::White);
	TextoSalir.setFillColor(Color::Black);
	EMP.setFillColor(Color::White);
	ATE.setFillColor(Color::Black);
	ControlesBlanco.setFillColor(Color::White);
	ControlesNegro.setFillColor(Color::Black);
	Inicio1.setFillColor(Color::White);
	Inicio2.setFillColor(Color::Black);
	PuntosP1.setFillColor(Color::White);
	PuntosP2.setFillColor(Color::Black);

	SpritePrsonajeBlanco.setTexture(TexturaPersonajeBlanco);
	SpritePrsonajeNegro.setTexture(TexturaPersonajeNegro);
	SpriteMuroBlanco.setTexture(TexturaMuroBlanco);
	SpriteMuroNegro.setTexture(TexturaMuroNegro);
	SpriteNexoBlanco.setTexture(TexturaNexoBlanco);
	SpriteNexoNegro.setTexture(TexturaNexoNegro);
	SpriteEsferaBlanca1.setTexture(TexturaEsferaBlanca);
	SpriteEsferaBlanca2.setTexture(TexturaEsferaBlanca);
	SpriteEsferaBlanca3.setTexture(TexturaEsferaBlanca);
	SpriteEsferaBlanca4.setTexture(TexturaEsferaBlanca);
	SpriteEsferaBlanca5.setTexture(TexturaEsferaBlanca);
	SpriteEsferaNegra1.setTexture(TexturaEsferaNegra);
	SpriteEsferaNegra2.setTexture(TexturaEsferaNegra);
	SpriteEsferaNegra3.setTexture(TexturaEsferaNegra);
	SpriteEsferaNegra4.setTexture(TexturaEsferaNegra);
	SpriteEsferaNegra5.setTexture(TexturaEsferaNegra);
	SpriteFondo.setTexture(TexturaFondo);

	SpriteFondo.setPosition(0, 0);
	SpriteNexoBlanco.setPosition(15, 40);
	SpriteNexoNegro.setPosition(680, 40);
	SpriteMuroBlanco.setPosition(119, 40);
	SpriteMuroNegro.setPosition(581, 40);
	SpritePrsonajeBlanco.setPosition(25, 35);
	SpritePrsonajeNegro.setPosition(596, 35);

	TextoPuntajeBlanco.setPosition(150, 550);
	TextoPuntajeNegro.setPosition(420, 550);
	TextoVictoriaBlanco.setPosition(80, 150);
	TextoVictoriaNegro.setPosition(380, 150);
	TextoReiniciar.setPosition(120, 300);
	TextoSalir.setPosition(420, 300);
	EMP.setPosition(295, 200);
	ATE.setPosition(350, 200);
	ControlesBlanco.setPosition(50, 30);
	ControlesNegro.setPosition(450, 30);
	Inicio1.setPosition(180, 390);
	Inicio2.setPosition(350, 390);
	PuntosP1.setPosition(113, 480);
	PuntosP2.setPosition(350, 480);


	bool BoolEsferaBlanca1 = false;
	bool BoolEsferaBlanca2 = false;
	bool BoolEsferaBlanca3 = false;
	bool BoolEsferaBlanca4 = false;
	bool BoolEsferaBlanca5 = false;

	bool BoolEsferaNegra1 = false;
	bool BoolEsferaNegra2 = false;
	bool BoolEsferaNegra3 = false;
	bool BoolEsferaNegra4 = false;
	bool BoolEsferaNegra5 = false;

	bool VictoriaBlanco = false;
	bool VictoriaNegro = false;

	bool Menu = true;

	int TimerEsferaBlanca1 = 200;
	int TimerEsferaBlanca2 = 200;
	int TimerEsferaBlanca3 = 200;
	int TimerEsferaBlanca4 = 200;
	int TimerEsferaBlanca5 = 200;

	int TimerEsferaNegra1 = 200;
	int TimerEsferaNegra2 = 200;
	int TimerEsferaNegra3 = 200;
	int TimerEsferaNegra4 = 200;
	int TimerEsferaNegra5 = 200;

	int StunPersonajeBlanco = 0;
	int StunPersonajeNegro = 0;

	int PuntajeBlanco = 0;
	int PuntajeNegro = 0;

	int velocidadEsferas = 5;
	int velocidadPersonajes = 4;
	int velocidadMuros = 3;

	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		if (Menu == false)
		{			
			if (VictoriaBlanco == false && VictoriaNegro == false)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && SpritePrsonajeBlanco.getPosition().y >= 40 && StunPersonajeBlanco == 0)
				{
					SpritePrsonajeBlanco.move(0, velocidadPersonajes *-1);
					//cout<<"p b U"<<endl;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && SpritePrsonajeBlanco.getPosition().y <= 478 && StunPersonajeBlanco == 0)
				{
					SpritePrsonajeBlanco.move(0, velocidadPersonajes);
					//cout << "p b D" << endl;

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6) && SpritePrsonajeNegro.getPosition().y >= 40 && StunPersonajeNegro == 0)
				{
					SpritePrsonajeNegro.move(0, velocidadPersonajes *-1);
					//cout << "p n U" << endl;

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3) && SpritePrsonajeNegro.getPosition().y <= 478 && StunPersonajeNegro == 0)
				{
					SpritePrsonajeNegro.move(0, velocidadPersonajes);
					//cout << "p n D" << endl;

				}


				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && SpriteMuroBlanco.getPosition().y >= 40)
				{
					SpriteMuroBlanco.move(0, velocidadMuros *-1);
					//cout << "m b U" << endl;

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && SpriteMuroBlanco.getPosition().y <= 500)
				{
					SpriteMuroBlanco.move(0, velocidadMuros);
					//cout << "m b D" << endl;

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5) && SpriteMuroNegro.getPosition().y >= 40)
				{
					SpriteMuroNegro.move(0, velocidadMuros *-1);
					//cout << "m n U" << endl;

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2) && SpriteMuroNegro.getPosition().y <= 500)
				{
					SpriteMuroNegro.move(0, velocidadMuros);
					//cout << "m n D" << endl;

				}


				if (Keyboard::isKeyPressed(Keyboard::Q) && TimerEsferaBlanca1 == 200 && StunPersonajeBlanco == 0)
				{
					SpriteEsferaBlanca1.setPosition(SpritePrsonajeBlanco.getPosition().x + 79, SpritePrsonajeBlanco.getPosition().y + 51);
					BoolEsferaBlanca1 = true;
					TimerEsferaBlanca1 = 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::W) && TimerEsferaBlanca2 == 200 && StunPersonajeBlanco == 0)
				{
					SpriteEsferaBlanca2.setPosition(SpritePrsonajeBlanco.getPosition().x + 79, SpritePrsonajeBlanco.getPosition().y + 51);
					BoolEsferaBlanca2 = true;
					TimerEsferaBlanca2 = 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::E) && TimerEsferaBlanca3 == 200 && StunPersonajeBlanco == 0)
				{
					SpriteEsferaBlanca3.setPosition(SpritePrsonajeBlanco.getPosition().x + 79, SpritePrsonajeBlanco.getPosition().y + 51);
					BoolEsferaBlanca3 = true;
					TimerEsferaBlanca3 = 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::D) && TimerEsferaBlanca4 == 200 && StunPersonajeBlanco == 0)
				{
					SpriteEsferaBlanca4.setPosition(SpritePrsonajeBlanco.getPosition().x + 79, SpritePrsonajeBlanco.getPosition().y + 51);
					BoolEsferaBlanca4 = true;
					TimerEsferaBlanca4 = 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::C) && TimerEsferaBlanca5 == 200 && StunPersonajeBlanco == 0)
				{
					SpriteEsferaBlanca5.setPosition(SpritePrsonajeBlanco.getPosition().x + 79, SpritePrsonajeBlanco.getPosition().y + 51);
					BoolEsferaBlanca5 = true;
					TimerEsferaBlanca5 = 0;
				}


				if (Keyboard::isKeyPressed(Keyboard::Numpad9) && TimerEsferaNegra1 == 200 && StunPersonajeNegro == 0)
				{
					SpriteEsferaNegra1.setPosition(SpritePrsonajeNegro.getPosition().x, SpritePrsonajeNegro.getPosition().y + 51);
					BoolEsferaNegra1 = true;
					TimerEsferaNegra1 = 0;

				}
				if (Keyboard::isKeyPressed(Keyboard::Numpad8) && TimerEsferaNegra2 == 200 && StunPersonajeNegro == 0)
				{
					SpriteEsferaNegra2.setPosition(SpritePrsonajeNegro.getPosition().x, SpritePrsonajeNegro.getPosition().y + 51);
					BoolEsferaNegra2 = true;
					TimerEsferaNegra2 = 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::Numpad7) && TimerEsferaNegra3 == 200 && StunPersonajeNegro == 0)
				{
					SpriteEsferaNegra3.setPosition(SpritePrsonajeNegro.getPosition().x, SpritePrsonajeNegro.getPosition().y + 51);
					BoolEsferaNegra3 = true;
					TimerEsferaNegra3 = 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::Numpad4) && TimerEsferaNegra4 == 200 && StunPersonajeNegro == 0)
				{
					SpriteEsferaNegra4.setPosition(SpritePrsonajeNegro.getPosition().x, SpritePrsonajeNegro.getPosition().y + 51);
					BoolEsferaNegra4 = true;
					TimerEsferaNegra4 = 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::Numpad1) && TimerEsferaNegra5 == 200 && StunPersonajeNegro == 0)
				{
					SpriteEsferaNegra5.setPosition(SpritePrsonajeNegro.getPosition().x, SpritePrsonajeNegro.getPosition().y + 51);
					BoolEsferaNegra5 = true;
					TimerEsferaNegra5 = 0;
				}


				if (BoolEsferaBlanca1 == true)
				{
					SpriteEsferaBlanca1.move(velocidadEsferas, 0);
				}
				if (BoolEsferaBlanca2 == true)
				{
					SpriteEsferaBlanca2.move(velocidadEsferas, 0);
				}
				if (BoolEsferaBlanca3 == true)
				{
					SpriteEsferaBlanca3.move(velocidadEsferas, 0);
				}
				if (BoolEsferaBlanca4 == true)
				{
					SpriteEsferaBlanca4.move(velocidadEsferas, 0);
				}
				if (BoolEsferaBlanca5 == true)
				{
					SpriteEsferaBlanca5.move(velocidadEsferas, 0);
				}


				if (BoolEsferaNegra1 == true)
				{
					SpriteEsferaNegra1.move(velocidadEsferas * -1, 0);
				}
				if (BoolEsferaNegra2 == true)
				{
					SpriteEsferaNegra2.move(velocidadEsferas * -1, 0);
				}
				if (BoolEsferaNegra3 == true)
				{
					SpriteEsferaNegra3.move(velocidadEsferas * -1, 0);
				}
				if (BoolEsferaNegra4 == true)
				{
					SpriteEsferaNegra4.move(velocidadEsferas * -1, 0);
				}
				if (BoolEsferaNegra5 == true)
				{
					SpriteEsferaNegra5.move(velocidadEsferas * -1, 0);
				}



				if (TimerEsferaBlanca1 < 200)
				{
					TimerEsferaBlanca1++;
				}
				if (TimerEsferaBlanca2 < 200)
				{
					TimerEsferaBlanca2++;
				}
				if (TimerEsferaBlanca3 < 200)
				{
					TimerEsferaBlanca3++;
				}
				if (TimerEsferaBlanca4 < 200)
				{
					TimerEsferaBlanca4++;
				}
				if (TimerEsferaBlanca5 < 200)
				{
					TimerEsferaBlanca5++;
				}



				if (TimerEsferaNegra1 < 200)
				{
					TimerEsferaNegra1++;
				}
				if (TimerEsferaNegra2 < 200)
				{
					TimerEsferaNegra2++;
				}
				if (TimerEsferaNegra3 < 200)
				{
					TimerEsferaNegra3++;
				}
				if (TimerEsferaNegra4 < 200)
				{
					TimerEsferaNegra4++;
				}
				if (TimerEsferaNegra5 < 200)
				{
					TimerEsferaNegra5++;
				}

				if (StunPersonajeBlanco > 0)
				{
					StunPersonajeBlanco--;
				}
				if (StunPersonajeNegro > 0)
				{
					StunPersonajeNegro--;
				}

				if ((SpriteEsferaBlanca1.getPosition().x + 15 >= SpriteMuroNegro.getPosition().x && SpriteEsferaBlanca1.getPosition().x <= SpriteMuroNegro.getPosition().x + 5) && (SpriteEsferaBlanca1.getPosition().y + 15 >= SpriteMuroNegro.getPosition().y && SpriteEsferaBlanca1.getPosition().y <= SpriteMuroNegro.getPosition().y + 80) && BoolEsferaBlanca1 == true)
				{
					BoolEsferaBlanca1 = false;
				}
				if ((SpriteEsferaBlanca2.getPosition().x + 15 >= SpriteMuroNegro.getPosition().x && SpriteEsferaBlanca2.getPosition().x <= SpriteMuroNegro.getPosition().x + 5) && (SpriteEsferaBlanca2.getPosition().y + 15 >= SpriteMuroNegro.getPosition().y && SpriteEsferaBlanca2.getPosition().y <= SpriteMuroNegro.getPosition().y + 80) && BoolEsferaBlanca2 == true)
				{
					BoolEsferaBlanca2 = false;
				}
				if ((SpriteEsferaBlanca3.getPosition().x + 15 >= SpriteMuroNegro.getPosition().x && SpriteEsferaBlanca3.getPosition().x <= SpriteMuroNegro.getPosition().x + 5) && (SpriteEsferaBlanca3.getPosition().y + 15 >= SpriteMuroNegro.getPosition().y && SpriteEsferaBlanca3.getPosition().y <= SpriteMuroNegro.getPosition().y + 80) && BoolEsferaBlanca3 == true)
				{
					BoolEsferaBlanca3 = false;
				}
				if ((SpriteEsferaBlanca4.getPosition().x + 15 >= SpriteMuroNegro.getPosition().x && SpriteEsferaBlanca4.getPosition().x <= SpriteMuroNegro.getPosition().x + 5) && (SpriteEsferaBlanca4.getPosition().y + 15 >= SpriteMuroNegro.getPosition().y && SpriteEsferaBlanca4.getPosition().y <= SpriteMuroNegro.getPosition().y + 80) && BoolEsferaBlanca4 == true)
				{
					BoolEsferaBlanca4 = false;
				}
				if ((SpriteEsferaBlanca5.getPosition().x + 15 >= SpriteMuroNegro.getPosition().x && SpriteEsferaBlanca5.getPosition().x <= SpriteMuroNegro.getPosition().x + 5) && (SpriteEsferaBlanca5.getPosition().y + 15 >= SpriteMuroNegro.getPosition().y && SpriteEsferaBlanca5.getPosition().y <= SpriteMuroNegro.getPosition().y + 80) && BoolEsferaBlanca5 == true)
				{
					BoolEsferaBlanca5 = false;
				}

				if ((SpriteEsferaNegra1.getPosition().x + 15 >= SpriteMuroBlanco.getPosition().x && SpriteEsferaNegra1.getPosition().x <= SpriteMuroBlanco.getPosition().x + 5) && (SpriteEsferaNegra1.getPosition().y + 15 >= SpriteMuroBlanco.getPosition().y && SpriteEsferaNegra1.getPosition().y <= SpriteMuroBlanco.getPosition().y + 80) && BoolEsferaNegra1 == true)
				{
					BoolEsferaNegra1 = false;
				}
				if ((SpriteEsferaNegra2.getPosition().x + 15 >= SpriteMuroBlanco.getPosition().x && SpriteEsferaNegra2.getPosition().x <= SpriteMuroBlanco.getPosition().x + 5) && (SpriteEsferaNegra2.getPosition().y + 15 >= SpriteMuroBlanco.getPosition().y && SpriteEsferaNegra2.getPosition().y <= SpriteMuroBlanco.getPosition().y + 80) && BoolEsferaNegra2 == true)
				{
					BoolEsferaNegra2 = false;
				}
				if ((SpriteEsferaNegra3.getPosition().x + 15 >= SpriteMuroBlanco.getPosition().x && SpriteEsferaNegra3.getPosition().x <= SpriteMuroBlanco.getPosition().x + 5) && (SpriteEsferaNegra3.getPosition().y + 15 >= SpriteMuroBlanco.getPosition().y && SpriteEsferaNegra3.getPosition().y <= SpriteMuroBlanco.getPosition().y + 80) && BoolEsferaNegra3 == true)
				{
					BoolEsferaNegra3 = false;
				}
				if ((SpriteEsferaNegra4.getPosition().x + 15 >= SpriteMuroBlanco.getPosition().x && SpriteEsferaNegra4.getPosition().x <= SpriteMuroBlanco.getPosition().x + 5) && (SpriteEsferaNegra4.getPosition().y + 15 >= SpriteMuroBlanco.getPosition().y && SpriteEsferaNegra4.getPosition().y <= SpriteMuroBlanco.getPosition().y + 80) && BoolEsferaNegra4 == true)
				{
					BoolEsferaNegra4 = false;
				}
				if ((SpriteEsferaNegra5.getPosition().x + 15 >= SpriteMuroBlanco.getPosition().x && SpriteEsferaNegra5.getPosition().x <= SpriteMuroBlanco.getPosition().x + 5) && (SpriteEsferaNegra5.getPosition().y + 15 >= SpriteMuroBlanco.getPosition().y && SpriteEsferaNegra5.getPosition().y <= SpriteMuroBlanco.getPosition().y + 80) && BoolEsferaNegra5 == true)
				{
					BoolEsferaNegra5 = false;
				}



				if ((SpriteEsferaBlanca1.getPosition().x + 15 >= SpritePrsonajeNegro.getPosition().x && SpriteEsferaBlanca1.getPosition().x <= SpritePrsonajeNegro.getPosition().x + 79) && (SpriteEsferaBlanca1.getPosition().y + 15 >= SpritePrsonajeNegro.getPosition().y && SpriteEsferaBlanca1.getPosition().y <= SpritePrsonajeNegro.getPosition().y + 102) && BoolEsferaBlanca1 == true)
				{
					BoolEsferaBlanca1 = false;
					StunPersonajeNegro = StunPersonajeNegro + 200;
				}
				if ((SpriteEsferaBlanca2.getPosition().x + 15 >= SpritePrsonajeNegro.getPosition().x && SpriteEsferaBlanca2.getPosition().x <= SpritePrsonajeNegro.getPosition().x + 79) && (SpriteEsferaBlanca2.getPosition().y + 15 >= SpritePrsonajeNegro.getPosition().y && SpriteEsferaBlanca2.getPosition().y <= SpritePrsonajeNegro.getPosition().y + 102) && BoolEsferaBlanca2 == true)
				{
					BoolEsferaBlanca2 = false;
					StunPersonajeNegro = StunPersonajeNegro + 200;
				}
				if ((SpriteEsferaBlanca3.getPosition().x + 15 >= SpritePrsonajeNegro.getPosition().x && SpriteEsferaBlanca3.getPosition().x <= SpritePrsonajeNegro.getPosition().x + 79) && (SpriteEsferaBlanca3.getPosition().y + 15 >= SpritePrsonajeNegro.getPosition().y && SpriteEsferaBlanca3.getPosition().y <= SpritePrsonajeNegro.getPosition().y + 102) && BoolEsferaBlanca3 == true)
				{
					BoolEsferaBlanca3 = false;
					StunPersonajeNegro = StunPersonajeNegro + 200;
				}
				if ((SpriteEsferaBlanca4.getPosition().x + 15 >= SpritePrsonajeNegro.getPosition().x && SpriteEsferaBlanca4.getPosition().x <= SpritePrsonajeNegro.getPosition().x + 79) && (SpriteEsferaBlanca4.getPosition().y + 15 >= SpritePrsonajeNegro.getPosition().y && SpriteEsferaBlanca4.getPosition().y <= SpritePrsonajeNegro.getPosition().y + 102) && BoolEsferaBlanca4 == true)
				{
					BoolEsferaBlanca4 = false;
					StunPersonajeNegro = StunPersonajeNegro + 200;
				}
				if ((SpriteEsferaBlanca5.getPosition().x + 15 >= SpritePrsonajeNegro.getPosition().x && SpriteEsferaBlanca5.getPosition().x <= SpritePrsonajeNegro.getPosition().x + 79) && (SpriteEsferaBlanca5.getPosition().y + 15 >= SpritePrsonajeNegro.getPosition().y && SpriteEsferaBlanca5.getPosition().y <= SpritePrsonajeNegro.getPosition().y + 102) && BoolEsferaBlanca5 == true)
				{
					BoolEsferaBlanca5 = false;
					StunPersonajeNegro = StunPersonajeNegro + 200;
				}

				if ((SpriteEsferaNegra1.getPosition().x + 15 >= SpritePrsonajeBlanco.getPosition().x && SpriteEsferaNegra1.getPosition().x <= SpritePrsonajeBlanco.getPosition().x + 79) && (SpriteEsferaNegra1.getPosition().y + 15 >= SpritePrsonajeBlanco.getPosition().y && SpriteEsferaNegra1.getPosition().y <= SpritePrsonajeBlanco.getPosition().y + 102) && BoolEsferaNegra1 == true)
				{
					BoolEsferaNegra1 = false;
					StunPersonajeBlanco = StunPersonajeBlanco + 200;
				}
				if ((SpriteEsferaNegra2.getPosition().x + 15 >= SpritePrsonajeBlanco.getPosition().x && SpriteEsferaNegra2.getPosition().x <= SpritePrsonajeBlanco.getPosition().x + 79) && (SpriteEsferaNegra2.getPosition().y + 15 >= SpritePrsonajeBlanco.getPosition().y && SpriteEsferaNegra2.getPosition().y <= SpritePrsonajeBlanco.getPosition().y + 102) && BoolEsferaNegra2 == true)
				{
					BoolEsferaNegra2 = false;
					StunPersonajeBlanco = StunPersonajeBlanco + 200;
				}
				if ((SpriteEsferaNegra3.getPosition().x + 15 >= SpritePrsonajeBlanco.getPosition().x && SpriteEsferaNegra3.getPosition().x <= SpritePrsonajeBlanco.getPosition().x + 79) && (SpriteEsferaNegra3.getPosition().y + 15 >= SpritePrsonajeBlanco.getPosition().y && SpriteEsferaNegra3.getPosition().y <= SpritePrsonajeBlanco.getPosition().y + 102) && BoolEsferaNegra3 == true)
				{
					BoolEsferaNegra3 = false;
					StunPersonajeBlanco = StunPersonajeBlanco + 200;
				}
				if ((SpriteEsferaNegra4.getPosition().x + 15 >= SpritePrsonajeBlanco.getPosition().x && SpriteEsferaNegra4.getPosition().x <= SpritePrsonajeBlanco.getPosition().x + 79) && (SpriteEsferaNegra4.getPosition().y + 15 >= SpritePrsonajeBlanco.getPosition().y && SpriteEsferaNegra4.getPosition().y <= SpritePrsonajeBlanco.getPosition().y + 102) && BoolEsferaNegra4 == true)
				{
					BoolEsferaNegra4 = false;
					StunPersonajeBlanco = StunPersonajeBlanco + 200;
				}
				if ((SpriteEsferaNegra5.getPosition().x + 15 >= SpritePrsonajeBlanco.getPosition().x && SpriteEsferaNegra5.getPosition().x <= SpritePrsonajeBlanco.getPosition().x + 79) && (SpriteEsferaNegra5.getPosition().y + 15 >= SpritePrsonajeBlanco.getPosition().y && SpriteEsferaNegra5.getPosition().y <= SpritePrsonajeBlanco.getPosition().y + 102) && BoolEsferaNegra5 == true)
				{
					BoolEsferaNegra5 = false;
					StunPersonajeBlanco = StunPersonajeBlanco + 200;
				}

				if (SpriteEsferaBlanca1.getPosition().x + 15 >= SpriteNexoNegro.getPosition().x && BoolEsferaBlanca1 == true)
				{
					BoolEsferaBlanca1 = false;
					PuntajeBlanco++;
				}
				if (SpriteEsferaBlanca2.getPosition().x + 15 >= SpriteNexoNegro.getPosition().x && BoolEsferaBlanca2 == true)
				{
					BoolEsferaBlanca2 = false;
					PuntajeBlanco++;
				}
				if (SpriteEsferaBlanca3.getPosition().x + 15 >= SpriteNexoNegro.getPosition().x && BoolEsferaBlanca3 == true)
				{
					BoolEsferaBlanca3 = false;
					PuntajeBlanco++;
				}
				if (SpriteEsferaBlanca4.getPosition().x + 15 >= SpriteNexoNegro.getPosition().x && BoolEsferaBlanca4 == true)
				{
					BoolEsferaBlanca4 = false;
					PuntajeBlanco++;
				}
				if (SpriteEsferaBlanca5.getPosition().x + 15 >= SpriteNexoNegro.getPosition().x && BoolEsferaBlanca5 == true)
				{
					BoolEsferaBlanca5 = false;
					PuntajeBlanco++;
				}

				if (SpriteEsferaNegra1.getPosition().x <= SpriteNexoBlanco.getPosition().x + 5 && BoolEsferaNegra1 == true)
				{
					BoolEsferaNegra1 = false;
					PuntajeNegro++;
				}
				if (SpriteEsferaNegra2.getPosition().x <= SpriteNexoBlanco.getPosition().x + 5 && BoolEsferaNegra2 == true)
				{
					BoolEsferaNegra2 = false;
					PuntajeNegro++;
				}
				if (SpriteEsferaNegra3.getPosition().x <= SpriteNexoBlanco.getPosition().x + 5 && BoolEsferaNegra3 == true)
				{
					BoolEsferaNegra3 = false;
					PuntajeNegro++;
				}
				if (SpriteEsferaNegra4.getPosition().x <= SpriteNexoBlanco.getPosition().x + 5 && BoolEsferaNegra4 == true)
				{
					BoolEsferaNegra4 = false;
					PuntajeNegro++;
				}
				if (SpriteEsferaNegra5.getPosition().x <= SpriteNexoBlanco.getPosition().x + 5 && BoolEsferaNegra5 == true)
				{
					BoolEsferaNegra5 = false;
					PuntajeNegro++;
				}

				if (PuntajeBlanco == 20)
				{
					VictoriaBlanco = true;
				}
				if (PuntajeNegro == 20)
				{
					VictoriaNegro = true;
				}
			}
		}
			sf::Event event;
			while (window.pollEvent(event))
			{				
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
				}
			}


		window.clear(sf::Color::Black);

		window.draw(SpriteFondo);
		if (Menu == true)
		{
			window.draw(ControlesBlanco);
			window.draw(ControlesNegro);
			window.draw(Inicio1);
			window.draw(Inicio2);
			window.draw(PuntosP1);
			window.draw(PuntosP2);

			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				Menu = false;
			}

		}
		if (Menu == false)
		{
			window.draw(SpriteNexoBlanco);
			window.draw(SpriteNexoNegro);
			window.draw(SpritePrsonajeBlanco);
			window.draw(SpritePrsonajeNegro);
			window.draw(SpriteMuroNegro);
			window.draw(SpriteMuroBlanco);

			if (BoolEsferaBlanca1 == true)
			{
				window.draw(SpriteEsferaBlanca1);
			}
			if (BoolEsferaBlanca2 == true)
			{
				window.draw(SpriteEsferaBlanca2);
			}
			if (BoolEsferaBlanca3 == true)
			{
				window.draw(SpriteEsferaBlanca3);
			}
			if (BoolEsferaBlanca4 == true)
			{
				window.draw(SpriteEsferaBlanca4);
			}
			if (BoolEsferaBlanca5 == true)
			{
				window.draw(SpriteEsferaBlanca5);
			}

			if (BoolEsferaNegra1 == true)
			{
				window.draw(SpriteEsferaNegra1);
			}
			if (BoolEsferaNegra2 == true)
			{
				window.draw(SpriteEsferaNegra2);
			}
			if (BoolEsferaNegra3 == true)
			{
				window.draw(SpriteEsferaNegra3);
			}
			if (BoolEsferaNegra4 == true)
			{
				window.draw(SpriteEsferaNegra4);
			}
			if (BoolEsferaNegra5 == true)
			{
				window.draw(SpriteEsferaNegra5);
			}

			Text PuntuacionBlanco(to_string(PuntajeBlanco), Fuente, 30);
			Text PuntuacionNegro(to_string(PuntajeNegro), Fuente, 30);

			PuntuacionBlanco.setFillColor(Color::White);
			PuntuacionNegro.setFillColor(Color::Black);

			PuntuacionBlanco.setPosition(255, 550);
			PuntuacionNegro.setPosition(525, 550);

			window.draw(TextoPuntajeBlanco);
			window.draw(TextoPuntajeNegro);
			window.draw(PuntuacionBlanco);
			window.draw(PuntuacionNegro);

			if (VictoriaBlanco == true && VictoriaNegro == false)
			{
				window.draw(TextoVictoriaBlanco);
			}
			if (VictoriaNegro == true && VictoriaBlanco == false)
			{
				window.draw(TextoVictoriaNegro);
			}

			if ((VictoriaBlanco == true || VictoriaNegro == true) && !(VictoriaBlanco == true && VictoriaNegro == true))
			{
				window.draw(TextoReiniciar);
				window.draw(TextoSalir);
				if (Keyboard::isKeyPressed(Keyboard::R))
				{
					BoolEsferaBlanca1 = false;
					BoolEsferaBlanca2 = false;
					BoolEsferaBlanca3 = false;
					BoolEsferaBlanca4 = false;
					BoolEsferaBlanca5 = false;

					BoolEsferaNegra1 = false;
					BoolEsferaNegra2 = false;
					BoolEsferaNegra3 = false;
					BoolEsferaNegra4 = false;
					BoolEsferaNegra5 = false;

					VictoriaBlanco = false;
					VictoriaNegro = false;

					TimerEsferaBlanca1 = 200;
					TimerEsferaBlanca2 = 200;
					TimerEsferaBlanca3 = 200;
					TimerEsferaBlanca4 = 200;
					TimerEsferaBlanca5 = 200;

					TimerEsferaNegra1 = 200;
					TimerEsferaNegra2 = 200;
					TimerEsferaNegra3 = 200;
					TimerEsferaNegra4 = 200;
					TimerEsferaNegra5 = 200;

					StunPersonajeBlanco = 0;
					StunPersonajeNegro = 0;

					PuntajeBlanco = 0;
					PuntajeNegro = 0;

					SpriteMuroBlanco.setPosition(119, 40);
					SpriteMuroNegro.setPosition(581, 40);
					SpritePrsonajeBlanco.setPosition(25, 35);
					SpritePrsonajeNegro.setPosition(596, 35);
				}
			}

			if (VictoriaBlanco == true && VictoriaNegro == true)
			{
				window.draw(EMP);
				window.draw(ATE);

				window.draw(TextoReiniciar);
				window.draw(TextoSalir);
				if (Keyboard::isKeyPressed(Keyboard::R))
				{
					BoolEsferaBlanca1 = false;
					BoolEsferaBlanca2 = false;
					BoolEsferaBlanca3 = false;
					BoolEsferaBlanca4 = false;
					BoolEsferaBlanca5 = false;

					BoolEsferaNegra1 = false;
					BoolEsferaNegra2 = false;
					BoolEsferaNegra3 = false;
					BoolEsferaNegra4 = false;
					BoolEsferaNegra5 = false;

					VictoriaBlanco = false;
					VictoriaNegro = false;

					TimerEsferaBlanca1 = 200;
					TimerEsferaBlanca2 = 200;
					TimerEsferaBlanca3 = 200;
					TimerEsferaBlanca4 = 200;
					TimerEsferaBlanca5 = 200;

					TimerEsferaNegra1 = 200;
					TimerEsferaNegra2 = 200;
					TimerEsferaNegra3 = 200;
					TimerEsferaNegra4 = 200;
					TimerEsferaNegra5 = 200;

					StunPersonajeBlanco = 0;
					StunPersonajeNegro = 0;

					PuntajeBlanco = 0;
					PuntajeNegro = 0;

					SpriteMuroBlanco.setPosition(119, 40);
					SpriteMuroNegro.setPosition(581, 40);
					SpritePrsonajeBlanco.setPosition(25, 35);
					SpritePrsonajeNegro.setPosition(596, 35);
				}
			}
		}
		window.display();
	}

	return 0;
}*/


#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Game.h"
using namespace std;
using namespace sf;
int main() {
	
	Game * game;
	game = new Game(Vector2i(800, 600), "BattleshipTravel");
	return 0;
}