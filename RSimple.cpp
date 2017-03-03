#include "RSimple.h"
#include "Quad.h"
#include "Matrix_Maths.h"

namespace Renderer
{

	void Simple::draw(const Quad & quad)
	{
		m_quads.push_back(&quad);
	}

	void Simple::update(const Camera& camera)
	{
		m_shader.bind();
		//on rempli la variable de temps du shader avec la vleur du temps
		m_shader.setTime(m_clock.getElapsedTime().asSeconds());

		//on passe la matrice de vue au shader (donc la camera)
		m_shader.setViewMatrix(Maths::createViewMatrix(camera));

		for (auto& quad : m_quads) //TODO comprendre cette ligne
		{
			prepare(*quad);
			glDrawElements(GL_TRIANGLES, quad->getModel().getIndicesCount(), GL_UNSIGNED_INT, nullptr);
		}
		m_quads.clear();
	}

	void Simple::prepare(const Quad & quad)
	{
		quad.getModel().bind(); //on récupère le model
		//on envoie la matrice de models (les quads) au shader
		m_shader.setModelMatrix(Maths::createModelMatrix(quad));
	}
}