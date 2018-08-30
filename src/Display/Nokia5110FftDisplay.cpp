#include <Arduino.h>
#include "Nokia5110FftDisplay.h"

namespace MuzicAnalyser { namespace Display 
{
    Nokia5110FftDisplay::Nokia5110FftDisplay(LCD5110* display, uint8_t lowPass)
    {
        this->display = display;
        this->lowPass = lowPass;
    }

    void Nokia5110FftDisplay::Display(uint8_t* fftData, uint16_t fftDataCount)
    {
        this->display->clrScr();
        for (uint8_t magnitudeNumber = 1; magnitudeNumber < fftDataCount; ++magnitudeNumber)
        {
            uint8_t currentMagnitude = map(
                fftData[magnitudeNumber], 
                this->lowPass, 
                255, 
                0, 
                48); // this->GetMaxLevelHeight()

            if (currentMagnitude < 0)
            {
                currentMagnitude = 0;
            }

            uint8_t currentX = (magnitudeNumber - 1) * 2;

            this->display->drawRect(currentX, 47, currentX, 47 - currentMagnitude);
        }
    }

    uint16_t Nokia5110FftDisplay::GetMaxLevelHeight()
    {
        return 48;
    }
} }