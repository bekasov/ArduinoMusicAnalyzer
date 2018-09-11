#pragma once
#include <Arduino.h>


namespace Calculation { namespace Fft
{
    class IFftWrapper
    {
    public:
        virtual uint8_t* CalculateFft(int16_t* const data) = 0;
        virtual ~IFftWrapper() = default;
    };
} }