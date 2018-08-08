#include <Arduino.h>
#include <vector>

#include "app.h"
#include "Display/Max72xxVuMeterDisplay.h"
#include "Calculation/Fft/FhtWrapper.h"

namespace MuzicAnalyser 
{
    App* App::instance;

    void App::Setup(HardwareSettings* settings, VuMeter::VuMeterSettings* vuMeterSettings)
    {
        analogReference(settings->useExternalAsDacBase ? EXTERNAL : INTERNAL);
        if (settings->expandAdcRange)
        {
            this->ExpandAdcRange();
        }

        std::vector<uint8_t> analogInputs = { settings->leftChannel, settings->rightChannel };
        this->analogReader = new BatchAnalogReader(analogInputs);

        this->dataBuffer = new DataBuffer(settings->numberOfMeasures, analogInputs.size(), settings->adcOffset);

        this->vuMeter = new VuMeter(this->analogReader, vuMeterSettings);
        this->max72xxPanel = new Max72xxPanel(settings->pinCs, settings->horizontalDisplays, settings->verticalDisplays);
        this->max72xxVuDisplay = new Max72xxVuMeterDisplay(this->max72xxPanel, settings->brightness);

        this->vuMeter->AddDisplay(this->max72xxVuDisplay);

        this->fft = new FhtWrapper();

        Serial.begin(9600);
    }

    void App::Run()
    {
        this->analogReader->FillData(this->dataBuffer);

        // int16_t* const data = this->dataBuffer->GetChannelData(DataBuffer::Channel::LEFT);
        // uint8_t* out;
        // this->fft->CalculateFft(data, out);
        // Serial.println("-------------------------");
        // Serial.println(out[0]);
        // Serial.println(out[1]);
        // Serial.println(out[2]);
        // Serial.println(out[3]);
        // Serial.println(out[4]);
        // Serial.println(out[5]);
        // Serial.println(out[6]);
        // Serial.println("-------------------------");

        this->vuMeter->Draw(this->dataBuffer);
    }

    void App::ExpandAdcRange()
    {
        sbi(ADCSRA, ADPS2);
        cbi(ADCSRA, ADPS1);
        sbi(ADCSRA, ADPS0);
    }

    App::~App()
    {
    }
}
