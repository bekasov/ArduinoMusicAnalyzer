#include <Arduino.h>
#include "Nokia5110VuMeter.h"

namespace MuzicAnalyser { namespace Display 
{
    Nokia5110VuMeter::Nokia5110VuMeter(LCD5110* display)
    {
        this->display = display;
        this->previousLeft = 0;
        this->previousRight = 0;
    }

    void Nokia5110VuMeter::Display(uint16_t leftChannelCurrent, uint16_t rightChannelCurrent)
    {
        if (this->previousLeft == leftChannelCurrent && this->previousRight == rightChannelCurrent)
        {
            return;
        }

        uint8_t leftLevelY = 0, rightLevelY = 3;
        uint8_t levelX = 0;
        uint8_t levelWidth = 1;

        this->display->clrRect(levelX, leftLevelY, levelX + this->previousLeft, leftLevelY + levelWidth);
        this->display->clrRect(levelX, rightLevelY, levelX + this->previousLeft, rightLevelY + levelWidth);

        this->display->drawRect(levelX, leftLevelY, levelX + leftChannelCurrent, leftLevelY + levelWidth);
        this->display->drawRect(levelX, rightLevelY, levelX + rightChannelCurrent, rightLevelY + levelWidth);
		
        this->previousLeft = leftChannelCurrent;
        this->previousRight = rightChannelCurrent;
    }

    uint16_t Nokia5110VuMeter::GetMaxColumnLength()
    { 
        return 84;//48; 
    }

    void Nokia5110VuMeter::SetBrightness(uint8_t brightness)
    {
        this->display->setContrast(brightness);
    }
} }