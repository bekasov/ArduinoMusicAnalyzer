#pragma once

#include "Display/LedMatrix.h"
#include "Measure/ValuesForPeriod.h"


namespace MuzicAnalyser 
{
    using namespace Display;
    using namespace Measure;

    class App final 
    {
    private: 
        LedMatrix* display;
        ValuesForPeriod* measurer;

    public:
        ~App();

        void Setup();
        void Run();
    };
}
