//
// Created by Youssef on 9/11/2025.
//

#include "Stopwatch.h"

Stopwatch &Stopwatch::getInstance() {
    static Stopwatch instance;
    return instance;
}
