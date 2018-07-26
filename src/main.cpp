#include <Arduino.h>
#include "app.h"

using namespace MuzicAnalyser;

static App::HardwareSettings settings 
{ 
    .leftChannel = A1, 
    .rightChannel = A2,
    .brightness = 4,
    .verticalDisplays = 1,
    .horizontalDisplays = 1,
    .pinCs = 10,
    .useExternalAsDacBase = true,
    .expandAdcRange = true
};

static VuMeter::VuMeterSettings vuMeterSettings
{
    .numberOfMeasures = 100,
    .lowPass = 20,
    .mono = false
};

static App* app;

void setup() 
{
    app = App::GetInstance();
    app->Setup(&settings, &vuMeterSettings);
}

void loop() 
{
    app->Run();
}