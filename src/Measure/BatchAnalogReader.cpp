#include "BatchAnalogReader.h"
#include <Arduino.h>


namespace MuzicAnalyser { namespace Measure 
{
    void BatchAnalogReader::FillData(DataBuffer* const dataBuffer)
    {
        uint16_t measureNum = 0;
        do
        {
            uint8_t channelNum = 0;
            do
            {
                int16_t currentValue = analogRead(this->analogInputs[channelNum]) - dataBuffer->offset;
                dataBuffer->data[channelNum][measureNum] = currentValue;
                dataBuffer->sumDataBuffer[measureNum] += currentValue;// >> 1;
                channelNum++;
            }
            while (channelNum < dataBuffer->channelsNumber);
            measureNum++;
        }
        while (measureNum < dataBuffer->numberOfMeasures);
    }
} }