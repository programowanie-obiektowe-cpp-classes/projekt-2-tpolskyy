#pragma once

#include <string>

class Food {
public:
    Food(const std::string& name, int optimalTime, int optimalTemp)
        : name(name), optimalTime(optimalTime), optimalTemp(optimalTemp) {}

    std::string getName() const { return name; }
    int getOptimalTime() const { return optimalTime; }
    int getOptimalTemp() const { return optimalTemp; }
    
    // ocena gotowania z wariantami
    std::string evaluateCooking(int actualTime, int actualTemp) const {
        if (actualTime == optimalTime && actualTemp == optimalTemp) {
            return "Perfectly cooked \n Your dish is ready to enjoy!";
        } else if (actualTemp > optimalTemp) {
            if (actualTime >= optimalTime) {
                return "Overcooked \n Too hot."; // za cieplo za dlugo
            } else {
                return "Burnt outside, undercooked inside \n Too hot for short time."; // za cieplo za krotko
            }
        } else if (actualTemp < optimalTemp) {
            if (actualTime > optimalTime) {
                return "Undercooked but warm \n Not hot enough for long time."; //za chlodno za dlugo
            } else if (actualTime < optimalTime) {
                return "Raw and cold \n Not enough heat and time."; //za chlodno za krotko
            } else {
                return "Undercooked \n Needs more heat.";
            }
        } else { 
            if (actualTime > optimalTime) {
                return "Overcooked \n Too long at the right temperature."; //temp ok za dlugo
            } else {
                return "Undercooked \n Needs more time at the right temperature."; //temp ok za krotko
            }
        }
    }

private:
    std::string name;
    int optimalTime; // w sekundach
    int optimalTemp; // w stopniach Celsjusza
};

