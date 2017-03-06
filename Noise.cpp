#include "Noise.h"
#include "Random_Maths.h"
#include <climits>
#include <iostream>

namespace HeightMap
{ 
	Noise::Noise()
		: m_seed(Random::integer(0, INT_MAX))
	{
		valley_Mountains();
		initTerrainSelector();
		initFinalTerrain();
		initHeightMapBuilder();
	}

	void Noise::valley_Mountains()
	{
		m_baseFlatTerrain.SetFrequency(2.0);
		m_baseFlatTerrain.SetSeed(m_seed);

		m_flatTerrain.SetSourceModule(0, m_baseFlatTerrain);
		m_flatTerrain.SetScale(0.125);
		m_flatTerrain.SetBias(-0.75);

		m_mountainTerrain.SetSeed(m_seed);

		m_terrainType.SetFrequency(0.5);
		m_terrainType.SetPersistence(0.25);
		m_terrainType.SetSeed(m_seed);
	}

	void Noise::initTerrainSelector()
	{
		m_terrainSelector.SetSourceModule(0, m_flatTerrain);
		m_terrainSelector.SetSourceModule(1, m_mountainTerrain);
		m_terrainSelector.SetControlModule(m_terrainType);
		m_terrainSelector.SetBounds(0.0, 1000.0);
		m_terrainSelector.SetEdgeFalloff(0.125);
	}

	void Noise::initFinalTerrain()
	{
		m_finalTerrain.SetSourceModule(0, m_terrainSelector);
		m_finalTerrain.SetFrequency(4.0);
		m_finalTerrain.SetPower(0.125);
	}

	void Noise::initHeightMapBuilder()
	{
		m_heightMapBuilder.SetSourceModule(m_finalTerrain);
		m_heightMapBuilder.SetDestNoiseMap(m_heightMap);
		m_heightMapBuilder.SetDestSize(256, 256);
	}

	void Noise::setBound(int positionX, int positionY)
	{
		const double SIZE = 4;
		positionX *= (int)SIZE;
		positionY *= (int)SIZE;
		m_heightMapBuilder.SetBounds((double)positionX, (double)positionX + SIZE, (double)positionY, (double)positionY + SIZE);
		m_heightMapBuilder.Build();
	}

	void Noise::draw(std::string name)
	{
		utils::RendererImage renderer;
		utils::Image image;
		renderer.SetSourceNoiseMap(m_heightMap);
		renderer.SetDestImage(image);
	//	renderer.ClearGradient();
	//	renderer.AddGradientPoint(-1.00, utils::Color(32, 160, 0, 255)); // grass
	//	renderer.AddGradientPoint(-0.25, utils::Color(224, 224, 0, 255)); // dirt
	//	renderer.AddGradientPoint(0.25, utils::Color(128, 128, 128, 255)); // rock
	//	renderer.AddGradientPoint(1.00, utils::Color(255, 0, 0, 255)); // snow
		renderer.EnableLight();
		renderer.SetLightContrast(3.0);
		renderer.SetLightBrightness(2.0);
		renderer.Render();

		utils::WriterBMP writer;
		writer.SetSourceImage(image);
		writer.SetDestFilename(name);
		writer.WriteDestFile();
	}

	double Noise::getPositionY(int x, int y)
	{
		return m_heightMap.GetValue(x, y);
	}
}