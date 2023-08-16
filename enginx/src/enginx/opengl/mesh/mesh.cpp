#include <enginx/opengl/mesh/mesh.hpp>

Mesh::Mesh(std::vector <Vertex>& vertices/*, std::vector <GLuint>& indices*/)
{
	Mesh::vertices = vertices;
	//Mesh::indices = indices;

	m_VAO.Bind();
	VBO m_VBO(vertices);
	//EBO m_EBO(indices);
    

	m_VAO.LinkAttrib(m_VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	//VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	//VAO.LinkAttrib(VBO, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
	//VAO.LinkAttrib(VBO, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));


	m_VAO.Unbind();
	m_VBO.Unbind();
	//EBO.Unbind();
}


void Mesh::Draw(Shader& shader)
{
	// Bind shader to be able to access uniforms
	shader.Activate();
	m_VAO.Bind();


	// Draw the actual mesh
    glDrawArrays(GL_TRIANGLES, 0, 3); // for now
	//glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}