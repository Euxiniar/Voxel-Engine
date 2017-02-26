#include "Playing.h"

#include <iostream>
#include <SFML/System/Clock.hpp>

#include "Master.h"
#include "Camera.h"

namespace State
{
	//en créant l'appli, on crée un objet playing qui aura en argument l'appli, chargera la texture, et l'appliquera sur le cube
	Playing::Playing(Application& application)
		: Game_State(application)
		, m_texture("Texture_Atlas", 512, 16)
		, m_quad(m_texture)
	{
		m_texture.bind();

		m_quad.position.x -= 0;
	}

	void Playing::input(Camera& camera)
	{

	}

	void Playing::update(Camera& camera, float dt)
	{
		m_quad.rotation += .1;
		//on appelle les input de la camera
		camera.input(dt);
	}

	void Playing::draw(Renderer::Master& renderer)
	{
		renderer.draw(m_quad);
	}
}