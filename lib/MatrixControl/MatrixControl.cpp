#include <Arduino.h>

#include "MatrixControl.h"

namespace Lib { namespace MatrixControl 
{
    MatrixControl::MatrixControl()
    {
        this->matrix = new Max72xxPanel(this->pinCs, this->numberOfHorizontalDisplays, this->numberOfVerticalDisplays);
    }

    MatrixControl::~MatrixControl()
    {
        // delete this->matrix;
    }

    void MatrixControl::Setup()
    {
        this->matrix->setIntensity(4); // Set brightness between 0 and 15
        // pinMode(LED_BUILTIN, OUTPUT);
        for (this->ptr = 0; this->ptr < this->length; this->ptr++) 
        {
            this->x[ptr] = this->numberOfHorizontalDisplays * 8 / 2;
            this->y[ptr] = this->numberOfVerticalDisplays * 8 / 2;
        }
        this->nextPtr = 0;

        ::randomSeed(::analogRead(this->pinRandom)); // Initialize random generator
    }

    void MatrixControl::Run()
    {
        this->ptr = this->nextPtr;
        this->nextPtr = this->next(this->ptr);

        this->matrix->drawPixel(this->x[this->ptr], this->y[this->ptr], HIGH); // Draw the head of the snake
        this->matrix->write(); // Send bitmap to display

        ::delay(wait);

        if (!this->occupied(this->nextPtr)) {
            this->matrix->drawPixel(this->x[this->nextPtr], this->y[this->nextPtr], LOW); // Remove the tail of the snake
        }

        for (int attempt = 0; attempt < 10; attempt++) 
        {
            // Jump at random one step up, down, left, or right
            switch (::random(4)) 
            {
                case 0: 
                    this->x[nextPtr] = constrain(this->x[this->ptr] + 1, 0, this->matrix->width() - 1); this->y[this->nextPtr] = this->y[this->ptr]; 
                    break;
                case 1: 
                    this->x[this->nextPtr] = constrain(this->x[this->ptr] - 1, 0, this->matrix->width() - 1); this->y[this->nextPtr] = this->y[this->ptr]; 
                    break;
                case 2: 
                    this->y[this->nextPtr] = constrain(this->y[this->ptr] + 1, 0, this->matrix->height() - 1); this->x[this->nextPtr] = this->x[this->ptr]; 
                    break;
                case 3: 
                    this->y[this->nextPtr] = constrain(this->y[this->ptr] - 1, 0, this->matrix->height() - 1); this->x[this->nextPtr] = this->x[this->ptr]; 
                    break;
            }

            if (!this->occupied(this->nextPtr)) 
            {
                break; // The spot is empty, break out the for loop
            }
        }
        // digitalWrite(LED_BUILTIN, HIGH);
        // delay(200);

        // digitalWrite(LED_BUILTIN, LOW);
        // delay(1000);
    }
}}