#include <Arduino.h>
#include "app.h"

Piotest::App app = Piotest::App();

void setup() {
    app.Setup();
}

void loop() {
    app.Run();
}