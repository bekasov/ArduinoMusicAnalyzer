#pragma once
#include <Arduino.h>
#include <vector>
#include <wiring_private.h>

#include "DataBuffer.h"


namespace MuzicAnalyser { namespace Measure 
{
    using namespace std;

    class BatchAnalogReader final
    {
    private:
        vector<uint8_t> analogInputs;

    public:
        BatchAnalogReader(vector<uint8_t> analogInputs) 
        {
            this->analogInputs = analogInputs;
        }

        void FillData(DataBuffer* const dataBuffer);
    };
} }