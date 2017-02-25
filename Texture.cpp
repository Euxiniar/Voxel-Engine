#include "Texture.h"
#include <SFML/Graphics/Image.hpp>
#include <GL/glew.h>

namespace Texture
{
	void Basic_Texture::load(const std::string & fileName)
	{
		std::string filePath = "Data/Textures/" + fileName + ".png";

		//on charge l'image depuis le fichier passé en argument
		sf::Image image;
		image.loadFromFile(filePath);

		//on assigne à OpenGL de la place pour stocker la texture et la lire 
		glGenTextures(1, &m_textureId);

		//on selectionne la texture qu'on utilise comme étant 2D. 
		glBindTexture(GL_TEXTURE_2D, m_textureId);

		//on définit les propriétés de l'image
		glTexImage2D(GL_TEXTURE_2D,
			0,
			GL_RGBA,
			image.getSize().x,
			image.getSize().y,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			image.getPixelsPtr());

		//En cas de débordement de la forme, la texture se déforme pour rentrer
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		//on déselectionne la texture
		glBindTexture(GL_TEXTURE_2D, 0);		
	}

	void Basic_Texture::bind()
	{
		glBindTexture(GL_TEXTURE_2D, m_textureId);
	}

	void Basic_Texture::unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}



