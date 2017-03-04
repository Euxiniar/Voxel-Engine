#pragma once
#include <cstdint>

namespace Block
{
	struct Position
	{
		Position(uint8_t x, uint8_t y, uint8_t z);

		uint8_t x,
			y,
			z;
	};

}