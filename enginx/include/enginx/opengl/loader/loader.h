#ifndef LOADER_H
#define LOADER_H

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glext.h>

#define EX_GLAPI extern

#ifdef __cplusplus
extern "C" {
#endif

EX_GLAPI void LoadGL();

#include <KHR/khrplatform.h>
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef khronos_int8_t GLbyte;
typedef khronos_uint8_t GLubyte;
typedef khronos_int16_t GLshort;
typedef khronos_uint16_t GLushort;
typedef int GLint;
typedef unsigned int GLuint;
typedef khronos_int32_t GLclampx;
typedef int GLsizei;
typedef khronos_float_t GLfloat;
typedef khronos_float_t GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void *GLeglClientBufferEXT;
typedef void *GLeglImageOES;
typedef char GLchar;
typedef char GLcharARB;

typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
extern PFNGLCREATESHADERPROC ex_glCreateShader;
#define glCreateShader ex_glCreateShader
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
extern PFNGLSHADERSOURCEPROC ex_glShaderSource;
#define glShaderSource ex_glShaderSource
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
extern PFNGLCOMPILESHADERPROC ex_glCompileShader;
#define glCompileShader ex_glCompileShader
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC)(void);
extern PFNGLCREATEPROGRAMPROC ex_glCreateProgram;
#define glCreateProgram ex_glCreateProgram
typedef void (APIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
extern PFNGLATTACHSHADERPROC ex_glAttachShader;
#define glAttachShader ex_glAttachShader
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
extern PFNGLLINKPROGRAMPROC ex_glLinkProgram;
#define glLinkProgram ex_glLinkProgram
typedef void (APIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
extern PFNGLDELETESHADERPROC ex_glDeleteShader;
#define glDeleteShader ex_glDeleteShader
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint *arrays);
extern PFNGLGENVERTEXARRAYSPROC ex_glGenVertexArrays;
#define glGenVertexArrays ex_glGenVertexArrays
typedef void (APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint *buffers);
extern PFNGLGENBUFFERSPROC ex_glGenBuffers;
#define glGenBuffers ex_glGenBuffers
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint array);
extern PFNGLBINDVERTEXARRAYPROC ex_glBindVertexArray;
#define glBindVertexArray ex_glBindVertexArray
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint *arrays);
extern PFNGLDELETEVERTEXARRAYSPROC ex_glDeleteVertexArrays;
#define glDeleteVertexArrays ex_glDeleteVertexArrays
extern PFNGLBINDBUFFERPROC ex_glBindBuffer;
#define glBindBuffer ex_glBindBuffer
extern PFNGLDELETEBUFFERSPROC ex_glDeleteBuffers;
#define glDeleteBuffers ex_glDeleteBuffers
extern PFNGLBUFFERDATAPROC ex_glBufferData;
#define glBufferData ex_glBufferData
extern PFNGLVERTEXATTRIBPOINTERPROC ex_glVertexAttribPointer;
#define glVertexAttribPointer ex_glVertexAttribPointer
extern PFNGLENABLEVERTEXATTRIBARRAYPROC ex_glEnableVertexAttribArray;
#define glEnableVertexAttribArray ex_glEnableVertexAttribArray
extern PFNGLUSEPROGRAMPROC ex_glUseProgram;
#define glUseProgram ex_glUseProgram
extern PFNGLDELETEPROGRAMPROC ex_glDeleteProgram;
#define glDeleteProgram ex_glDeleteProgram
extern PFNGLGETUNIFORMLOCATIONPROC ex_glGetUniformLocation;
#define glGetUniformLocation ex_glGetUniformLocation
extern PFNGLUNIFORM1IPROC ex_glUniform1i;
#define glUniform1i ex_glUniform1i
extern PFNGLUNIFORM1FPROC ex_glUniform1f;
#define glUniform1f ex_glUniform1f
extern PFNGLUNIFORM2FVPROC ex_glUniform2fv;
#define glUniform2fv ex_glUniform2fv
extern PFNGLUNIFORM2FPROC ex_glUniform2f;
#define glUniform2f ex_glUniform2f
extern PFNGLUNIFORM3FVPROC ex_glUniform3fv;
#define glUniform3fv ex_glUniform3fv
extern PFNGLUNIFORM3FPROC ex_glUniform3f;
#define glUniform3f ex_glUniform3f
extern PFNGLUNIFORM4FVPROC ex_glUniform4fv;
#define glUniform4fv ex_glUniform4fv
extern PFNGLUNIFORM4FPROC ex_glUniform4f;
#define glUniform4f ex_glUniform4f
extern PFNGLUNIFORMMATRIX2FVPROC ex_glUniformMatrix2fv;
#define glUniformMatrix2fv ex_glUniformMatrix2fv
extern PFNGLUNIFORMMATRIX3FVPROC ex_glUniformMatrix3fv;
#define glUniformMatrix3fv ex_glUniformMatrix3fv
extern PFNGLUNIFORMMATRIX4FVPROC ex_glUniformMatrix4fv;
#define glUniformMatrix4fv ex_glUniformMatrix4fv
extern PFNGLGETSHADERIVPROC ex_glGetShaderiv;
#define glGetShaderiv ex_glGetShaderiv
extern PFNGLGETSHADERINFOLOGPROC ex_glGetShaderInfoLog;
#define glGetShaderInfoLog ex_glGetShaderInfoLog
extern PFNGLGETPROGRAMIVPROC ex_glGetProgramiv;
#define glGetProgramiv ex_glGetProgramiv
extern PFNGLGETPROGRAMINFOLOGPROC ex_glGetProgramInfoLog;
#define glGetProgramInfoLog ex_glGetProgramInfoLog

#ifdef __cplusplus
}
#endif



#endif // LOADER_H