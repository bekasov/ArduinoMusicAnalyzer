#pragma once
#include <Arduino.h>
#include <vector>
#include <wiring_private.h>
// #include <functional>

namespace MuzicAnalyser { namespace Measure 
{
    using namespace std;

    class ValuesForPeriod final
    {
    private:
        vector<uint8_t> analogInputs;
        // binary_function<long,long,long> comparer;
        // function<long(long,long)> comparer;
        // long (*comparer)(long, long);

    public:
        ValuesForPeriod(vector<uint8_t> analogInputs) 
        {
            this->analogInputs = analogInputs;

            sbi(ADCSRA, ADPS2);
            cbi(ADCSRA, ADPS1);
            sbi(ADCSRA, ADPS0);
            analogReference(INTERNAL); //  EXTERNAL
        }

        vector<int16_t> GetCurrent(uint16_t numberOfMeasures);
    };
} }