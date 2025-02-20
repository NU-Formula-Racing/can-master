#include "platform/esp_server.hpp"

ESPServer::ESPServer() : server(port), ws("/ws")
{
}

String ESPServer::getSensorReadings()
{
    readings["temperature"] = String(millis());
    readings["humidity"] = String(millis() * 0.5f);
    readings["pressure"] = String(millis() * 0.25f);
    String jsonString = JSON.stringify(readings);
    return jsonString;
}

void ESPServer::initLittleFS()
{
    if (!LittleFS.begin(true))
    {
    Serial.println("An error has occurred while mounting LittleFS");
    }
    Serial.println("LittleFS mounted successfully");
}

void ESPServer::initWiFi() {
    WiFi.softAP(ssid);
    Serial.println("IP Address: ");
    Serial.println(WiFi.softAPIP());
}

void ESPServer::notifyClients(String sensorReadings)
{
    ws.textAll(sensorReadings);
}

void ESPServer::handleWebSocketMessage(void *arg, uint8_t *data, size_t len)
{
    AwsFrameInfo *info = (AwsFrameInfo *)arg;
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT)
    {
    String sensorReadings = getSensorReadings();
    Serial.print(sensorReadings);
    notifyClients(sensorReadings);
    }
}


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
        handleWebSocketMessage(arg, data, len);
        break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
        break;
    }
}

void ESPServer::initWebSocket()
{
    ws.onEvent([this](AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, 
                  void *arg, uint8_t *data, size_t len) {
        this->onEvent(server, client, type, arg, data, len);
    });
    server.addHandler(&ws);
}

void ESPServer::begin(const int port) 
{
    Serial.begin(9600);
    initWiFi();
    initLittleFS();
    initWebSocket();

    // Web Server Root URL
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(LittleFS, "/index.html", "text/html"); });

    server.serveStatic("/", LittleFS, "/");

    // Start server
    server.begin();
    
}

void ESPServer::sendTest() {
    if ((millis() - lastTime) > timerDelay)
    {
        String sensorReadings = getSensorReadings();
        Serial.print(sensorReadings);
        notifyClients(sensorReadings);
        lastTime = millis();
    }
    ws.cleanupClients();
}

void ESPServer::onNotFound(std::function<ServerResponse(ServerRequest)> handler) {
    // no op
}

void ESPServer::onOpen(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) {
    // no op
}

void ESPServer::onClose(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) {
    // no op
}