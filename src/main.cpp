#include "app.h"

MuzicAnalyser::App app = MuzicAnalyser::App();

void setup() {
    app.Setup();
}

void loop() {
    app.Run();
}