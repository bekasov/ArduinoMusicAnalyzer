#pragma once

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

namespace Lib { namespace MatrixControl 
{
    class MatrixControl final
    {
    private:
        int pinCs = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
        int numberOfHorizontalDisplays = 1;
        int numberOfVerticalDisplays = 1;

        static const int pinRandom = A0;
        static const int wait = 100; // In milliseconds
        static const int length = 8;

        int x[length];
        int y[length];

        int ptr, nextPtr;

        Max72xxPanel* matrix;

    public:
        MatrixControl();
        ~MatrixControl();

        void Setup();
        void Run();

    private:
        bool occupied(int ptrA) 
        {
            for (int ptrB = 0 ; ptrB < this->length; ptrB++) {
                if (ptrA != ptrB) 
                {
                    if (this->equal(ptrA, ptrB))
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        int next(int ptr) 
        {
            return (ptr + 1) % this->length;
        }

        bool equal(int ptrA, int ptrB) 
        {
            return this->x[ptrA] == this->x[ptrB] && this->y[ptrA] == this->y[ptrB];
        }
    };
}}