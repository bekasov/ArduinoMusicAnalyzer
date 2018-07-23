#pragma once

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

#include <VuMeter.h>
#include "IDisplay.h"

namespace MuzicAnalyser { namespace Display 
{
    class LedMatrix : public IDisplay<VuMeter::VuMeterDisplayData>
    {
    private:
        Max72xxPanel* matrix;

    public:
        LedMatrix(byte brightness = 4, byte verticalDisplays = 1, byte horizontalDisplays = 1, byte pinCs = 10);
        ~LedMatrix();

        void OutValues(const VuMeter::VuMeterDisplayData* data,  int valuesMax);
    };

} }