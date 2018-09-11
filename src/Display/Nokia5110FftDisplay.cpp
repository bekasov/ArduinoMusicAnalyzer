#include <Arduino.h>
#include "Nokia5110FftDisplay.h"


namespace MuzicAnalyser { namespace Display 
{
    Nokia5110FftDisplay::Nokia5110FftDisplay(LCD5110* display, FftMeterSettings* settings)
    {
        this->display = display;
        this->settings = settings;

        this->prevMagnitudes = new uint8_t[this->settings->maxBinsCount];
        for (uint8_t magnitudeNumber = 1; magnitudeNumber < this->settings->maxBinsCount; ++magnitudeNumber)
        {
            this->prevMagnitudes[magnitudeNumber] = 0;
        }
    }

    void Nokia5110FftDisplay::Display(const uint8_t* fftData)
    {
        for (uint8_t magnitudeNumber = 1; magnitudeNumber < this->settings->maxBinsCount; ++magnitudeNumber)
        {
            int8_t currentMagnitude = this->Map(
                fftData[magnitudeNumber], 
                this->settings->lowPass, 
                this->settings->maxCalculatedMagnitude, 
                0, 
                MAX_LEVEL_HEIGHT);

            if (currentMagnitude < 0)
            {
                currentMagnitude = 0;
            }


            uint8_t currentX = ((magnitudeNumber - 1) << 1) + 4;

            uint8_t currentCycle = (this->prevMagnitudes[magnitudeNumber] & 0xC0) >> 6;
            uint8_t prevMagnitude = this->prevMagnitudes[magnitudeNumber] & 0x3F;

            this->display->clrRect(currentX, 47, currentX + 1, 47 - prevMagnitude);

            if (prevMagnitude > currentMagnitude)
            {
                if (currentCycle == 0)
                {
                    currentCycle = this->settings->delayCycles;
                }
                else
                {
                    currentCycle--;
                }

                if (currentCycle > 0)
                {
                    currentMagnitude = prevMagnitude;
                }
            }
            else
            {
                currentCycle = 0;
            }

            if (currentMagnitude > 0)
            {
                this->display->drawRect(currentX, 47, currentX + 1, 47 - currentMagnitude);
            }

            this->prevMagnitudes[magnitudeNumber] = ((uint8_t)currentMagnitude) | (currentCycle << 6);
        }
    }

    uint16_t Nokia5110FftDisplay::GetMaxLevelHeight()
    {
        return MAX_LEVEL_HEIGHT;
    }

    int8_t Nokia5110FftDisplay::Map(uint8_t x, uint8_t inMin, uint8_t inMax, uint8_t outMin, uint8_t outMax)
    {
        return ((x - inMin) * (outMax - outMin) / (inMax - inMin)) + outMin;
    }
} }