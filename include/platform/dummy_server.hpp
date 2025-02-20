#ifndef __DUMMY_SERVER_H__
#define __DUMMY_SERVER_H__

#include <string.h>

#include <functional>
#include <web_server_interface.hpp>

class DummyServer : public IWebServer {
   public:
    virtual void begin(const int port) = 0;

    virtual void onOpen(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;
    virtual void onClose(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;

    // virtual void get(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;
    // virtual void post(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;
    // virtual void put(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;
    // virtual void del(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;

    virtual void onNotFound(std::function<ServerResponse(ServerRequest)> handler) = 0;
};

#endif  // __DUMMY_SERVER_H__