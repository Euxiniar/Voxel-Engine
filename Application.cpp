#include "Application.h"
#include "Display.h"
#include "Playing.h"

Application::Application()
{
	//On cr�e un objet playing qu'on stock dans un stack de type game_state (playing h�rite de Game_State)
	pushState(std::make_unique<State::Playing>(*this));
}

void Application::runMainGameLoop()
{
	sf::Clock clock;

	//tant que la fen�tre est ouverte
	while (Display::isOpen())
	{
		//temps �coul� a chaque execution de la boucle
		auto dt = clock.restart().asSeconds();

		//on efface l'�cran
		m_renderer.clear();

		//On s�lectionne le Last In et on appelle les fonctions inputs update et draw
		//(les fonctions appel�es seront celles des enfants de Game_State
		m_states.top()->input(camera);
		m_states.top()->update(camera, dt);
		m_states.top()->draw(m_renderer);

		//On rafraichit le contexte OpenGL
		m_renderer.update(camera);

		//On regarde si on doit fermer
		Display::CheckForClose();

	}
}

void Application::pushState(std::unique_ptr<State::Game_State> state)
{
	//on ajoute l'application et son contenu (grace � move) dans le stack m_states
	m_states.push(std::move(state));
}

void Application::popState()
{
	m_states.pop();
}
