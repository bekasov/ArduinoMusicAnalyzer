#pragma once

#include <Arduino.h>

#include "Display/IDisplay.h"
#include "Measure/ValuesForPeriod.h"

namespace MuzicAnalyser
{
    using namespace Display;
    using namespace Measure;

    class VuMeter final
    {
    public:
        struct VuMeterDisplayData
        {
            int16_t leftChannelCurrentValue;
            int16_t rightChannelCurrentValue;
        };

        VuMeter(ValuesForPeriod* measurer);
        ~VuMeter();

        void MeasureAndDisplay(IDisplay<VuMeterDisplayData>* displayDriver);

    private: 
        static const uint16_t NUMBER_OF_MEASURES = 100;
        static const uint32_t ANALOG_READ_MAX_VALUE = 1023;
        static const uint32_t NORMALIZATION_RANGE = 1000;
        static const int16_t LOW_PASS = 20;

        ValuesForPeriod* measurer;
    };
}