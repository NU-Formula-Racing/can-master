#ifndef __SERVER_H__
#define __SERVER_H__

#ifdef NATIVE
#include <platform/native_server.hpp>
#define Server NativeServer

#elif defined(ARDUINO_ARCH_ESP32)
#include <platform/esp_server.hpp>
#define Server ESPServer

#else
#include <platform/dummy_server.hpp>
#define Server DummyServer

#endif  // NATIVE


#endif // __SERVER_H__