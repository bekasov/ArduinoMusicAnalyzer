#pragma once

#include "IFftWrapper.h"

namespace Calculation { namespace Fft 
{
    class FhtWrapper : public IFftWrapper
    {
    public:
        virtual void CalculateFft(int16_t* const data, uint8_t*& result) override;
    };
} }