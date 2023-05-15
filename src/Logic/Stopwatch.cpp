//
// Created by niels on 24/11/2022.
//

#include "Stopwatch.h"

Stopwatch::Stopwatch() { deltaTime = 0.0f; }

void Stopwatch::start() { start_time = std::chrono::steady_clock::now(); }

void Stopwatch::stop() {
    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsed_seconds_normal = end_time - start_time;
    deltaTime = elapsed_seconds_normal.count();
}

float Stopwatch::getDeltaTime() const { return deltaTime; }