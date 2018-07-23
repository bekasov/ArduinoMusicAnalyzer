#ifndef __PIOTEST_APP_H__
#define __PIOTEST_APP_H__

#include <Display/Matrix.h>

namespace Piotest 
{
    using namespace VuMeter::Display;

    class App final 
    {
    private: 
        Matrix* Mc;

    public:
        App();
        ~App();

        void Setup();
        void Run();
    };
}

#endif