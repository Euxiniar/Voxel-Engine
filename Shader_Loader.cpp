#include "Shader_Loader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcpt.h>

namespace Shader
{
	GLuint compileShader(const GLchar* source, GLenum type)
	{
		//on crée le shader avec le type (frag ou vert)
		auto id = glCreateShader(type);

		//on envoie à notre shader courant le code de notre fichier
		glShaderSource(id, 1, &source, nullptr);

		//on compile le shader
		glCompileShader(id);

		GLint isSuccess;
		GLchar infoLog[GL_INFO_LOG_LENGTH];

		//on récupère l'état de la compilation
		glGetShaderiv(id, GL_COMPILE_STATUS, &isSuccess);

		//Si la compilation n'a pas fonctionnée
		if (!isSuccess)
		{
			glGetShaderInfoLog(id, GL_INFO_LOG_LENGTH, nullptr, infoLog);
			throw std::runtime_error("Error compiling shader: " + std::string(infoLog));
		}

		//retourne l'ID du shader
		return id;
	}

	std::string getSource(const std::string& sourceFile)
	{
		//on ouvre le fichier
		std::ifstream inFile("Data/Shaders/" + sourceFile + ".glsl");
		std::string source;
		std::stringstream stringStream;

		//on vérifie qu'il s'est bien ouvert
		if (!inFile.is_open())
		{
			throw std::runtime_error("Could not open file: " + sourceFile);
		}

		//on récupère grace au flux l'intégralité du fichier
		stringStream << inFile.rdbuf();

		//on le convertit en string
		source = stringStream.str();

		//on le renvoie
		return source;
	}

	GLuint createProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
	{
		//on crée un program
		auto id = glCreateProgram();

		//on lui attache nos deux codes précompilés.
		glAttachShader(id, vertexShaderID);
		glAttachShader(id, fragmentShaderID);

		//on link les deux fichiers vert et frag entre eux
		glLinkProgram(id);

		GLint isSuccess;
		GLchar infoLog[GL_INFO_LOG_LENGTH];

		//on récupère l'état du link
		glGetShaderiv(id, GL_LINK_STATUS, &isSuccess);

		//Si le link n'a pas fonctionnée
		if (!isSuccess)
		{
			glGetShaderInfoLog(id, GL_INFO_LOG_LENGTH, nullptr, infoLog);
			throw std::runtime_error("Error link shader: " + std::string(infoLog));
		}


		return id;
	}

	GLuint loadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
	{
		//on appelle la méthode pour ouvrir les fichiers
		auto vertexSource = getSource(vertexShaderFile);
		auto fragmentSource = getSource(fragmentShaderFile);

		//on appelle la compilation du code d'abord pour le shader de sommets, puis de pixels
		auto vertexShaderID = compileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
		auto fragmentShaderID = compileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);

		//on appelle la fonction createProgram (seul un program peut etre executé par la carte graphique)
		auto programID = createProgram(vertexShaderID, fragmentShaderID);

		//on supprime les deux shaders puisqu'ils ne nous servent plus
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);

		//on retourne l'id du program
		return programID;
	}
}