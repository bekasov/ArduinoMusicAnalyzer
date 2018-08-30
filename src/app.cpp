#include <Arduino.h>
#include <vector>

#include "app.h"
#include "Display/Max72xxVuMeterDisplay.h"
#include "Display/Nokia5110VuMeter.h"
#include "Calculation/Fft/FhtWrapper.h"

extern uint8_t SmallFont[];
int __attribute__((used)) fht_input[(FHT_N)];

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

        this->dataBuffer = new DataBuffer(settings->numberOfMeasures, analogInputs.size(), settings->adcOffset, fht_input);

        this->vuMeter = new VuMeter(this->analogReader, vuMeterSettings);
        this->max72xxPanel = new Max72xxPanel(settings->pinCs, settings->horizontalDisplays, settings->verticalDisplays);
        this->max72xxVuDisplay = new Max72xxVuMeterDisplay(this->max72xxPanel, settings->brightness);

        this->nokiaPanel = new LCD5110(
            settings->nokia5110Sck, 
            settings->nokia5110Mosi, 
            settings->nokia5110Dc,
            settings->nokia5110Rst, 
            settings->nokia5110Cs);

        this->nokiaVuDisplay = new Nokia5110VuMeter(this->nokiaPanel);

        this->nokiaPanel->InitLCD();
        this->nokiaPanel->setFont(SmallFont);

        this->vuMeter->AddDisplay(this->max72xxVuDisplay);
        this->vuMeter->AddDisplay(this->nokiaVuDisplay);

        this->fft = new FhtWrapper();
        this->fftDisplay = new Nokia5110FftDisplay(this->nokiaPanel, vuMeterSettings->lowPass);
    }

    void App::Run()
    {
        this->analogReader->FillData(this->dataBuffer);
        uint8_t* fftData = this->fft->CalculateFft(this->dataBuffer->sumDataBuffer);

        this->fftDisplay->Display(fftData, this->dataBuffer->numberOfMeasures / 2);

        this->vuMeter->Draw(this->dataBuffer);

        this->nokiaPanel->update();
    }

    void App::ExpandAdcRange()
    {
        uint8_t* aa;
        aa = ADCSRA;
        // (ADCSRA) |= ADPS2;
        // (ADCSRA*) &= ~ADPS1;
        // (ADCSRA*) |= ADPS0;
        // (_SFR_BYTE(ADCSRA) &= ~_BV(ADPS2));
        sbi(aa, ADPS2);
        cbi(aa, ADPS1);
        sbi(aa, ADPS0);
    }

    App::~App()
    {
    }
}
