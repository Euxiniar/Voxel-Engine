#include "Random_Maths.h"
#include <random>

namespace Random
{
	std::minstd_rand gen;

	void setSeed(int seed)
	{
		gen.seed(seed);
	}


	int integer(int low, int high)
	{
		gen.seed(std::random_device{}());
		std::uniform_int_distribution<int> dist(low, high);
		return dist(gen);
	}

	double decimal(double low, double high)
	{
		std::uniform_real_distribution<double> dist(low, high);
		return dist(gen);
	}
}