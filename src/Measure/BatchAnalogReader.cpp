#include "BatchAnalogReader.h"
#include <Arduino.h>

namespace MuzicAnalyser { namespace Measure 
{
    void BatchAnalogReader::FillData(DataBuffer* const dataBuffer)
    {
        for (uint16_t measureNum = 0; measureNum < dataBuffer->numberOfMeasures; measureNum++)
        {
            int16_t currentSum = 0;
            for (uint8_t inputNum = 0; inputNum < dataBuffer->channelsNumber; inputNum++)
            {
                int16_t currentValue = analogRead(this->analogInputs[inputNum]) - dataBuffer->offset;
                // dataBuffer->GetChannelData(dataBuffer->GetChannelNameByNumber(inputNum))[measureNum] = currentValue;
                dataBuffer->data[inputNum][measureNum] = currentValue;
                currentSum += currentValue;
            }
            dataBuffer->sumDataBuffer[measureNum] = currentSum; // / dataBuffer->channelsNumber;
        }
    }
} }