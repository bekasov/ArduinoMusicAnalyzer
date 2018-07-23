#include <vector>

#include "VuMeter.h"

namespace MuzicAnalyser
{
    using namespace std;

    VuMeter::VuMeter(ValuesForPeriod* measurer)
    {
        this->measurer = measurer;
    }

    void VuMeter::MeasureAndDisplay(IDisplay<VuMeterDisplayData>* displayDriver)
    {
        vector<int16_t> currentValues = this->measurer->GetCurrent(this->NUMBER_OF_MEASURES);
        for (int16_t& currentValue : currentValues)
        {
            currentValue = abs(map(currentValue, this->LOW_PASS, this->ANALOG_READ_MAX_VALUE, 0, this->NORMALIZATION_RANGE));
        }

        VuMeterDisplayData dataToDisplay = { .leftChannelCurrentValue = currentValues[0], .rightChannelCurrentValue = currentValues[1] };

        displayDriver->Display(&dataToDisplay, this->NORMALIZATION_RANGE);
    }

    VuMeter::~VuMeter()
    {
        if (this->measurer != nullptr)
        {
            delete this->measurer;
        }
    }
}