#include "VuMeter.h"

namespace MuzicAnalyser
{
    using namespace std;

    VuMeter::VuMeter(BatchAnalogReader* measurer)
    {
        this->measurer = measurer;
    }

    void VuMeter::Measure(uint16_t numberOfMeasures)
    {
        // this->currentValues.clear();
        this->currentValues = this->measurer->GetMaxForPeriod(numberOfMeasures);
    }

    void VuMeter::Draw(IDisplayAdapter* display, uint16_t lowPass, uint16_t maxWidth)
    {
        for (int16_t& currentValue : this->currentValues)
        {
            currentValue = abs(map(currentValue, lowPass, this->measurer->ANALOG_READ_MAX_VALUE, 0, maxWidth));
        }

        // display->Clear();

        display->DrawRectangle(Display::Point { .x = 5, .y = 0 }, Display::Point { .x = 6, .y = this->currentValues[0] });
        display->DrawRectangle(Display::Point { .x = 1, .y = 0 }, Display::Point { .x = 2, .y = this->currentValues[1] });

        // display->FlushBuffer();
    }

    VuMeter::~VuMeter()
    {
        if (this->measurer != nullptr)
        {
            delete this->measurer;
        }
    }
}