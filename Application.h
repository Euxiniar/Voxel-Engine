#pragma once
#include <stack>
#include <memory>

#include "Game_State.h"
#include "Master.h"
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
		Renderer::Master m_renderer;
		Camera camera;
};
