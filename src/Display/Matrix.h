#pragma once

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

namespace VuMeter { namespace Display 
{
    class Matrix final
    {
    private:
        Max72xxPanel* matrix;

    public:
        Matrix(byte brightness = 4, byte verticalDisplays = 1, byte horizontalDisplays = 1, byte pinCs = 10);
        ~Matrix();

        void OutValues(int leftValue, int rightValue,  int valuesMax);
    };

} }