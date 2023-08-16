#include <enginx/core/connection.hpp>
#include <enginx/core/screen.hpp>
#include <enginx/core/graphicsContext.hpp>
#include <enginx/utility/logger.hpp>
#include <enginx/utility/asserts.hpp>

#define DEBUG_MODE

namespace enginx
{
    GraphicsContext* GraphicsContext::sInstance = NULL;

    XVisualInfo* GraphicsContext::m_visual = {};
    GLXFBConfig GraphicsContext::m_bestFbc = {};
    GLXContext GraphicsContext::m_context = 0;

    GraphicsContext* GraphicsContext::Instance()
    {
        if (sInstance == NULL)
            sInstance = new GraphicsContext();

        return sInstance;
    }

    void GraphicsContext::Initialize()
    {
        createFbc();
        createVisual();       
    }

    void GraphicsContext::Release()
    {
        /* delete sInstance;
        sInstance = NULL; */
        glXDestroyContext(XConnection::connection, m_context);
        XFree(m_visual);
        //XFree(m_bestFbc);
    }

    GraphicsContext::GraphicsContext()
    {

    }

    GraphicsContext::~GraphicsContext()
    {
        
    }

    void GraphicsContext::createFbc()
    {
        GLint glxAttribs[] = {
            GLX_X_RENDERABLE    , True,
            GLX_DRAWABLE_TYPE   , GLX_WINDOW_BIT,
            GLX_RENDER_TYPE     , GLX_RGBA_BIT,
            GLX_X_VISUAL_TYPE   , GLX_TRUE_COLOR,
            GLX_RED_SIZE        , 8,
            GLX_GREEN_SIZE      , 8,
            GLX_BLUE_SIZE       , 8,
            GLX_ALPHA_SIZE      , 8,
            GLX_DEPTH_SIZE      , 24,
            GLX_STENCIL_SIZE    , 8,
            GLX_DOUBLEBUFFER    , True,
            None
	    };

        int fbcount;
        GLXFBConfig* fbc = glXChooseFBConfig(XConnection::connection, XScreen::defaultScreen_ID, glxAttribs, &fbcount);
        STOP_IF_TRUE(fbc == 0, "Failed to retrieve framebuffer.");
        DEBUG("Found %i matching framebuffers.", fbcount);

        // Pick the FB config/visual with the most samples per pixel
        DEBUG("Getting best XVisualInfo");
        int best_fbc = -1, worst_fbc = -1, best_num_samp = -1, worst_num_samp = 999;
        for (int i = 0; i < fbcount; ++i) {
            XVisualInfo *vi = glXGetVisualFromFBConfig( XConnection::connection, fbc[i] );
            if ( vi != 0)
            {
                int samp_buf, samples;
                glXGetFBConfigAttrib( XConnection::connection, fbc[i], GLX_SAMPLE_BUFFERS, &samp_buf );
                glXGetFBConfigAttrib( XConnection::connection, fbc[i], GLX_SAMPLES       , &samples  );

                if ( best_fbc < 0 || (samp_buf && samples > best_num_samp) )
                {
                    best_fbc = i;
                    best_num_samp = samples;
                }

                if ( worst_fbc < 0 || !samp_buf || samples < worst_num_samp )
                    worst_fbc = i;
                
                worst_num_samp = samples;
            }

            XFree( vi );
        }
        //std::cout << "Best visual info index: " << best_fbc << "\n";
        m_bestFbc = fbc[ best_fbc ];
        XFree( fbc );
        
    }  // ! end of createFbc();

    void GraphicsContext::createVisual()
    {
        m_visual = glXGetVisualFromFBConfig( XConnection::connection, m_bestFbc );
        STOP_IF_TRUE(m_visual == 0, "Could not create correct visual window.");

        STOP_IF_TRUE(XScreen::defaultScreen_ID != m_visual->screen, "ScreenID does not match visual->screen.");    

    } // ! end of createVisual();

    void GraphicsContext::createGraphicsContext()
    {
        typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);
        glXCreateContextAttribsARBProc glXCreateContextAttribsARB = 0;
        glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc) glXGetProcAddressARB( (const GLubyte *) "glXCreateContextAttribsARB" );
        STOP_IF_TRUE(glXCreateContextAttribsARB == 0, "Failed to load glXCreateContextAttribsARB(). OpenGL Context can't be obtained.");

        #ifdef DEBUG_MODE
        int context_attribs[] = {
            GLX_CONTEXT_MAJOR_VERSION_ARB, OPENGL_CONTEXT_MAJOR_VERSION,
            GLX_CONTEXT_MINOR_VERSION_ARB, OPENGL_CONTEXT_MINOR_VERSION,
            GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_DEBUG_BIT_ARB,          
            GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,            
            None
        };
        #else
        int context_attribs[] = {
            GLX_CONTEXT_MAJOR_VERSION_ARB, OPENGL_CONTEXT_MAJOR_VERSION,
            GLX_CONTEXT_MINOR_VERSION_ARB, OPENGL_CONTEXT_MINOR_VERSION,            
            GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,            
            None
        };
        #endif

        m_context = glXCreateContextAttribsARB(XConnection::connection, m_bestFbc, 0, true, context_attribs);
        
        XSync( XConnection::connection, False );

        #ifdef DEBUG_MODE
        if (!glXIsDirect(XConnection::connection, m_context)) {
            DEBUG("Indirect GLX rendering context obtained.");
        }
        else {
            DEBUG("Direct GLX rendering context obtained.");
        }
        #endif
        
    }  // ! end of createGraphicsContext();

    void GraphicsContext::makeContextCurrent(Window& window)
    {
        glXMakeCurrent(XConnection::connection, window, m_context);

        #ifdef DEBUG_MODE
        DEBUG("GL Vendor: %c", glGetString(GL_VENDOR));
        DEBUG("GL Renderer: %c", glGetString(GL_RENDERER));
        DEBUG("GL Version: %c", glGetString(GL_VERSION));
        #endif
    }  // ! end of makeContextCurrent();

}