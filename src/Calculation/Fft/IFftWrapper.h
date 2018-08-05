#pragma once

#include <Arduino.h>

namespace Calculation { namespace Fft
{
    class IFftWrapper
    {
    public:
        virtual void CalculateFft(int16_t* const data, uint8_t*& result) = 0;
        virtual ~IFftWrapper() {};
    };
} }