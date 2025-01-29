#pragma once

#include "Food.hpp"

class Microwave {
public:
    Microwave();
    void setTemperature(int temp);
    void setTime(int time);
    bool cook(const Food& food);

private:
    int currentTemp;
    int currentTime;
};
