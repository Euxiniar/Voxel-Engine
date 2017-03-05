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
		long m_seed;
		module::RidgedMulti m_mountainTerrain;
		module::Billow m_baseFlatTerrain;
		module::ScaleBias m_flatTerrain;
		module::Perlin m_terrainType;
		module::Select m_terrainSelector;
		module::Turbulence m_finalTerrain;
		utils::NoiseMap m_heightMap;
		utils::NoiseMapBuilderPlane m_heightMapBuilder;
	};
}