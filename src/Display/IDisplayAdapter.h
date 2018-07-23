#pragma once

#include <Arduino.h>

namespace MuzicAnalyser { namespace Display 
{
    struct Point
    {
        int16_t x;
        int16_t y;
    };

    class IDisplayAdapter
    {
    public:
        virtual void DrawRectangle(Point p0, Point p1) = 0;
        virtual void SetBrightness(int8_t value) = 0;
        virtual void Clear() = 0;
        virtual void FlushBuffer() = 0;
        virtual uint16_t GetDisplaySize(bool vertical) = 0;
        virtual ~IDisplayAdapter() {}
    };
} }