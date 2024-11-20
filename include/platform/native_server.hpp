#ifndef __NATIVE_SERVER_H__
#define __NATIVE_SERVER_H__

#include <web_server_interface.hpp>
#include <httplib/httplib.h>

using NativeResponse = httplib::Response;
using NativeRequest = httplib::Request;

class NativeServer : public IWebServer
{
public:
    ServerResponse transformResponse(void *response) override
    {
        NativeResponse *native_response = (NativeResponse *)response;
        ServerResponse server_response;
        server_response.status = native_response->status;
        server_response.body = native_response->body;

    }

    ServerRequest transformRequest(void *request) override
    {
    }

    void on(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override;
    void begin() override;

    void get(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override;
    void post(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override;
    void put(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override;
    void del(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override;

    void onNotFound(std::function<ServerResponse(ServerRequest)> handler) override;
};

#endif // __NATIVE_SERVER_H__