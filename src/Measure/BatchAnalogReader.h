#pragma once

#include <Arduino.h>
#include <vector>
#include <wiring_private.h>
// #include <functional>

namespace MuzicAnalyser { namespace Measure 
{
    using namespace std;

    class BatchAnalogReader final
    {
    public:
        static const uint32_t ANALOG_READ_MAX_VALUE = 1023;

    private:
        vector<uint8_t> analogInputs;

    public:
        BatchAnalogReader(vector<uint8_t> analogInputs) 
        {
            this->analogInputs = analogInputs;

            sbi(ADCSRA, ADPS2);
            cbi(ADCSRA, ADPS1);
            sbi(ADCSRA, ADPS0);
            analogReference(INTERNAL); //  EXTERNAL
        }

        vector<int16_t> GetMaxForPeriod(uint16_t numberOfMeasures);
    };
} }