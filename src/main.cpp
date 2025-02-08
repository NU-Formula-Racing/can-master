#include <Arduino.h>

#include <web_server_interface.hpp>
#include <server.hpp>

Server server;

void setup()
{
    server.begin(80);
}

void loop()
{
    server.sendTest();
}