#include "platform/esp_server.hpp"

ESPServer::ESPServer() : server(port), ws("/ws")
{
}


void ESPServer::begin(const int port) 
{
    Serial.begin(9600);
    
    // init wifi
    WiFi.softAP(ssid);
    Serial.println("IP Address: ");
    Serial.println(WiFi.softAPIP());

    // init little FS
    if (!LittleFS.begin(true))
    {
        Serial.println("An error has occurred while mounting LittleFS");
    }
    Serial.println("LittleFS mounted successfully");

    // init websocket
    ws.onEvent([this](AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, 
        void *arg, uint8_t *data, size_t len) {
        
            this->onEvent(server, client, type, arg, data, len);
    });

    server.addHandler(&ws);

    // server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
    //           { request->send(LittleFS, "/index.html", "text/html"); });

    server.serveStatic("/", LittleFS, "/");

    // Start server
    server.begin();

    // server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
    // { request->send(LittleFS, "/index.html", "text/html"); });
}

void ESPServer::get(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) 
{
    const char * c_path = path.c_str();

    // Web Server Root URL
    server.on(c_path, HTTP_GET, [handler](AsyncWebServerRequest *request)
    { 
        // populate server request from async web server request
        ServerRequest sr;
        
        // strings
        sr.method = request->method();  
        sr.path = request->url().c_str();  
        
        // sr.body;


        int headers = request->headers();
        for(int i = 0; i < headers; i++)
        {
            AsyncWebHeader* h = request->getHeader(i);
            sr.headers[h->name().c_str()] = h->value().c_str();
        }

        ServerResponse response = handler(sr);

        // transfor it back to the thing that espserver needs under the hood
        // AsyncWebServerResponse transformed;

        // return transformed;
    });
}

ServerResponse ESPServer::sendRequest(ServerRequest srq) 
{
    // const String s = String(srq.path);
    // AsyncWebServerRequest request((this->server), s);

    // int method;
    // std::string path;
    // std::string body;
    // std::unordered_map<std::string, std::string> headers;

    Serial.println("Sending LittleFS Request");
    request.send(LittleFS, "/index.html", "text/html");

    ServerResponse s;
    return s;
}


void ESPServer::sendTest() {
    if ((millis() - lastTime) > timerDelay)
    {
        readings["temperature"] = String(millis());
        readings["humidity"] = String(millis() * 0.5f);
        readings["pressure"] = String(millis() * 0.25f);

        String sensorReadings = JSON.stringify(readings);

        Serial.print(sensorReadings);
        
        // notify the clients
        ws.textAll(sensorReadings);

        lastTime = millis();
    }
    
    ws.cleanupClients();
}

// void ESPServer::onNotFound(std::function<ServerResponse(ServerRequest)> handler) {
//     // no op
// }

// void ESPServer::onOpen(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) {
//     // no op
// }

// void ESPServer::onClose(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) {
//     // no op
// }

void ESPServer::onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
{
    switch (type)
    {
    case WS_EVT_CONNECT:
        Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
        break;
    case WS_EVT_DISCONNECT:
        Serial.printf("WebSocket client #%u disconnected\n", client->id());
        break;
    case WS_EVT_DATA:
        // AwsFrameInfo *info = (AwsFrameInfo *)arg;
        
        // if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT)
        // {
        //     String sensorReadings = getSensorReadings();
        //     Serial.print(sensorReadings);
        //     notifyClients(sensorReadings);
        // }
        break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
        break;
    }
}