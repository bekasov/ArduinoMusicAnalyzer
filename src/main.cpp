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
    .adcMaxOutValue = 1023,
    .adcOffset = 1023 / 2,
    .numberOfMeasures = 128,
    .useExternalAsDacBase = true,
    .expandAdcRange = false,
    .inputsHaveHalfUpOffset = true
};

static VuMeter::VuMeterSettings vuMeterSettings
{
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