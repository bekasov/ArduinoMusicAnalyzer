#pragma once

#include "IFftWrapper.h"

namespace Calculation { namespace Fft 
{
    class FhtWrapper : public IFftWrapper
    {
    public:
        virtual uint8_t* CalculateFft(int16_t* const data) override;
    };
} }