#pragma once

#include <Arduino.h>
#include <vector>
#include <wiring_private.h>

namespace MuzicAnalyser { namespace Measure 
{
    using namespace std;

    class BatchAnalogReader final
    {
    public:
        static const uint32_t ANALOG_READ_MAX_VALUE = 1023;

    private:
        vector<uint8_t> analogInputs;

    public:
        BatchAnalogReader(vector<uint8_t> analogInputs) 
        {
            this->analogInputs = analogInputs;
        }

        vector<int16_t> GetMaxForPeriod(uint16_t numberOfMeasures);
    };
} }