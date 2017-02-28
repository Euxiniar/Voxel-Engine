#include "Simple_Shader.h"
#include "Matrix_Maths.h"

namespace Shader
{
	//en se construisant, simple_shader crée un Shader_program
	Simple_Shader::Simple_Shader()
	: Shader_Program("Simple_Vertex", "Simple_Fragment")
	{
		getUniformLocations();

		//on appelle la fonction bind héritée de Shader_Program
		bind();

		//on appelle la fonction loadMatrix4 de Shader_Program
		loadMatrix4(m_locationProjMatrix, Maths::createProjMatrix());

		//on délie le program
		unbind();
	}

	void Simple_Shader::setTime(float time)
	{
		loadFloat(m_locationTime, time);
	}

	void Simple_Shader::setViewMatrix(const Matrix4 & matrix)
	{
		loadMatrix4(m_locationViewMatrix, matrix);
	}

	void Simple_Shader::setModelMatrix(const Matrix4 & matrix)
	{
		loadMatrix4(m_locationModelMatrix, matrix);
	}

	void Simple_Shader::setProjMatrix(const Matrix4 & matrix)
	{
		loadMatrix4(m_locationProjMatrix, matrix);
	}

	void Simple_Shader::getUniformLocations()
	{
		//on récupère la localisation de toutes les variables
		m_locationTime			=	glGetUniformLocation(getId(), "time");
		m_locationViewMatrix	=	glGetUniformLocation(getId(), "viewMatrix");
		m_locationModelMatrix	=	glGetUniformLocation(getId(), "modelMatrix");
		m_locationProjMatrix	=	glGetUniformLocation(getId(), "projMatrix");
	}
}