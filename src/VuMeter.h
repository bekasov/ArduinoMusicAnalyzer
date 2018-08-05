#pragma once

#include <Arduino.h>
#include <vector>

#include "Display/IVuMeterDisplay.h"
#include "Measure/BatchAnalogReader.h"
#include "Measure/DataBuffer.h"

namespace MuzicAnalyser
{
    using namespace Display;
    using namespace Measure;

    class VuMeter final
    {
    public:
        struct VuMeterSettings
        {
            uint16_t lowPass;
            bool mono;
        };

        VuMeter(BatchAnalogReader* measurer, VuMeterSettings* settings);
        ~VuMeter();

        void AddDisplay(IVuMeterDisplay* display);
        void Draw(DataBuffer* const data);

    private: 
        BatchAnalogReader* measurer;
        VuMeterSettings* settings;
        vector<IVuMeterDisplay*> displays;
    };
}