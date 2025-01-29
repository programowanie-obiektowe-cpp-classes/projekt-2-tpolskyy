#include "Microwave.hpp"

Microwave::Microwave() : currentTemp(0), currentTime(0) {}

void Microwave::setTemperature(int temp) {
    currentTemp = temp;
}

void Microwave::setTime(int time) {
    currentTime = time;
}

bool Microwave::cook(const Food& food) {
    std::string cookingResult = food.evaluateCooking(currentTime, currentTemp);
    // weryfikacja zgodnosci danych
    if (cookingResult == "perfectly cooked") {
        return true; // gotowanie udane
    } else {
        return false; // gotowanie nieudane
    }
}
