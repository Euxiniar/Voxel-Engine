#include "Block_Database.h"
#include "BAir.h"
#include "BGrass.h"

namespace Block
{
	Database & Database::get()
	{
		//on cr�e une m�thode singleton. 
		//permettra de cr�er un seul objet � la fois
		static Database database;
		return database;
	}

	Database::Database()
			: blocks((int)ID::NUM_BLOCK_TYPES)
		{
			blocks[ (int) ID::Air]		= std::make_unique<Air>();
			blocks[ (int) ID::Grass]	= std::make_unique<Grass>();

		}

		const Type & Database::get(uint8_t id)
		{
			return *blocks[id];
		}

		const Type & Database::get(ID blockID)
		{
			return *blocks[(int)blockID];
		}
	
}

