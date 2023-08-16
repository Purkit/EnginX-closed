#ifndef GRAPHICS_CONTEXT_HPP
#define GRAPHICS_CONTEXT_HPP

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <GL/glx.h>
#include <GL/glext.h>

#include "../defines.h"

namespace enginx
{
    class EXAPI GraphicsContext
    {
        public:
            static GraphicsContext* Instance();
            static void Initialize();
            static void Release();
            static void createGraphicsContext();
            static void makeContextCurrent(Window& window);
        
        private:
            GraphicsContext();
            ~GraphicsContext();
            static GraphicsContext* sInstance;
        
        public:
            static XVisualInfo *m_visual;
            static GLXFBConfig m_bestFbc;
            static GLXContext m_context;

            static const int OPENGL_CONTEXT_MAJOR_VERSION = 4;
            static const int OPENGL_CONTEXT_MINOR_VERSION = 5;
        
        private:
            static void createFbc();
            static void createVisual();
            
    };
}

#endif // ! end of GRAPHICS_ENGINE_HPP