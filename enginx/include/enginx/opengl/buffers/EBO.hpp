#ifndef EBO_HPP
#define EBO_HPP

#include <vector>
#include "../loader/loader.h"

class EBO
{
    public:
        GLuint ID;
        EBO(std::vector<GLuint>& indices);

        void Bind();
        void Unbind();
        void Delete();

};

#endif // EBO_HPP