#include <enginx/core/connection.hpp>
#include <enginx/utility/logger.hpp>
#include <enginx/utility/asserts.hpp>

Display* XConnection::connection = NULL;

void XConnection::Connect()
{
    VERBOSE("Connecting to X Server...");
    connection = XOpenDisplay(NULL);
    STOP_IF_TRUE(connection == NULL, "Failed to connect to X Server.");    
}

void XConnection::Disconnect()
{
    if (connection != NULL)
        XCloseDisplay(connection);
    VERBOSE("Disconnected to X Server.");
}