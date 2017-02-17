#pragma once

#include "Game_State.h"
#include "Model.h"
#include "Simple_Shader.h"
#include "Texture.h"
#include "Quad.h"

class Application; 

namespace State
{
	class Playing : public Game_State
	{
		public:
			Playing(Application & application);

			void input	(Entity& camera) override;
			void update	(Entity& camera) override;
			void draw	(Renderer::Master& renderer) override;

		private:
			Shader::Simple_Shader m_shader;
			Texture::Basic_Texture m_texture;
			Quad m_quad;
	};
}