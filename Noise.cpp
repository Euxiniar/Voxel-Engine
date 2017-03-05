#include "Noise.h"
#include "Random_Maths.h"

namespace HeightMap
{ 
	Noise::Noise()
		: m_seed(Random::integer(0, sizeof(double)))
	{
		m_noise.SetSeed(m_seed);
		utils::NoiseMapBuilderPlane heightMapBuilder;
		heightMapBuilder.SetSourceModule(m_noise);
		heightMapBuilder.SetDestNoiseMap(heightMap);
		heightMapBuilder.SetDestSize(256, 256);
		heightMapBuilder.SetBounds(2.0, 6.0, 1.0, 5.0);
		heightMapBuilder.Build();
	}


	Noise::~Noise()
	{
	}

	void Noise::draw()
	{
		utils::RendererImage renderer;
		utils::Image image;
		renderer.SetSourceNoiseMap(heightMap);
		renderer.SetDestImage(image);
		renderer.Render();

		utils::WriterBMP writer;
		writer.SetSourceImage(image);
		writer.SetDestFilename("tutorial.bmp");
		writer.WriteDestFile();
	}
}