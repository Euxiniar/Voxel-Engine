#pragma once
#include "noiseutils.h"

namespace HeightMap
{ 
	class Noise
	{
		public:
			Noise();
			~Noise();
			void draw();
	private:
		double m_seed;
		module::Perlin m_noise;
		utils::NoiseMap heightMap;
		utils::NoiseMapBuilderPlane heightMapBuilder;
	};
}