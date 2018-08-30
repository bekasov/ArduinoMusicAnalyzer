#pragma once

#include <Arduino.h>

namespace MuzicAnalyser { namespace Display 
{
    class IFftDisplay
    {
    public:
        virtual void Display(uint8_t* fftData, uint16_t fftDataCount) = 0;
        virtual uint16_t GetMaxLevelHeight() = 0;
        virtual ~IFftDisplay() {}
    };
} }