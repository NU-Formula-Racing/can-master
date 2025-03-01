#ifndef __ESP_SERVER_H__
#define __ESP_SERVER_H__

#ifdef ARDUINO_ARCH_ESP32

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "LittleFS.h"
#include <Arduino_JSON.h>

#include <web_server_interface.hpp>

class ESPServer : public IWebServer {

   // Replace with your network credentials
   const char *ssid = "NFR25_Monitor";
   const char *password = "GoCats!";
   const int64_t port = 80; 

   // Create AsyncWebServer object on port 80
   AsyncWebServer server;

   // Create a WebSocket object
   AsyncWebSocket ws;

   // Json Variable to Hold Sensor Readings
   JSONVar readings;

   // Timer variables
   unsigned long lastTime = 0;
   unsigned long timerDelay = 1000;

   public:
      ESPServer();

      void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);

      void begin(const int port) override;

      void sendTest() override;

      ServerResponse sendRequest(ServerRequest srq) override;
   
      void get(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override;
      // virtual void post(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;
      // virtual void put(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;
      // virtual void del(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) = 0;

      // void onOpen(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override;
      // void onClose(const std::string &path, std::function<ServerResponse(ServerRequest)> handler) override;

      // void onNotFound(std::function<ServerResponse(ServerRequest)> handler) override;
};


#endif // ARDUINO_
#endif  // __ESP_SERVER_H__