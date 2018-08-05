#include "BatchAnalogReader.h"
#include <Arduino.h>

namespace MuzicAnalyser { namespace Measure 
{
    void BatchAnalogReader::FillData(DataBuffer* const dataBuffer)
    {
        for (uint16_t measureNum = 0; measureNum < dataBuffer->numberOfMeasures; measureNum++)
        {
            for (uint8_t inputNum = 0; inputNum < dataBuffer->channelsNumber; inputNum++)
            {
                int16_t currentValue = analogRead(this->analogInputs[inputNum]) - dataBuffer->offset;
                dataBuffer->GetChannelData(dataBuffer->GetChannelNameByNumber(inputNum))[measureNum] = currentValue;
            }
        }
    }
} }