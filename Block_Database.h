#pragma once

#include "Block_Type.h"
#include "Block_ID.h"

namespace Block
{
	namespace Database
	{
		void init();

		const Type& get(uint8_t id);
		const Type& get(ID blockID);
	}
}