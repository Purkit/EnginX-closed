#ifndef MESH_HPP
#define MESH_HPP

#include "../buffers/VAO.hpp"
#include "../buffers/VBO.hpp"
#include "../buffers/EBO.hpp"
#include "../../shader/shader.hpp"
#include "../loader/loader.h"

class Mesh
{
    public:
        std::vector<Vertex> vertices;
        //std::vector <GLuint> indices;
        VAO m_VAO;

        Mesh(std::vector <Vertex>& vertices/*, std::vector <GLuint>& indices*/);
        void Draw(Shader& shader);
};

#endif // MESH_HPP