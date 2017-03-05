#pragma once


#include <random>

namespace Random
{
	void init();
	int integer(int low, int high);
	void setSeed(int seed);
}