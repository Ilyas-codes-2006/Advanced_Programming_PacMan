//
// Created by Youssef on 9/11/2025.
//

#include "Stopwatch.h"
/**
 * @Functionality We return the instance needed for a Singleton.
 *
 * @Explanation /
 */
Stopwatch &Stopwatch::getInstance() {
    static Stopwatch instance;
    return instance;
}
/**
 * @Functionality We see the time passed.
 *
 * @Explanation We calculate deltatime by taking the currenttime and substracting it from the previoustime.
 * The currentTime becomes the previousTime and we found our deltatime.
 */
float Stopwatch::tick() {
    currentTime = std::chrono::steady_clock::now();
    deltaTime = currentTime - previousTime;
    previousTime = currentTime;
    return deltaTime.count();
}
/**
 * @Functionality We reset the time.
 *
 * @Explanation We start at a new timestamp so the previousTime becomes the time the clock becomes at this moment.
 * AI adviced me to mae a reset time because I was struggling with finding a way to pause the game. Because the entities kept moving
 * while I was paused. The problem lied in that deltatime kept going and when we return to levelState the Entities are already moved.
 * So every time we go in the pause state we use this function to reset the time and then the entities won't move while in the pauseState.
 */
void Stopwatch::reset() {
    previousTime = std::chrono::steady_clock::now();
}
