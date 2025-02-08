#ifndef __NATIVE_SERVER_H__
#define __NATIVE_SERVER_H__

#include <iostream>
#include <set>
#include <string> 

#include <boost/version.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include <nlohmann/json.hpp>
#include <web_server_interface.hpp>

typedef websocketpp::server<websocketpp::config::asio> server;

using websocketpp::connection_hdl;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

using json = nlohmann::json;
using namespace std;

class NativeServer : public IWebServer
{
public:
    typedef std::set<connection_hdl, std::owner_less<connection_hdl>> con_list;
    server m_server;
    con_list m_connections;
    json readings;

    
    // ServerResponse transformResponse(void *response) override
    // {
    // }

    // ServerRequest transformRequest(void *request) override
    // {
    // }

    void onOpen(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override
    {
        m_connections.insert(hdl);
    }

    void onClose(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override
    {
        m_connections.erase(hdl);
    }

    void begin(const int port) override 
    {
        m_server.init_asio();

        m_server.set_open_handler(bind(&broadcast_server::on_open, this, ::_1));
        m_server.set_close_handler(bind(&broadcast_server::on_close, this, ::_1));

        m_server.listen(port);
        m_server.start_accept();
        m_server.run();
    }

    // void get(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override;
    // void post(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override 
    // {

    // }

    // void put(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override;

    // void del(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override 
    // {
    //     m_connections.erase(hdl);
    // }

    // void onNotFound(std::function<ServerResponse(ServerRequest)> handler) override;


};

#endif // __NATIVE_SERVER_H__