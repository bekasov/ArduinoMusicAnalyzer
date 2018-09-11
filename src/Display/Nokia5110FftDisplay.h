#pragma once
#include <Arduino.h>
#include <LCD5110_Graph.h>
#include "IFftDisplay.h"


namespace MuzicAnalyser { namespace Display 
{
    class Nokia5110FftDisplay final : public IFftDisplay
    {
    public:
        struct FftMeterSettings
        {
            uint8_t lowPass;
            uint8_t maxCalculatedMagnitude;
            uint8_t maxBinsCount;
            uint8_t delayCycles;
        };

        Nokia5110FftDisplay(LCD5110* display, FftMeterSettings* settings);
        ~Nokia5110FftDisplay() {}

        void Display(const uint8_t* fftData) override;
        uint16_t GetMaxLevelHeight() override;

    private:
        const uint8_t MAX_LEVEL_HEIGHT = 42;

        LCD5110* display;
        FftMeterSettings* settings;
        uint8_t* prevMagnitudes;

        int8_t Map(uint8_t x, uint8_t inMin, uint8_t inMax, uint8_t outMin, uint8_t outMax);
    };
} }