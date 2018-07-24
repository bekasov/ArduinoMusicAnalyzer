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

    void VuMeter::MeasureAndDraw()
    {
        this->currentValues = this->measurer->GetMaxForPeriod(this->settings->numberOfMeasures);

        for (IVuMeterDisplay* display : this->displays)
        {
            for (int16_t& currentValue : this->currentValues)
            {
                currentValue = abs(map(
                    currentValue, 
                    this->settings->lowPass, 
                    this->measurer->ANALOG_READ_MAX_VALUE, 
                    0, 
                    display->GetMaxColumnLength()));
            }

            if (this->settings->mono)
            {
                int16_t maxValue = max(this->currentValues[0], this->currentValues[1]);
                this->currentValues[0] = maxValue;
                this->currentValues[1] = maxValue;
            }

            display->Display(this->currentValues[0], this->currentValues[1]);
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