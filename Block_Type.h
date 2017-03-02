#pragma once

#include "Block_Data.h"
#include <string>

namespace Block
{
	class Type
	{
		public:

		protected:
			Type(const std::string& fileName);

			const Data& getData() const;

		private:
			Data m_data;
	};
}