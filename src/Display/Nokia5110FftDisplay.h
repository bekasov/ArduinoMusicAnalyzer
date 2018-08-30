#pragma once
#include <Arduino.h>
#include <LCD5110_Graph.h>
#include "IFftDisplay.h"

namespace MuzicAnalyser { namespace Display 
{
    class Nokia5110FftDisplay final : public IFftDisplay
    {
    public:
        Nokia5110FftDisplay(LCD5110* display, uint8_t lowPass);
        ~Nokia5110FftDisplay() {}

        void Display(uint8_t* fftData, uint16_t fftDataCount) override;
        uint16_t GetMaxLevelHeight() override;

    private:
        LCD5110* display;
        uint8_t lowPass;
    };
} }