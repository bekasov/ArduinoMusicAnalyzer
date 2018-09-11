#pragma once
#include <Arduino.h>


namespace MuzicAnalyser { namespace Display 
{
    class IFftDisplay
    {
    public:
        virtual void Display(const uint8_t* fftData) = 0;
        virtual uint16_t GetMaxLevelHeight() = 0;
        virtual ~IFftDisplay() = default;
    };
} }