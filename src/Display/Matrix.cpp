#include "Matrix.h"

namespace VuMeter { namespace Display 
{ 
    Matrix::Matrix(byte brightness, byte verticalDisplays, byte horizontalDisplays, byte pinCs)
    {
        this->matrix = new Max72xxPanel(pinCs, horizontalDisplays, verticalDisplays);
        this->matrix->setIntensity(brightness);
    }

    Matrix::~Matrix()
    {
        if (this->matrix != nullptr)
        {
            delete this->matrix;
        }
    }

    void Matrix::OutValues(int leftValue, int rightValue, int valuesMax)
    {
        this->matrix->fillScreen(LOW);

        leftValue = abs(map(leftValue, 0, valuesMax, 0, 8));
        rightValue = abs(map(rightValue, 0, valuesMax, 0, 8));

        this->matrix->drawLine(6, 0, 6, leftValue, HIGH);
        this->matrix->drawLine(5, 0, 5, leftValue, HIGH);

        this->matrix->drawLine(1, 0, 1, rightValue, HIGH);
        this->matrix->drawLine(2, 0, 2, rightValue, HIGH);

        this->matrix->write();
    }

} }