#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <memory.h>

#include "../defines.h"

namespace enginx
{
    enum ExKeyCode
    {
        EX_KEY_UNKNOWN = 0,
        EX_KEY_A,
        EX_KEY_B,
        EX_KEY_C,
        EX_KEY_D,
        EX_KEY_E,
        EX_KEY_F,
        EX_KEY_G,
        EX_KEY_H,
        EX_KEY_I,
        EX_KEY_J,
        EX_KEY_K,
        EX_KEY_L,
        EX_KEY_M,
        EX_KEY_N,
        EX_KEY_O,
        EX_KEY_P,
        EX_KEY_Q,
        EX_KEY_R,
        EX_KEY_S,
        EX_KEY_T,
        EX_KEY_U,
        EX_KEY_V,
        EX_KEY_W,
        EX_KEY_X,
        EX_KEY_Y,
        EX_KEY_Z,
        EX_KEY_F1,
        EX_KEY_F2,
        EX_KEY_F3,
        EX_KEY_F4,
        EX_KEY_F5,
        EX_KEY_F6,
        EX_KEY_F7,
        EX_KEY_F8,
        EX_KEY_F9,
        EX_KEY_F10,
        EX_KEY_F11,
        EX_KEY_F12,
        EX_KEY_ESCAPE,

        KEY_COUNT
    };

    enum Key_State
    {
        EX_KEY_NONE = 0,
        EX_KEY_PRESSED = 1,
        EX_KEY_RELEASE = 2
    };

    class EXAPI Keyboard
    {
        public:
            static void Update(KeySym keysym, Key_State key_state);
            static void Reset();

            static bool isKeyPressed(ExKeyCode key);
            static bool isKeyReleased(ExKeyCode key);

            static void Disable_AutoKeyRepeat();
            static void Enable_AutoKeyRepeat();

        private:
            static unsigned char m_KeyboardState[ExKeyCode::KEY_COUNT];

        public:
            static ExKeyCode getExKeyCodefromKeysym(KeySym keysym);
        
        private:
            static XEvent m_ev_q;
    };

} // namespace enginx

#endif // KEYBOARD_HPP