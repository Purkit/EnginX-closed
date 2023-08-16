#ifndef SHADER_HPP
#define SHADER_HPP

#include "../opengl/loader/loader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <ex_maths/ex_maths.hpp>

class Shader
{
    public:
        unsigned int ID;
    
    public:
        Shader(const char* vertexPath, const char* fragmentPath);
        ~Shader();

        void Activate();

    public:
        void setBool(const std::string& name, bool value) const;
        void setInt(const std::string& name, int value) const;
        void setFloat(const std::string& name, float value) const;
        void setVec2(const std::string& name, const ex_math::Vector2f& value) const;
        void setVec2(const std::string& name, float x, float y) const;
        void setVec3(const std::string& name, const ex_math::Vector3f& value) const;
        void setVec3(const std::string& name, float x, float y, float z) const;
        void setVec4(const std::string& name, const ex_math::Vector4f& value) const;
        void setVec4(const std::string& name, float x, float y, float z, float w);
        void setMat2(const std::string& name, const ex_math::Matrix2x2& mat) const;
        void setMat3(const std::string& name, const ex_math::Matrix3x3& mat) const;
        void setMat4(const std::string& name, const ex_math::Matrix4x4& mat) const;
    
    private:
        mutable std::unordered_map<std::string, GLint> m_UniformLocationCache;

    private: 
        void checkCompileErrors(GLuint shader, std::string type);
        GLint GetUniformLocation(const std::string& name) const;
};

#endif // SHADER_HPP