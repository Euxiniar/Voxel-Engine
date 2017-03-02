#include "Application.h"
#include "Display.h"
#include "SPlaying.h"
#include "Random_Maths.h"
#include <iostream>

Application::Application()
{
	init();
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

		//si le temps de la chnson est fini
		if (m_songTimer.getElapsedTime() > m_songDuration)
			resetSong();

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

void Application::resetSong()
{
	static std::string songFIlesPath = "Data/Music/";
	static std::vector<std::string> songNames =
	{
		"Game_of_Thrones",
		"Doctor_Who",
	};

	static auto lastSong = songNames.size();
	auto thisSong = lastSong;

	while (thisSong == lastSong)
		thisSong = Random::integer(0, songNames.size()-1);

	lastSong = thisSong;
	m_song.openFromFile(songFIlesPath + songNames[thisSong] + ".ogg");
	m_song.play();
	m_songDuration = m_song.getDuration();
	m_songTimer.restart();
	m_song.setVolume(5);
}

void Application::init()
{
	//Start the music
	resetSong();
}
