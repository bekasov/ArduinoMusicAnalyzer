#pragma once

#include <Arduino.h>

namespace MuzicAnalyser { namespace Display 
{
    template<class TData> class IDisplay
    {
    public:
        virtual void Display(const TData* data, uint32_t maxValue) = 0;
        virtual ~IDisplay() {}
    };
} }
