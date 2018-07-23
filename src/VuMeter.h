#pragma once

#include <Arduino.h>
#include <vector>

#include "Display/IDisplayAdapter.h"
#include "Measure/BatchAnalogReader.h"

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

        struct VuMeterMeasuringSettings
        {
            uint16_t numberOfMeasures = 100;
            uint16_t normalizationRange = 1000;
            uint16_t lowPass = 20;
        };

        VuMeter(BatchAnalogReader* measurer);
        ~VuMeter();

        void Measure(uint16_t numberOfMeasures);
        void Draw(IDisplayAdapter* display, uint16_t lowPass, uint16_t maxWidth);

    private: 
        BatchAnalogReader* measurer;
        vector<int16_t> currentValues;
    };
}