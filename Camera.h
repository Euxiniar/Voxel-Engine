#pragma once
#include "Entity.h"

struct Camera : public Entity
{
	public:
		void input(float dt);

	private: 
		void mouseInput(float dtMouse);
};

