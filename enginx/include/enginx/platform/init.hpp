#ifndef PLATFORM_INITIALIZE_HPP
#define PLATFORM_INITIALIZE_HPP

#include "../core/connection.hpp"
#include "../core/screen.hpp"

namespace enginx
{
    class Platform
    {
        public:
            static void StartUp();
            static void ShutDown();
    };
}

#endif // PLATFORM_INITIALIZE_HPP