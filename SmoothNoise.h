#ifndef nmap_h
#define nmap_h

#include "Arduino.h"
#include "math.h"

float cubic(float n);
float cubic_interpolate(float n, float a, float b, float c, float d);

class SmoothNoise {
    float last;
    float next;
    int steps;
    int steps_from_last;

    public:
        SmoothNoise(int num_steps);
        float next(void);
};

#endif
