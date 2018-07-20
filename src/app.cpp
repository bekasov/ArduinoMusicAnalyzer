#include <Arduino.h>
#include "ClassOne/ClassOne.h"
#include "app.h"

namespace Piotest 
{
    App::App()
    {
        this->Mc = new MatrixControl();
    }

    App::~App()
    {
        delete this->Mc;
    }

    void App::Setup()
    {
        // ClassOne::ClassOne ne = ClassOne::ClassOne();
        // ne.Go();

        this->Mc->Setup();
    }

    void App::Run()
    {
        this->Mc->Run();
    }
}