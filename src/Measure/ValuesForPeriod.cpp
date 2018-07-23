#include "ValuesForPeriod.h"
#include <Arduino.h>

namespace MuzicAnalyser { namespace Measure 
{
    vector<int16_t> ValuesForPeriod::GetCurrent(uint16_t numberOfMeasures)
    {
        vector<int16_t> result;
        for (const uint8_t& analogInput : this->analogInputs)
        {
            int16_t maxValue = 0;
            for (uint16_t i = 0; i < numberOfMeasures; i++)
            {
                maxValue = max(analogRead(analogInput), maxValue);
            }

            result.push_back(maxValue);
        }

        return result;
    }
} }