#include <Arduino.h>
#include <vector>

#include "app.h"
#include "Display/Max72xxAdapter.h"

namespace MuzicAnalyser 
{
    App* App::instance;

    void App::Setup()
    {
        // this->display = new LedMatrix();

        unsigned char LEFT_CHANNEL = A1;
        unsigned char RIGHT_CHANNEL = A2;
        std::vector<uint8_t> analogInputs = { LEFT_CHANNEL, RIGHT_CHANNEL };
        this->analogReader = new BatchAnalogReader(analogInputs);

        this->vuMeter = new VuMeter(this->analogReader);
        byte brightness = 4;
        byte verticalDisplays = 1;
        byte horizontalDisplays = 1;
        byte pinCs = 10;

        this->display = new Max72xxAdapter(new Max72xxPanel(pinCs, horizontalDisplays, verticalDisplays));
    }

    void App::Run()
    {
        int LOW_PASS = 20;
        int ANALOG_READ_MAX_VALUE = 1023;
        int NORMALIZATION_BOUND = 1000;
        byte NUMBER_OF_MEASURES = 100;

        // std::vector<long> currentValues = this->analogReader->GetCurrent(NUMBER_OF_MEASURES);
        // for (long& currentValue : currentValues)
        // {
        //     currentValue = abs(map(currentValue, LOW_PASS, ANALOG_READ_MAX_VALUE, 0, NORMALIZATION_BOUND));
        // }

        // this->display->OutValues(currentValues[0], currentValues[1], NORMALIZATION_BOUND);

        this->vuMeter->Measure(NUMBER_OF_MEASURES);

        this->vuMeter->Draw(this->display, LOW_PASS, this->display->GetDisplaySize(false));
    }

    App::~App()
    {
        if (this->display != nullptr)
        {
            delete this->display;
        }
    }
}
