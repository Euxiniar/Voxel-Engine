#include "Texture_Atlas.h"

namespace Texture
{
	Atlas::Atlas(const std::string& textureName, GLuint size, GLuint textureSize)
		: m_size(size)
		, m_textureSize(textureSize)
	{
		//on appelle la méthode load héritée de Basic_Texture
		load(textureName);
	}

	std::vector<GLfloat> Atlas::getTextureCoords(const Vector2& location)
	{
		//on calcule le nombre de textures qui est contenue sur une ligne 
		//(taille de la texture sur taille de la ligne)
		static auto texturesPerRow = m_size / m_textureSize;
		//on raporte tout sur un intervalle[0 ; 1]
		static auto unitSize = 1.0f / (float)texturesPerRow;

		//on selectionne la case
		auto xMin = location.x * unitSize;
		auto yMin = location.y * unitSize;

		auto xMax = xMin + unitSize;
		auto yMax = yMin + unitSize;

		//on retourne les coordonnées de la case dans un tableau
		return
		{
			xMax, yMax,
			xMin, yMax,
			xMin, yMin,
			xMax, yMin
		};
	}
}