#pragma once
#include <vector>
#include "Simple_Shader.h"

class Chunklet;
class Camera;

namespace Renderer
{
	class RChunk
	{
		public:
			void draw (const Chunklet& quad);
			void update(const Camera& camera);

		private:
			std::vector<const Chunklet*> m_chunks;
	};
}