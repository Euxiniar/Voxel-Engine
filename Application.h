#pragma once
#include <stack>
#include <memory>

#include "Game_State.h"
#include "RMaster.h"
#include "Entity.h"
#include "Camera.h"

class Application
{
	public:
		Application();
		

		void runMainGameLoop();
		void pushState(std::unique_ptr<State::Game_State> state);
		void popState();

	private:
		std::stack <std::unique_ptr<State::Game_State>> m_states;

		//on crée un objet de type Master
		Renderer::Master m_renderer;

		//on crée une caméra
		Camera camera;
};

