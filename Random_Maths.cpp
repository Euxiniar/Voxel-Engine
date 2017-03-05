#include "Random_Maths.h"
#include <random>

namespace Random
{
	std::minstd_rand gen;

	void setSeed(int seed)
	{
		gen.seed(seed);
	}

	void init()
	{
		gen.seed(std::random_device{}());
	}

	int integer(int low, int high)
	{
		std::uniform_int_distribution<int> dist(low, high);
		return dist(gen);
	}

	double decimal(double low, double high)
	{
		std::uniform_real_distribution<double> dist(low, high);
		return dist(gen);
	}
}