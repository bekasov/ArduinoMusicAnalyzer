#pragma once

#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

#include "Display/IVuMeterDisplay.h"
#include "Measure/BatchAnalogReader.h"
#include "VuMeter.h"


namespace MuzicAnalyser 
{
    using namespace Display;
    using namespace Measure;

    class App final 
    {
    public:
        struct HardwareSettings
        {
            uint8_t leftChannel;
            uint8_t rightChannel;

            byte brightness;
            byte verticalDisplays;
            byte horizontalDisplays;
            byte pinCs;
        };

    private: 
        static App* instance;

        Max72xxPanel* max72xxPanel;
        IVuMeterDisplay* max72xxVuDisplay;

        BatchAnalogReader* analogReader;
        VuMeter* vuMeter;
        
        HardwareSettings* hardwareSettings;

        App() {}

        void ExtendAdcRange();
        
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
