#pragma once

#include <Arduino.h>

namespace MuzicAnalyser { namespace Display 
{
    class IVuMeterDisplay
    {
    public:
        virtual void Display(uint16_t leftChannelCurrent, uint16_t rightChannelCurrent) = 0;
        virtual uint16_t GetMaxColumnLength() = 0;
        virtual void SetBrightness(uint8_t brightness) = 0;
        virtual ~IVuMeterDisplay() {}
    };
} }
