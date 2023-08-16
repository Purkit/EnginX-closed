#include "../include/app.hpp"
#include <enginx/platform/init.hpp>
#include <enginx/utility/logger.hpp>

int main()
{
    enginx::Platform::StartUp();
    enginx::Logger::setPrirority(enginx::LOG_LEVEL_VERBOSE);

    {
        enginx::Application app{};
        app.Initialize();
        app.Run();
        app.Release();
    }

    enginx::Platform::ShutDown();

    return 0;    
}