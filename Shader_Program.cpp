#include "Shader_Program.h"
#include "Shader_Loader.h"

namespace Shader 
{
	//on appelle la fonction loadShader (dans le shaderLoader) pour activer le programme
	Shader_Program::Shader_Program(const std::string & vertexShaderFile, const std::string & fragmentShaderFile)
		: m_programId(Shader::loadShader(vertexShaderFile, fragmentShaderFile))
	{
	}

	Shader_Program::~Shader_Program()
	{
		glDeleteProgram(m_programId);
	}

	void Shader_Program::bind()
	{
		//on sélectionne le programme pour l'utiliser
		glUseProgram(m_programId);
	}

	void Shader_Program::unbind()
	{
		//on déselectionne le program
		glUseProgram(0);
	}

	GLuint Shader_Program::getId() const
	{
		//on retourne l'id du programme généré avec loadShader
		return m_programId;
	}

	void Shader_Program::loadFloat(GLuint location, float value)
	{
		glUniform1f(location, value);
	}

	void Shader_Program::loadVector2(GLuint location, const Vector2 & vector)
	{
		glUniform2f(location, vector.x, vector.y);
	}

	void Shader_Program::loadMatrix4(GLuint location, const Matrix4 & matrix)
	{
		//on charge la matrice dans la variable du dhader sélectionnée
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
		
	}
}