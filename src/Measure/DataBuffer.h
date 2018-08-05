#pragma once

#include <Arduino.h>

namespace MuzicAnalyser { namespace Measure 
{
    struct DataBuffer final
    {
        enum Channel
        {
            LEFT = 0,
            RIGHT = 1,
            REAR_LEFT = 2,
            REAR_RIGHT = 3,
            CENTER = 5,
            SUBWOOFER = 6
        };

        DataBuffer(const uint16_t& numberOfMeasures, const uint8_t& channelsNumber, const uint16_t& offset);
        ~DataBuffer();

        int16_t*& GetChannelData(Channel channel);
        Channel GetChannelNameByNumber(uint8_t channelNumber);

        int16_t** data;

        uint16_t numberOfMeasures;
        uint8_t channelsNumber;
        uint16_t offset;
    };
} }