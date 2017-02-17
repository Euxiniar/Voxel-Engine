#pragma once


#include "Glm_Common.h"

struct Entity;
struct Camera;


namespace Maths
{
		Matrix4 createViewMatrix(const Camera& camera);
		Matrix4 createModelMatrix(const Entity& entity);
		Matrix4 createProjMatrix();
}