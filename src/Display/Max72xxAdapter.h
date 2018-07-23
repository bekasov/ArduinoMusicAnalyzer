#pragma once

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

#include "IDisplayAdapter.h"

namespace MuzicAnalyser { namespace Display 
{
    class Max72xxAdapter final : public IDisplayAdapter 
    {
    private:
        Max72xxPanel* panel;

    public:
        Max72xxAdapter(Max72xxPanel* max72xxPanel);
        void DrawRectangle(Point p0, Point p1) override;
        void SetBrightness(int8_t value) override;
        void Clear() override;
        void FlushBuffer() override;
        uint16_t GetDisplaySize(bool vertical = false) override;

        ~Max72xxAdapter() override;    
    };
} }