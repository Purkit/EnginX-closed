#include <enginx/shader/shader.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    // 2. compile shaders
    unsigned int vertex, fragment;
    // vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");
    // fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    // shader Program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");
    // delete the shaders as they're linked into our program now and no longer necessery
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader()
{
    glDeleteProgram(ID);
}

GLint Shader::GetUniformLocation(const std::string& name) const
{
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
        return m_UniformLocationCache[name];

    GLint location = glGetUniformLocation(ID, name.c_str());
    m_UniformLocationCache[name] = location;
    return location;
}


void Shader::Activate()
{
    glUseProgram(ID);
}


// ------------------------------------------------------------------------
void Shader::setBool(const std::string& name, bool value) const
{
    GLuint location = GetUniformLocation(name);
    glUniform1i(location, (int)value);
}
// ------------------------------------------------------------------------
void Shader::setInt(const std::string& name, int value) const
{
    GLuint location = GetUniformLocation(name);
    glUniform1i(location, value);
}
// ------------------------------------------------------------------------
void Shader::setFloat(const std::string& name, float value) const
{
    GLuint location = GetUniformLocation(name);
    glUniform1f(location, value);
}
// ------------------------------------------------------------------------
void Shader::setVec2(const std::string& name, const ex_math::Vector2f& value) const
{
    GLuint location = GetUniformLocation(name);
    glUniform2fv(location, 1, (GLfloat*)&value);
}
// ------------------------------------------------------------------------
void Shader::setVec2(const std::string& name, float x, float y) const
{
    GLuint location = GetUniformLocation(name);
    glUniform2f(location, x, y);
}
// ------------------------------------------------------------------------
void Shader::setVec3(const std::string& name, const ex_math::Vector3f& value) const
{
    GLuint location = GetUniformLocation(name);
    glUniform3fv(location, 1, (GLfloat*)&value);
}
// ------------------------------------------------------------------------
void Shader::setVec3(const std::string& name, float x, float y, float z) const
{
    GLuint location = GetUniformLocation(name);
    glUniform3f(location, x, y, z);
}
// ------------------------------------------------------------------------
void Shader::setVec4(const std::string& name, const ex_math::Vector4f& value) const
{
    GLuint location = GetUniformLocation(name);
    glUniform4fv(location, 1, (GLfloat*)&value);
}
// ------------------------------------------------------------------------
void Shader::setVec4(const std::string& name, float x, float y, float z, float w)
{
    GLuint location = GetUniformLocation(name);
    glUniform4f(location, x, y, z, w);
}
// ------------------------------------------------------------------------
void Shader::setMat2(const std::string& name, const ex_math::Matrix2x2& mat) const
{
    GLuint location = GetUniformLocation(name);
    glUniformMatrix2fv(location, 1, GL_FALSE, (GLfloat*)&mat);
}
// ------------------------------------------------------------------------
void Shader::setMat3(const std::string& name, const ex_math::Matrix3x3& mat) const
{
    GLuint location = GetUniformLocation(name);
    glUniformMatrix3fv(location, 1, GL_FALSE, (GLfloat*)&mat);
}
// ------------------------------------------------------------------------
void Shader::setMat4(const std::string& name, const ex_math::Matrix4x4& mat) const
{
    GLuint location = GetUniformLocation(name);
    glUniformMatrix4fv(location, 1, GL_FALSE, (GLfloat*)&mat);
}
// ------------------------------------------------------------------------

void Shader::checkCompileErrors(GLuint shader, std::string type)
{
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}