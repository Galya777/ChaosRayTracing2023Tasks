#pragma once
#include <cstdint>
#include "../Homework2/v3.h"
class Light {
public:
    my_v3 pos;
    float intensity;//intensity coefficient, no specific unit of measurement
    Light(const my_v3& lightPos, float lightIntensity) :
        pos(lightPos), intensity(lightIntensity) {}
};

