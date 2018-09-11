#include "app.h"


using namespace MuzicAnalyser;

static App::HardwareSettings settings 
{ 
    .leftChannel = A1, 
    .rightChannel = A2,
    .brightness = 4,
    .verticalDisplays = 4,
    .horizontalDisplays = 1,
    .pinCs = 10,
    .adcMaxOutValue = 1023,
    .adcOffset = 1023 / 2,
    .numberOfMeasures = FHT_N,
    .useExternalAsDacBase = true,
    .expandAdcRange = true,
    .inputsHaveHalfUpOffset = true,
    .nokia5110Sck = 6,
    .nokia5110Mosi = 5,
    .nokia5110Dc = 4,
    .nokia5110Cs = 3,
    .nokia5110Rst = 2
};

static VuMeter::VuMeterSettings vuMeterSettings
{
    .lowPass = 20,
    .mono = false
};

static Nokia5110FftDisplay::FftMeterSettings fftSettings
{
    .lowPass = 40,
    .maxCalculatedMagnitude = 128,
    .maxBinsCount = FHT_N / 2,
    .delayCycles = 3
};

static App* app;

void setup() 
{
    app = App::GetInstance();
    app->Setup(&settings, &vuMeterSettings, &fftSettings);
}

void loop() 
{
    app->Run();
}