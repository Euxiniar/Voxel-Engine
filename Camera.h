#pragma once
#include "Entity.h"
#include "Display.h"

class Camera : public Entity
{
	public:
		Camera();

		void input(float dt);

	private: 
		void mouseInput(float dtMouse);
		const int centerX = Display::WIDTH / 2;
		const int centerY = Display::HEIGHT / 2;
};

