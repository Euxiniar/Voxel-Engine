#include "Application.h"
#include "Display.h"
#include "Playing.h"

Application::Application()
{
	//On crée un objet playing qu'on stock dans un stack de type game_state (playing hérite de Game_State)
	pushState(std::make_unique<State::Playing>(*this));
}

void Application::runMainGameLoop()
{
	sf::Clock clock;

	//tant que la fenêtre est ouverte
	while (Display::isOpen())
	{
		//temps écoulé a chaque execution de la boucle
		auto dt = clock.restart().asSeconds();

		//on efface l'écran
		m_renderer.clear();

		//On sélectionne le Last In et on appelle les fonctions inputs update et draw
		//(les fonctions appelées seront celles des enfants de Game_State
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
	//on ajoute l'application et son contenu (grace à move) dans le stack m_states
	m_states.push(std::move(state));
}

void Application::popState()
{
	m_states.pop();
}
