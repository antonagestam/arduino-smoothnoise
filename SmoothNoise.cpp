#include "SmoothNoise.h"

float cubic(float n) {
    n = 2 * n;
    if (n < 1)
        return .5 * pow(n, 3);
    n = n - 2;
    return .5 * (pow(n, 3) + 2);
}

float cubic_interpolate(float n, float a, float b, float c, float d) {
    /**
     * Maps a value n from the range (a, b) to the range (c, d)
     */
    float r = 1.0 * (n - a) / (b - a);
    return cubic(r) * (d - c) + c;
}


float R () {
    return random(100000) / 100000.0;
}

SmoothNoise::SmoothNoise(int num_steps) {
    steps = num_steps;
    steps_from_last = random(steps);
    next = R();
    last = R();
}

float SmoothNoise::next(void) {
    if(steps_from_last == steps) {
        steps_from_last = 0;
        last = next;
        next = R();
    }
    float current = cubic_interpolate(steps_from_last, 0, steps, last, next);
    steps_from_last++;
    return current;
}
