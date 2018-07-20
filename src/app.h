#ifndef __PIOTEST_APP_H__
#define __PIOTEST_APP_H__

#include <MatrixControl.h>

namespace Piotest 
{
    using namespace ::Lib::MatrixControl;

    class App final 
    {
    private: 
        MatrixControl* Mc;

    public:
        App();
        ~App();

        void Setup();
        void Run();
    };
}

#endif