#pragma once

#include "Display/IDisplayAdapter.h"
#include "Measure/BatchAnalogReader.h"
#include "VuMeter.h"


namespace MuzicAnalyser 
{
    using namespace Display;
    using namespace Measure;

    class App final 
    {
    private: 
        static App* instance;

        IDisplayAdapter* display;
        BatchAnalogReader* analogReader;
        VuMeter* vuMeter;
        
        App() {}

    public:
        ~App();

        static App* GetInstance()
        {
            if (App::instance == nullptr)
            {
                App::instance = new App();
            }

            return App::instance;
        }

        void Setup();
        void Run();
    };
}
