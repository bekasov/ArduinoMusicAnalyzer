#include "FhtWrapper.h"
#include "../../app.h"

#define LOG_OUT 1

#include <FHT.h>


namespace Calculation { namespace Fft 
{
    uint8_t* FhtWrapper::CalculateFft(int16_t* const data)
    {
        fht_window(); // window the data for better frequency response
        fht_reorder(); // reorder the data before doing the fht
        fht_run(); // process the data in the fht
        fht_mag_log(); // take the output of the fht

        return fht_log_out;
    }
} }
