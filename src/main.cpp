#include "app.h"

// #define FHT_N 128 // set to 256 point fht

// #include <FHT.h> // include the library

// extern int __attribute__((used)) fht_input[(FHT_N)];

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
    .numberOfMeasures = 64,
    .useExternalAsDacBase = true,
    .expandAdcRange = false,
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

static App* app;

void setup() 
{
    app = App::GetInstance();
    app->Setup(&settings, &vuMeterSettings);

    // uint8_t channelsNumber = 2;
    // uint16_t numberOfMeasures = FHT_N;

    // int16_t** data = new int16_t*[channelsNumber];

    // data[0] = fht_input;
    // data[1] = new int16_t[numberOfMeasures];


}

void loop() 
{
    app->Run();
}