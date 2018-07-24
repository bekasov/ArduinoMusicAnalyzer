#include <Arduino.h>
#include "Max72xxVuMeterDisplay.h"

namespace MuzicAnalyser { namespace Display 
{ 
    Max72xxVuMeterDisplay::Max72xxVuMeterDisplay(Max72xxPanel* display, int8_t brightness)
    {
        this->display = display;
        this->display->setIntensity(brightness);
    }

    void Max72xxVuMeterDisplay::Display(uint16_t leftChannelCurrent, uint16_t rightChannelCurrent)
    {
        this->display->fillScreen(LOW);

        this->display->drawLine(5, 0, 5, leftChannelCurrent, HIGH);
        this->display->drawLine(6, 0, 6, leftChannelCurrent, HIGH);

        this->display->drawLine(1, 0, 1, rightChannelCurrent, HIGH);
        this->display->drawLine(2, 0, 2, rightChannelCurrent, HIGH);

        this->display->write();
    }

    uint16_t Max72xxVuMeterDisplay::GetMaxColumnLength()
    { 
        return this->display->width(); 
    }

    void Max72xxVuMeterDisplay::SetBrightness(uint8_t brightness)
    {
        this->display->setIntensity(brightness);
    }

    Max72xxVuMeterDisplay::~Max72xxVuMeterDisplay()
    {
    }
} }