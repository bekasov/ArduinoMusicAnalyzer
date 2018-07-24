#include <Arduino.h>
#include <vector>

#include "app.h"
#include "Display/Max72xxVuMeterDisplay.h"

namespace MuzicAnalyser 
{
    App* App::instance;

    void App::Setup(HardwareSettings* settings, VuMeter::VuMeterSettings* vuMeterSettings)
    {
        analogReference(INTERNAL);
        this->ExtendAdcRange();

        std::vector<uint8_t> analogInputs = { settings->leftChannel, settings->rightChannel };
        this->analogReader = new BatchAnalogReader(analogInputs);

        this->vuMeter = new VuMeter(this->analogReader, vuMeterSettings);
        this->max72xxPanel = new Max72xxPanel(settings->pinCs, settings->horizontalDisplays, settings->verticalDisplays);
        this->max72xxVuDisplay = new Max72xxVuMeterDisplay(this->max72xxPanel, settings->brightness);

        this->vuMeter->AddDisplay(this->max72xxVuDisplay);
    }

    void App::Run()
    {
        this->vuMeter->MeasureAndDraw();
    }

    void App::ExtendAdcRange()
    {
        sbi(ADCSRA, ADPS2);
        cbi(ADCSRA, ADPS1);
        sbi(ADCSRA, ADPS0);
    }

    App::~App()
    {
    }
}
