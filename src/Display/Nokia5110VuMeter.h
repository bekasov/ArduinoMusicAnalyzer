#pragma once
#include <Arduino.h>
#include <LCD5110_Graph.h>
#include "IVuMeterDisplay.h"


namespace MuzicAnalyser { namespace Display 
{
    class Nokia5110VuMeter final : public IVuMeterDisplay
    {
    public:
        Nokia5110VuMeter(LCD5110* display);
        ~Nokia5110VuMeter() {}

        void Display(uint16_t leftChannelCurrent, uint16_t rightChannelCurrent) override;
        uint16_t GetMaxColumnLength() override;
        void SetBrightness(uint8_t brightness) override;

    private:
        LCD5110* display;

        uint16_t previousLeft;
        uint16_t previousRight;
    };
} }