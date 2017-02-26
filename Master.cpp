#include "Master.h"

#include "Display.h"

namespace Renderer
{
	void Master::clear()
	{
		//on efface l'�cran
		Display::clear();
	}

	void Master::update(const Camera& camera)
	{
		m_simpleRenderer.update(camera);

		Display::update();
	}

	void Master::draw(const Quad& model)
	{
		m_simpleRenderer.draw(model);
	}
}