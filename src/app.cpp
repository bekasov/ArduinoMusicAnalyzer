#include <Arduino.h>
#include <wiring_private.h>

#include "app.h"


namespace Piotest 
{
    App::App()
    {
    }

    App::~App()
    {
        if (this->Mc != nullptr)
        {
            delete this->Mc;
        }
    }

    void App::Setup()
    {
        this->Mc = new Matrix();
        
        sbi(ADCSRA, ADPS2);
        cbi(ADCSRA, ADPS1);
        sbi(ADCSRA, ADPS0);

        analogReference(INTERNAL); //  EXTERNAL
    }

    void App::Run()
    {
        int LOW_PASS = 20;
        int ANALOG_READ_MAX_VALUE = 1023;
        int NORMALIZATION_BOUND = 1000;
        byte NUMBER_OF_MEASURES = 100;

        int LEFT_CHANNEL = A1;
        int RIGHT_CHANNEL = A2;

        long leftChannelCurrent = 0;
        long rightChannelCurrent = 0;

        for (byte i = 0; i < NUMBER_OF_MEASURES; i++)
        {
            leftChannelCurrent = max(analogRead(LEFT_CHANNEL), leftChannelCurrent);
            rightChannelCurrent = max(analogRead(RIGHT_CHANNEL), rightChannelCurrent);
        }

        leftChannelCurrent = abs(map(leftChannelCurrent, LOW_PASS, ANALOG_READ_MAX_VALUE, 0, NORMALIZATION_BOUND)); 
        rightChannelCurrent = abs(map(rightChannelCurrent, LOW_PASS, ANALOG_READ_MAX_VALUE, 0, NORMALIZATION_BOUND)); 

        this->Mc->OutValues(leftChannelCurrent, rightChannelCurrent, NORMALIZATION_BOUND);
    }
}

/*
        //Serial.begin(9600);

        // sbi(ADCSRA, ADPS2);
        // cbi(ADCSRA, ADPS1);
        // sbi(ADCSRA, ADPS0);

        // constrain(RsoundLevel, 0, 500);
        // Serial.print("leftChannel: ");
        // Serial.print(leftChannelCurrent);
        // Serial.print(" -- ");
        // Serial.print("rightChannel: ");
        // Serial.print(rightChannelCurrent);

        // Serial.println(" ----------------------------------");

        // delay(200);

        // this->Mc->Run();

 * 
 */