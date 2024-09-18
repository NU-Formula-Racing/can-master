#ifndef __WEB_SERVER_INTERFACE_H__
#define __WEB_SERVER_INTERFACE_H__


#include <string>
#include <unordered_map>
#include <functional>

struct ServerRequest
{
    std::string method;
    std::string path;
    std::string body;
    std::unordered_map<std::string, std::string> headers;
};

struct ServerResponse
{
    int status;
    std::string body;
    std::unordered_map<std::string, std::string> headers;
};

class IWebServer
{
public:
    // Because we are trying to combine two http server implementations into one interface, we need to be able to transform the request and response objects
    // this way we can have a common interface for both implementations
    virtual ServerResponse transformResponse(void *response) = 0;
    virtual ServerRequest transformRequest(void *request) = 0;

    virtual void on(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;
    virtual void begin() = 0;

    virtual void get(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;
    virtual void post(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;
    virtual void put(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;
    virtual void del(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;

    virtual void onNotFound(std::function<ServerResponse(ServerRequest)> handler) = 0;
};

#endif // __WEB_SERVER_INTERFACE_H__