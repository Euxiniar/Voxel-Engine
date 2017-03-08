#include "Display.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>

namespace Display
{
	std::unique_ptr<sf::RenderWindow> window;

	void Display::create(std::string title)
	{
		//on choisi les paramètres à appliquer a notre fenêtre
		sf::ContextSettings settings;
		settings.depthBits = 24;
		settings.majorVersion = 3;
		settings.minorVersion = 3;
		
		//On crée notre fenêtre
		window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT/*sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height*/),
			title, 
			sf::Style::Close, 
			settings);

		//on initialise glew pour pouvoir utiliser OpenGL
		glewInit();
		glViewport(0, 0, WIDTH, HEIGHT);//sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);

		//permet qu'il n'y ait pas d'errer de superposition des faces
		glEnable(GL_DEPTH_TEST);

		//permet d'afficher uniquement les faces que l'on voit
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
		glFrontFace(GL_CW);

		window->setMouseCursorVisible(false);
		window->setFramerateLimit(60);
		window->setVerticalSyncEnabled(true);
	}


	void Display::close()
	{
		//Fermeture de la fenêtre et de tous les éléments qui y sont associés
		window->close();
	}

	void clear()
	{
		//effaçage du contexte OpenGL et vidage des buffers
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	}

	void update()
	{
		//rafraichissement de la fenêtre
		window->display();
	}

	void CheckForClose()
	{
		//Si la croix est appuyée, on appelle la fonction de fermeture
		sf::Event ev;
		while(window->pollEvent(ev))
			if (ev.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				close();
			}
	}

	bool isOpen()
	{
		//retourne l'état de la fenêtre
		return window->isOpen();
	}

	const sf::Window& get()
	{
		return *window;
	}

	bool isSelect()
	{
		
		return window->hasFocus();
	}
}