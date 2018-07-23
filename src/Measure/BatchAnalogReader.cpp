#include "BatchAnalogReader.h"
#include <Arduino.h>

namespace MuzicAnalyser { namespace Measure 
{
    vector<int16_t> BatchAnalogReader::GetMaxForPeriod(uint16_t numberOfMeasures)
    {
        vector<int16_t> result;
        
        int16_t maxValue = 0;
        for (uint16_t i = 0; i < numberOfMeasures; i++)
        {
            for (const uint8_t& analogInput : this->analogInputs)
            {
                maxValue = max(analogRead(analogInput), maxValue);
            }

            result.push_back(maxValue);
        }
        
        return result;
    }
} }