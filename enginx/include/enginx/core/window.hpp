#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <memory>
#include <functional>
#include "../defines.h"

namespace enginx
{
    struct ExWindowConfigInfo
    {
        std::string Title; // ? Should std::string be removed from this project
        u32 Width;
        u32 Height;

        ExWindowConfigInfo(const std::string& title = "EnginX", u32 width = 1000, u32 height = 800)
        : Title(title), Width(width), Height(height) {}
    };

    // ** EnginX Window Interface
    class EXAPI ExWindow
    {
        public:
            virtual ~ExWindow() = default;

            virtual void OnUpdate() = 0;

            virtual void Initialize() = 0;            
            virtual void Show() const = 0;
            virtual void Clear() const = 0;
            virtual void SetTitle(const std::string& title) const = 0;
            virtual void Close() = 0;

            virtual void PumpEvents() = 0;      // * Non blocking
            virtual void WaitForEvents() = 0;   // * Blocking

            virtual void MakeContextCurrent() const = 0;
            virtual void Present() const = 0;

            virtual void Toggle_FullScreenMode() = 0;
            virtual void Toggle_BorderlessMode() = 0;

            virtual bool shouldClose() const = 0;

            virtual u32 GetWidth() const = 0;
            virtual u32 GetHeight() const = 0;
            virtual void GetLocation(int& x, int& y) const = 0;

            static std::unique_ptr<ExWindow> Create(u32 w, u32 h, const std::string& title);
    };

}

#endif // WINDOW_HPP