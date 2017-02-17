#pragma once
#include <vector>
#include "Simple_Shader.h"
#include <SFML/System/Clock.hpp>

class Quad;
struct Entity;

namespace Renderer
{
	class Simple
	{
		public: 
			void draw(const Quad& quad);
			void update(const Entity& camera);

		private:
			void prepare(const Quad& quad);

			std::vector<const Quad *> m_quads;

			Shader::Simple_Shader m_shader;

			sf::Clock m_clock;
	};
}
