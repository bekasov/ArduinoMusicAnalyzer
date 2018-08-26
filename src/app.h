#pragma once

#include <Arduino.h>
#include <LCD5110_Graph.h>

#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

#include "Display/IVuMeterDisplay.h"
#include "Measure/BatchAnalogReader.h"
#include "Measure/DataBuffer.h"
#include "Calculation/Fft/IFftWrapper.h"
#include "VuMeter.h"


namespace MuzicAnalyser 
{
    using namespace Display;
    using namespace Measure;
    using namespace Calculation::Fft;

    class App final 
    {
    public:
        struct HardwareSettings
        {
            uint8_t leftChannel;
            uint8_t rightChannel;
            uint8_t brightness;
            uint8_t verticalDisplays;
            uint8_t horizontalDisplays;
            uint8_t pinCs;
            uint16_t adcMaxOutValue;
            uint16_t adcOffset;
            uint16_t numberOfMeasures;
            bool useExternalAsDacBase;
            bool expandAdcRange;
            bool inputsHaveHalfUpOffset;
            uint8_t nokia5110Sck;
            uint8_t nokia5110Mosi;
            uint8_t nokia5110Dc;
            uint8_t nokia5110Cs;
            uint8_t nokia5110Rst;
        };

    private: 
        static App* instance;

        DataBuffer* dataBuffer;

        Max72xxPanel* max72xxPanel;
        IVuMeterDisplay* max72xxVuDisplay;

        LCD5110* nokiaPanel;
        IVuMeterDisplay* nokiaVuDisplay;

        BatchAnalogReader* analogReader;
        VuMeter* vuMeter;
        IFftWrapper* fft;

        App() {}

        void ExpandAdcRange();
        
    public:

        ~App();

        static App* GetInstance()
        {
            if (App::instance == nullptr)
            {
                App::instance = new App();
            }

            return App::instance;
        }

        void Setup(HardwareSettings* hardwareSettings, VuMeter::VuMeterSettings* vuMeterSettings);
        void Run();
    };
}
