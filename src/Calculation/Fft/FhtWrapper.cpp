#include "FhtWrapper.h"
#include "../../app.h"

#define LOG_OUT 1

#include <FHT.h>

namespace Calculation { namespace Fft 
{
    uint8_t* FhtWrapper::CalculateFft(int16_t* const data) //  uint8_t*& result
    {
        // for (uint8_t i = 0; i < FHT_N; ++i)
        // {
        //     fht_input[i] = data[i];   
        // }

        // fht_input[0] = data[0];

        // Serial.println(fht_input[1]);

        fht_window(); // window the data for better frequency response
        fht_reorder(); // reorder the data before doing the fht
        fht_run(); // process the data in the fht
        fht_mag_log(); // take the output of the fht

        // ::MuzicAnalyser::App::GetInstance()->nokiaPanel->printNumI(data[0], 5, 10);
        // ::MuzicAnalyser::App::GetInstance()->nokiaPanel->printNumF(fht_log_out[1], 2, 5, 20);
        // ::MuzicAnalyser::App::GetInstance()->nokiaPanel->printNumF(fht_log_out[2], 2, 5, 30);
        // ::MuzicAnalyser::App::GetInstance()->nokiaPanel->printNumF(fht_log_out[3], 2, 5, 40);
        // sei();
        //Serial.write(255); // send a start byte
        //Serial.write(fht_log_out, FHT_N/2); // send out the data

        return fht_log_out;
    }
} }
