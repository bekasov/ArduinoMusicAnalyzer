#include <Arduino.h>
#include "ClassOne.h"

namespace Piotest { namespace ClassOne 
{
    void ClassOne::Go()
    {
        pinMode(LED_BUILTIN, OUTPUT);
    }
}}