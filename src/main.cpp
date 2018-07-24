#include <Arduino.h>
#include "app.h"

using namespace MuzicAnalyser;

App::HardwareSettings settings 
{ 
    .leftChannel = A1, 
    .rightChannel = A2,
    .brightness = 4,
    .verticalDisplays = 1,
    .horizontalDisplays = 1,
    .pinCs = 10
};

VuMeter::VuMeterSettings vuMeterSettings
{
    .numberOfMeasures = 100,
    .lowPass = 20,
    .mono = false
};

App* app;

void setup() 
{
    app = App::GetInstance();
    app->Setup(&settings, &vuMeterSettings);
}

void loop() 
{
    app->Run();
}