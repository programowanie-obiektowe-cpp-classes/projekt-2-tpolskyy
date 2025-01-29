#include <iostream>
#include <vector>
#include "Food.hpp"
#include "Microwave.hpp"

extern std::vector<Food> loadDishesFromXML(const std::string& xmlFilePath);  

int main() {
    // ldaowanie danych z xml
    std::vector<Food> dishes = loadDishesFromXML("D:\\STUDIA\\C++\\PROJEKT-2\\projekt-2-tpolskyy\\xml\\dishes.xml");

    // wyswietlanie potraw i informacji o nich
    std::cout << "Available dishes:\n";
    for (int i = 0; i < dishes.size(); ++i) {
        std::cout << i + 1 << ". " << dishes[i].getName() 
                  << " (Optimal Time: " << dishes[i].getOptimalTime()
                  << " seconds, Optimal Temp: " << dishes[i].getOptimalTemp() 
                  << " Celsius degrees)\n";
    }

    // wybor potrawy
    std::cout << "\nSelect a dish to cook (enter number): ";
    int choice;
    std::cin >> choice;

    if (choice > 0 && choice <= dishes.size()) {
        Food selectedDish = dishes[choice - 1];
        
        // wybor temperatury i czasu
        int userTime, userTemp;
        std::cout << "Enter cooking time (in seconds): ";
        std::cin >> userTime;
        std::cout << "Enter cooking temperature (in Celsius degrees): ";
        std::cin >> userTemp;

        // weryfikacja 
        Microwave microwave;
        microwave.setTemperature(userTemp);
        microwave.setTime(userTime);
        
        std::string cookingResult = selectedDish.evaluateCooking(userTime, userTemp);
        std::cout << "The dish is " << cookingResult << ".\n";
    } else {
        std::cout << "Invalid choice!\n";
    }

    return 0;
}
