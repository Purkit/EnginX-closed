#ifndef VBO_HPP
#define VBO_HPP

#include <glm/glm.hpp>
#include <vector>
#include "../loader/loader.h"

struct Vertex
{
    glm::vec3 position;
    //glm::vec3 normal;
    //glm::vec3 color;
    //glm::vec3 texUV;
};

class VBO
{
    public:
        GLuint ID;
        VBO(std::vector<Vertex>& vertices);

        void Bind();
        void Unbind();
        void Delete();
};

#endif // VBO_HPP