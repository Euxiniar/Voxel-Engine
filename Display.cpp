#include "Display.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>

namespace Display
{
	std::unique_ptr<sf::RenderWindow> window;

	void Display::init()
	{
		//on choisi les param�tres � appliquer a notre fen�tre
		sf::ContextSettings settings;
		settings.depthBits = 24;
		settings.majorVersion = 3;
		settings.minorVersion = 3;

		//On cr�e notre fen�tre
		window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), 
			"Window", 
			sf::Style::Close, 
			settings);

		//on initialise glew pour pouvoir utiliser OpenGL
		glewInit();
		glViewport(0, 0, WIDTH, HEIGHT);

		glEnable(GL_DEPTH_TEST);

		window->setMouseCursorVisible(false);
	}


	void Display::close()
	{
		//Fermeture de la fen�tre et de tous les �l�ments qui y sont associ�s
		window->close();
	}

	void clear()
	{
		//effa�age du contexte OpenGL et vidage des buffers
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	}

	void update()
	{
		//rafraichissement de la fen�tre
		window->display();
	}

	void CheckForClose()
	{
		//Si la croix est appuy�e, on appelle la fonction de fermeture
		sf::Event ev;
		while(window->pollEvent(ev))
			if (ev.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				close();
			}
	}

	bool isOpen()
	{
		//retourne l'�tat de la fen�tre
		return window->isOpen();
	}

	const sf::Window& get()
	{
		return *window;
	}
}