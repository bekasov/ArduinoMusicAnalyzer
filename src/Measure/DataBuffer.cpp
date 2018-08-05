#include "DataBuffer.h"

namespace MuzicAnalyser { namespace Measure 
{
    DataBuffer::DataBuffer(const uint16_t& numberOfMeasures, const uint8_t& channelsNumber, const uint16_t& offset)
    {
        this->numberOfMeasures = numberOfMeasures;
        this->offset = offset;
        this->channelsNumber = channelsNumber;

        this->data = new uint16_t*[this->channelsNumber];
        for (uint8_t channelNumber = 0; channelNumber < this->channelsNumber; ++channelNumber)
        {
            this->data[channelNumber] = new uint16_t[this->numberOfMeasures];
        }
    }

    uint16_t*& DataBuffer::GetChannelData(Channel channel)
    {
        return this->data[static_cast<uint8_t>(channel)];
    }

    DataBuffer::Channel DataBuffer::GetChannelNameByNumber(uint16_t channelNumber)
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