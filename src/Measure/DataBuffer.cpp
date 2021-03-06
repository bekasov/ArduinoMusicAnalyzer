#include "DataBuffer.h"
#include "../app.h"


namespace MuzicAnalyser { namespace Measure 
{
    DataBuffer::DataBuffer(const uint16_t& numberOfMeasures, const uint8_t& channelsNumber, const uint16_t& offset, int16_t* sumDataBuffer)
    {
        this->numberOfMeasures = numberOfMeasures;
        this->offset = offset;
        this->channelsNumber = channelsNumber;
        this->sumDataBuffer = sumDataBuffer;

        this->data = new int16_t*[this->channelsNumber];
        for (uint8_t channelNumber = 0; channelNumber < this->channelsNumber; ++channelNumber)
        {
            this->data[channelNumber] = new int16_t[this->numberOfMeasures];
        }

        if (sumDataBuffer != nullptr)
        {
            for (uint16_t measureNum = 0; measureNum < numberOfMeasures; ++measureNum)
            {
                sumDataBuffer[measureNum] = 0;
            }
        }
    }

    int16_t*& DataBuffer::GetChannelData(Channel channel)
    {
        return this->data[static_cast<uint8_t>(channel)];
    }

    DataBuffer::Channel DataBuffer::GetChannelNameByNumber(uint8_t channelNumber)
    {
        return static_cast<DataBuffer::Channel>(channelNumber);
    }

    DataBuffer::~DataBuffer()
    {        
        for(uint16_t channelNumber = 0; channelNumber < this->channelsNumber; ++channelNumber) 
        {
            delete[] this->data[channelNumber];
        }

        delete[] this->data;
    }
} }