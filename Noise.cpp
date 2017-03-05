#include "Noise.h"
#include "Random_Maths.h"
#include <iostream>
#include <climits>

namespace HeightMap
{ 
	Noise::Noise()
		: m_seed(Random::integer(0, INT_MAX))
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

		m_terrainSelector.SetSourceModule(0, m_flatTerrain);
		m_terrainSelector.SetSourceModule(1, m_mountainTerrain);
		m_terrainSelector.SetControlModule(m_terrainType);
		m_terrainSelector.SetBounds(0.0, 1000.0);
		m_terrainSelector.SetEdgeFalloff(0.125);


		m_finalTerrain.SetSourceModule(0, m_terrainSelector);
		m_finalTerrain.SetFrequency(4.0);
		m_finalTerrain.SetPower(0.125);

		m_heightMapBuilder.SetSourceModule(m_finalTerrain);
		m_heightMapBuilder.SetDestNoiseMap(m_heightMap);
		m_heightMapBuilder.SetDestSize(256, 256);
		m_heightMapBuilder.SetBounds(6.0, 10.0, 1.0, 5.0);
		m_heightMapBuilder.Build();
	}


	Noise::~Noise()
	{
	}

	void Noise::draw()
	{
		utils::RendererImage renderer;
		utils::Image image;
		renderer.SetSourceNoiseMap(m_heightMap);
		renderer.SetDestImage(image);
		renderer.ClearGradient();
		renderer.AddGradientPoint(-1.00, utils::Color(32, 160, 0, 255)); // grass
		renderer.AddGradientPoint(-0.25, utils::Color(224, 224, 0, 255)); // dirt
		renderer.AddGradientPoint(0.25, utils::Color(128, 128, 128, 255)); // rock
		renderer.AddGradientPoint(1.00, utils::Color(255, 255, 255, 255)); // snow
		renderer.EnableLight();
		renderer.SetLightContrast(3.0);
		renderer.SetLightBrightness(2.0);
		renderer.Render();

		utils::WriterBMP writer;
		writer.SetSourceImage(image);
		writer.SetDestFilename("tutorial.bmp");
		writer.WriteDestFile();
	}
}