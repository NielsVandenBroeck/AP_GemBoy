//
// Created by niels on 24/11/2022.
//

#ifndef PROJECT_STOPWATCH_H
#define PROJECT_STOPWATCH_H

#include <chrono>

/**
 * The Stopwatch Class keeps track of the game cycles. It holds a float DeltaTime that determines the amount that the
 * PlayerEntity moves. The higher your frame rate, the lower your delta time. Which means the lower your player has to
 * move for that frame. By implementing this, your frame rate does not affect the gameplay.
 */
class Stopwatch {
public:
    Stopwatch(Stopwatch&) = delete;

    /**
     * GetInstance: Returns an instance of the Stopwatch
     * @return instance of the Stopwatch
     */
    static Stopwatch& GetInstance() {
        static Stopwatch stopwatch;
        return stopwatch;
    }

    /**
     * starts the stopwatch timer
     */
    void start();

    /**
     * stops the stopwatch timer and calculates the delta time
     */
    void stop();

    /**
     * returns the delta time (time between start and stop)
     */
    float getDeltaTime() const;

private:
    /**
     * constructor of the class StopWatch
     */
    Stopwatch();

    std::chrono::steady_clock::time_point start_time; // keeps track when the timer started
    float deltaTime;                                  // calculated time between start and stop was called
};

#endif // PROJECT_STOPWATCH_H
