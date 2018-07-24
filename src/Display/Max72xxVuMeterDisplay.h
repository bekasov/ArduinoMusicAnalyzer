#pragma once

#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

#include "IVuMeterDisplay.h"

namespace MuzicAnalyser { namespace Display 
{
    class Max72xxVuMeterDisplay final : public IVuMeterDisplay
    {
    private:
        Max72xxPanel* display;

    public:
        Max72xxVuMeterDisplay(Max72xxPanel* display, int8_t brightness);
        ~Max72xxVuMeterDisplay();

        void Display(uint16_t leftChannelCurrent, uint16_t rightChannelCurrent) override;
        uint16_t GetMaxColumnLength() override;
        void SetBrightness(uint8_t brightness) override;
    };
} }