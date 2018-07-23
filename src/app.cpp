#include <Arduino.h>
#include <vector>

#include "app.h"

namespace MuzicAnalyser 
{
    void App::Setup()
    {
        // this->display = new LedMatrix();

        unsigned char LEFT_CHANNEL = A1;
        unsigned char RIGHT_CHANNEL = A2;
        std::vector<unsigned char> analogInputs = { LEFT_CHANNEL, RIGHT_CHANNEL };
        this->measurer = new ValuesForPeriod(analogInputs);
    }

    void App::Run()
    {
        // int LOW_PASS = 20;
        // int ANALOG_READ_MAX_VALUE = 1023;
        // int NORMALIZATION_BOUND = 1000;
        // byte NUMBER_OF_MEASURES = 100;

        // std::vector<long> currentValues = this->measurer->GetCurrent(NUMBER_OF_MEASURES);
        // for (long& currentValue : currentValues)
        // {
        //     currentValue = abs(map(currentValue, LOW_PASS, ANALOG_READ_MAX_VALUE, 0, NORMALIZATION_BOUND));
        // }

        // this->display->OutValues(currentValues[0], currentValues[1], NORMALIZATION_BOUND);
    }

    App::~App()
    {
        if (this->display != nullptr)
        {
            delete this->display;
        }
    }
}
