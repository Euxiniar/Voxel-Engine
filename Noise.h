#pragma once
#include "noiseutils.h"
#include <string>

namespace HeightMap
{ 
	class Noise
	{
		public:
			Noise();
			void valley_Mountains();
			void setBound(int positionX, int positionY);
			double getPositionY(int x, int z);
			void draw(std::string name);
	private:
		long m_seed;
		void initTerrainSelector();
		void initFinalTerrain();
		void initHeightMapBuilder();
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