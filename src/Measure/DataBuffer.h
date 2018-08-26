#pragma once

#include <Arduino.h>

namespace MuzicAnalyser { namespace Measure 
{
    struct DataBuffer final
    {
        enum Channel
        {
            CH_LEFT = 0,
            CH_RIGHT = 1,
            CH_REAR_LEFT = 2,
            CH_REAR_RIGHT = 3,
            CH_CENTER = 5,
            CH_SUBWOOFER = 6
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