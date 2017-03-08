#include "SPlaying.h"

#include <iostream>
#include <SFML/System/Clock.hpp>

#include "RMaster.h"
#include "Camera.h"
#include <iostream>

namespace State
{
	//en créant l'appli, on crée un objet playing qui aura en argument l'appli, chargera la texture, et l'appliquera sur le cube
	Playing::Playing(Application& application)
		: Game_State(application)
		, m_texture("Texture_Atlas", 512, 16)
		, m_quad(m_texture),
		m_quad2(m_texture),
		m_noise()
	{
		//m_texture.bind();

		
		m_noise.setBound(0, 0);
		m_quad.position.z -= 5;
		m_quad2.position.z -= 5;
		m_quad2.position.x -= 1;
		m_quad.position.y = (float)(int) (m_noise.getPositionY(0,0)*10);
		m_quad2.position.y = (float)(int)(m_noise.getPositionY(1, 0) * 10);
		std::cout << m_quad.position.y;
	}

	void Playing::input(Camera& camera)
	{

	}

	void Playing::update(Camera& camera, float dt)
	{
	//	m_quad.rotation += .5;
		
		//on appelle les input de la camera
		camera.input(dt);
	}

	void Playing::draw(Renderer::Master& renderer)
	{
		renderer.draw(m_quad);
		renderer.draw(m_quad2);
	}
}