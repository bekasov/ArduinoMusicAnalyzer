#pragma once

#include <Arduino.h>

namespace MuzicAnalyser { namespace Display 
{
    template<class TData> class IDisplay
    {
    public:
        virtual void Display(const TData* data) = 0;
        virtual ~IDisplay() {}
    };
} }
