#ifndef __SENSOR_H__
#define __SENSOR_H__

#include <functional>

#ifndef NATIVE
#include <CAN.h>
#define CAN_SUPPORTED
#endif  // !NATIVE

template <typename T>
class Sensor {
   public:
#ifdef CAN_SUPPORTED
    template <typename CAN_MSG_T>
    static Sensor<CAN_MSG_T> fromCAN(CANSignal &signal) {
        std::function<CAN_MSG_T()> read = [signal]() {
            return (CAN_MSG_T)signal;
        };

        return Sensor<CAN_MSG_T>(read);
    }
#endif  // CAN_SUPPORTED

    template <typename U>
    static Sensor<U> fromFunction(std::function<U()> read) {
        return Sensor<U>(read);
    }

    Sensor(std::function<T()> read) : _read(read) {}
    T read() { return _read(); }

   private:
    std::function<T()> _read;
};

// Helper macro to create a sensor from a CAN signal or a default value
#define SENSOR_CAN_OR_DEFAULT(type, can_signal, default_value) \
    (can_signal ? Sensor<type>::fromCAN<type>(can_signal) : Sensor<type>::fromFunction<type>([default_value]() { return default_value; }))

// Helper macro to create a sensor from a CAN signal or random value within a range
#define SENSOR_CAN_OR_RANDOM(type, can_signal, min, max) \
    (can_signal ? Sensor<type>::fromCAN<type>(can_signal) : Sensor<type>::fromFunction<type>([min, max]() { return random(min, max); }))

// Helper macro to create a sensor from a CAN signal or a oscillating value within a range
#define SENSOR_CAN_OR_OSCILLATE(type, can_signal, min, max, period) \
    (can_signal ? Sensor<type>::fromCAN<type>(can_signal) : Sensor<type>::fromFunction<type>([min, max, period]() { return min + (max - min) * (1 + sin(millis() * 2 * PI / period)) / 2; }))

#endif  // __SENSOR_H__