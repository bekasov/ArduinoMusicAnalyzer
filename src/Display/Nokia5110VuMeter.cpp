#include <Arduino.h>
#include "Nokia5110VuMeter.h"

namespace MuzicAnalyser { namespace Display 
{
    Nokia5110VuMeter::Nokia5110VuMeter(LCD5110* display)
    {
        this->display = display;
        this->previousLeft = 0;
        this->previousRight = 0;
        // myGLCD.InitLCD();
        // myGLCD.setFont(SmallFont);
    }

    void Nokia5110VuMeter::Display(uint16_t leftChannelCurrent, uint16_t rightChannelCurrent)
    {
        if (this->previousLeft == leftChannelCurrent && this->previousRight == rightChannelCurrent)
        {
            return;
        }

        uint8_t leftLevelX = 77, rightLevelX = 81;
        uint8_t levelY = 47;
        uint8_t levelWidth = 1;

        this->display->clrRect(leftLevelX, levelY, leftLevelX + levelWidth, levelY - this->previousLeft);
        this->display->clrRect(rightLevelX, levelY, rightLevelX + levelWidth, levelY - this->previousRight);

        this->display->drawRect(leftLevelX, levelY, leftLevelX + levelWidth, levelY - leftChannelCurrent);
        this->display->drawRect(rightLevelX, levelY, rightLevelX + levelWidth, levelY - rightChannelCurrent);
		
        this->previousLeft = leftChannelCurrent;
        this->previousRight = rightChannelCurrent;
    }

    uint16_t Nokia5110VuMeter::GetMaxColumnLength()
    { 
        return 48; 
    }

    void Nokia5110VuMeter::SetBrightness(uint8_t brightness)
    {
        this->display->setContrast(brightness);
    }
} }