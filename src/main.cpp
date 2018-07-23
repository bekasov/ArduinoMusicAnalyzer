#include "app.h"

MuzicAnalyser::App* app;

void setup() {
    app = MuzicAnalyser::App::GetInstance();
    app->Setup();
}

void loop() {
    app->Run();
}