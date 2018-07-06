#pragma once
#include <string>
#include <iostream>
#include <chrono>

class _Serial
{
public:
    // ready check for the serial port
    operator bool() const
    {
        return true; // always ready when mocking
    }; 

    void begin(int port)
    {
        return; // intentionally void
    }

    void println(std::string s)
    {
        this->print(s);
        std::cout << "\r\n";
    }

    void print(std::string s)
    {
        std::cout << s;
    }

    void println(int s)
    {
        this->print(std::to_string(s));
        std::cout << "\r\n";
    }

    void print(int s)
    {
        std::cout << std::to_string(s);
    }
};
_Serial Serial;

int digitalRead(int slotIndex)
{
    return 1; // intentionally void
}

void delay(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int digitalPinToInterrupt(int pin)
{
    return pin;
}

enum PinMode
{
    INPUT,
    OUTPUT,
    INPUT_PULLUP
};
void pinMode(int pin, PinMode mode)
{
    return; // intentionally void
}

void digitalWrite(int pin, int value)
{
    return;
}

enum SignalDirection
{
    LOW,
    CHANGE,
    RISING,
    FALLING
};

typedef void(*voidFunction)();
void attachInterrupt(int interruptIndex, voidFunction function, SignalDirection direction)
{

}