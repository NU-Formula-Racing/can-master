#include <Arduino.h>

#include <web_server_interface.hpp>
#include <server.hpp>

Server server;

ServerResponse onGetRoot(ServerRequest request) {
    // return a response with index.html
    return server.sendRequest(request);
}

void setup()
{
    server.begin(80);
    server.get("/", onGetRoot);
}

void loop()
{
    server.sendTest();
}