#include "FhtWrapper.h"

#define LOG_OUT 1 // use the log output function
#define FHT_N 128 // set to 256 point fht

#include <FHT.h> // include the library


namespace Calculation { namespace Fft 
{
    void FhtWrapper::CalculateFft(int16_t* const data, uint8_t*& result)
    {
        for (uint8_t i = 0; i < FHT_N; ++i)
        {
            fht_input[i] = data[i];   
        }

        Serial.println(fht_input[1]);

        fht_window(); // window the data for better frequency response
        fht_reorder(); // reorder the data before doing the fht
        fht_run(); // process the data in the fht
        fht_mag_log(); // take the output of the fht
        // sei();
        //Serial.write(255); // send a start byte
        //Serial.write(fht_log_out, FHT_N/2); // send out the data

        result = fht_log_out;
    }
} }
