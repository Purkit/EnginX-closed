#include <enginx/input/keyboard.hpp>
#include <enginx/core/connection.hpp>

namespace enginx
{
    unsigned char Keyboard::m_KeyboardState[KEY_COUNT] = {};
    XEvent Keyboard::m_ev_q;

    ExKeyCode Keyboard::getExKeyCodefromKeysym(KeySym keysym)
    {
        switch (keysym)
        {
            case XK_A:
            case XK_a:  return EX_KEY_A; break;

            case XK_B:
            case XK_b:  return EX_KEY_B; break;

            case XK_C: 
            case XK_c:  return EX_KEY_C; break;

            case XK_D: 
            case XK_d:  return EX_KEY_D; break;

            case XK_E: 
            case XK_e:  return EX_KEY_E; break;
            
            case XK_F: 
            case XK_f:  return EX_KEY_F; break;
            
            case XK_G: 
            case XK_g:  return EX_KEY_G; break;
            
            case XK_H: 
            case XK_h:  return EX_KEY_H; break;
            
            case XK_I: 
            case XK_i:  return EX_KEY_I; break;
            
            case XK_J: 
            case XK_j:  return EX_KEY_J; break;
            
            case XK_K: 
            case XK_k:  return EX_KEY_K; break;
            
            case XK_L: 
            case XK_l:  return EX_KEY_L; break;
            
            case XK_M: 
            case XK_m:  return EX_KEY_M; break;
            
            case XK_N: 
            case XK_n:  return EX_KEY_N; break;
            
            case XK_O: 
            case XK_o:  return EX_KEY_O; break;
            
            case XK_P: 
            case XK_p:  return EX_KEY_P; break;
            
            case XK_Q: 
            case XK_q:  return EX_KEY_Q; break;
            
            case XK_R: 
            case XK_r:  return EX_KEY_R; break;
            
            case XK_S: 
            case XK_s:  return EX_KEY_S; break;
            
            case XK_T: 
            case XK_t:  return EX_KEY_T; break;
            
            case XK_U: 
            case XK_u:  return EX_KEY_U; break;
            
            case XK_V: 
            case XK_v:  return EX_KEY_V; break;
            
            case XK_W: 
            case XK_w:  return EX_KEY_W; break;
            
            case XK_X: 
            case XK_x:  return EX_KEY_X; break;
            
            case XK_Y: 
            case XK_y:  return EX_KEY_Y; break;
            
            case XK_Z: 
            case XK_z:  return EX_KEY_Z; break;

            case XK_F1:     return EX_KEY_F1;     break;
            case XK_F2:     return EX_KEY_F2;     break;
            case XK_F3:     return EX_KEY_F3;     break;
            case XK_F4:     return EX_KEY_F4;     break;
            case XK_F5:     return EX_KEY_F5;     break;
            case XK_F6:     return EX_KEY_F6;     break;
            case XK_F7:     return EX_KEY_F7;     break;
            case XK_F8:     return EX_KEY_F8;     break;
            case XK_F9:     return EX_KEY_F9;     break;
            case XK_F10:    return EX_KEY_F10;    break;
            case XK_F11:    return EX_KEY_F11;    break;
            case XK_F12:    return EX_KEY_F12;    break;

            case XK_Escape: return EX_KEY_ESCAPE; break;

            default:
                return EX_KEY_UNKNOWN;
            break;
        };
    }  // ! end of getExKeyCodefromKeysym();

    void Keyboard::Update(KeySym keysym, Key_State key_state)
    {
        ExKeyCode key = getExKeyCodefromKeysym(keysym);
        m_KeyboardState[key] = key_state;
    }

    void Keyboard::Reset()
    {
        memset(m_KeyboardState, 0, sizeof(unsigned char)*27);
    }

    bool Keyboard::isKeyPressed(ExKeyCode key)
    {
        return m_KeyboardState[key] == EX_KEY_PRESSED;
    }

    bool Keyboard::isKeyReleased(ExKeyCode key)
    {
        return m_KeyboardState[key] == EX_KEY_RELEASE;
    }

    void Keyboard::Disable_AutoKeyRepeat()
    {
        XAutoRepeatOff(XConnection::connection);
    }

    void Keyboard::Enable_AutoKeyRepeat()
    {
        XAutoRepeatOn(XConnection::connection);
    }
}