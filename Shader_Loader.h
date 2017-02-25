#pragma once
#include "GL/glew.h"
#include <string>

namespace Shader
{
	GLuint compileShader(const GLchar* source, GLenum type);
	std::string getSource(const std::string& sourceFile);
	GLuint createProgram(GLuint vertexShaderID, GLuint fragmentShaderID);
	GLuint loadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
}

