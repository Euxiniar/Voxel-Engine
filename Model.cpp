#include "Model.h"

Model::Model(const std::vector<GLfloat>& vertexPositions,
	const std::vector<GLfloat>& textureCoordinates,
	const std::vector<GLuint>&  indices)
	: m_indicesCount(indices.size())
{
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	addVBO(3, vertexPositions);
	addVBO(2, textureCoordinates);
	addEBO(indices);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Model::~Model()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(m_buffers.size(), m_buffers.data());
}

void Model::addData(const std::vector<GLfloat>& vertexPositions,
	const std::vector<GLfloat>& textureCoordinates,
	const std::vector<GLuint>&  indices)
{
	glDeleteVertexArrays(1, &m_vao);

	//on réinitialise la RAM
	glDeleteBuffers(m_buffers.size(), m_buffers.data());

	m_indicesCount = indices.size();

	//on assigne à OpenGL de la place pour stocker le tableau et la lire 
	glGenVertexArrays(1, &m_vao);

	//on selectionne le tableau. 
	glBindVertexArray(m_vao);

	//on attribue de la ram pour gérer les vertex et les textures
	addVBO(3, vertexPositions);
	addVBO(2, textureCoordinates);
	addEBO(indices);

	//on déselectionne tout
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void Model::bind() const
{
	glBindVertexArray(m_vao);
}

void Model::unbind() const
{
	glBindVertexArray(0);
}

GLuint Model::getIndicesCount() const
{
	return m_indicesCount;
}

void Model::addVBO(int dim, const std::vector<GLfloat>& data)
{
	GLuint vbo;
	//on crée une case mémoire dans la ram de la carte graphique
	glGenBuffers(1, &vbo);

	//on la selectionne pour agir dessus
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//on réserve de la RAM au vbo. 
	//C'est un objet rarement mis a jour donc il est static
	glBufferData(GL_ARRAY_BUFFER,
		data.size() * sizeof(GLfloat),
		0,
		GL_STATIC_DRAW);

	//on envoie les données dans le buffer
	glBufferSubData(GL_ARRAY_BUFFER,
		0,
		data.size() * sizeof(GLfloat),
		data.data());

	//on accède aux sommets dans la mémoire vidéo à la place m_vboCount
	glVertexAttribPointer(m_vboCount,
		dim,
		GL_FLOAT,
		GL_FALSE,
		0,
		0);

	//on active le tableau puis on incrémente l'ID du tableau
	glEnableVertexAttribArray(m_vboCount++);

	//on stock l'ID du vbo courant dans le tableau m_buffers
	m_buffers.push_back(vbo);
}


void Model::addEBO(const std::vector<GLuint>& indices)
{
	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		indices.size() * sizeof(GLuint),
		indices.data(),
		GL_STATIC_DRAW);
	m_buffers.push_back(ebo);
}