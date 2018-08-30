#include "VuMeter.h"
#include "Display/IVuMeterDisplay.h"

namespace MuzicAnalyser
{
    using namespace std;

    VuMeter::VuMeter(BatchAnalogReader* measurer, VuMeterSettings* settings)
    {
        this->measurer = measurer;
        this->settings = settings;
    }

    void VuMeter::Draw(DataBuffer* const data)
    {
        const uint8_t CHANNELS_NUMBER = 2;
        uint16_t currentValues[CHANNELS_NUMBER];

        for (uint8_t channel = 0; channel < CHANNELS_NUMBER; channel++)
        {
            uint16_t currentMaxValue = 0;
            for (uint16_t valueNumber = 0; valueNumber < data->numberOfMeasures; valueNumber++)
            {
                int16_t currentValue = data->data[channel][valueNumber];
                currentMaxValue = max((uint16_t)abs(currentValue), currentMaxValue);
            }
            currentValues[channel] = currentMaxValue;
        }

        for (IVuMeterDisplay* const display : this->displays)
        {
            uint16_t currentDisplayValues[CHANNELS_NUMBER];
            uint16_t currentDisplayMaxLevel = display->GetMaxColumnLength();

            for (uint8_t channel = 0; channel < CHANNELS_NUMBER; ++channel)
            {
                currentDisplayValues[channel] = map(
                    currentValues[channel], 
                    this->settings->lowPass, 
                    data->offset, 
                    0, 
                    currentDisplayMaxLevel);
                
                if (currentDisplayValues[channel] < 0) 
                {
                    currentDisplayValues[channel] = 0;
                }
            }

            if (this->settings->mono)
            {
                uint16_t maxValue = max(currentDisplayValues[0], currentDisplayValues[1]);
                currentDisplayValues[0] = maxValue;
                currentDisplayValues[1] = maxValue;
            }

            display->Display(currentDisplayValues[0], currentDisplayValues[1]);
        }
    }

    void VuMeter::AddDisplay(IVuMeterDisplay* display)
    {
        this->displays.push_back(display);
    }

    VuMeter::~VuMeter()
    {
    }
}