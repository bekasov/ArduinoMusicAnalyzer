#include <Arduino.h>
#include "LedMatrix.h"

namespace MuzicAnalyser { namespace Display 
{ 
    LedMatrix::LedMatrix(byte brightness, byte verticalDisplays, byte horizontalDisplays, byte pinCs)
    {
        this->matrix = new Max72xxPanel(pinCs, horizontalDisplays, verticalDisplays);
        this->matrix->setIntensity(brightness);
    }

    LedMatrix::~LedMatrix()
    {
        if (this->matrix != nullptr)
        {
            delete this->matrix;
        }
    }

    void LedMatrix::Display(const VuMeter::VuMeterDisplayData* data)
    {
        this->matrix->fillScreen(LOW);

        auto valuesMax = 1000;

        long leftValue = abs(map(data->leftChannelCurrentValue, 0, valuesMax, 0, 8));
        long rightValue = abs(map(data->rightChannelCurrentValue, 0, valuesMax, 0, 8));

        this->matrix->drawLine(6, 0, 6, leftValue, HIGH);
        this->matrix->drawLine(5, 0, 5, leftValue, HIGH);

        this->matrix->drawLine(1, 0, 1, rightValue, HIGH);
        this->matrix->drawLine(2, 0, 2, rightValue, HIGH);

        this->matrix->write();
    }

} }