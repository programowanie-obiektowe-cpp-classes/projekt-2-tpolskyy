#include "Food.hpp"
#include "tinyxml2.h"
#include <iostream>
#include <vector>
#include <string>


using namespace tinyxml2;

std::vector<Food> loadDishesFromXML(const std::string& xmlFilePath) {   //wczytywanie danych z pliku xml
    std::vector<Food> dishes;
    XMLDocument doc;
    XMLError eResult = doc.LoadFile(xmlFilePath.c_str());
    if (eResult != XML_SUCCESS) {
        std::cout << "Failed to load file: " << xmlFilePath << std::endl; //komunikat bledu
        return dishes; //zwrocenie zerowego wektora
    }

    XMLElement* pRootElement = doc.FirstChildElement("Dishes");
    if (!pRootElement) {
        std::cout << "No 'Dishes' element found in XML file." << std::endl; //pusty plik albo nie ma odpowiednich danych
        return dishes; //zwrocenie zerowego wektora
    }

    for (XMLElement* pDishElement = pRootElement->FirstChildElement("Dish"); pDishElement != nullptr; pDishElement = pDishElement->NextSiblingElement("Dish")) { //czytanie danych,
        const char* name = pDishElement->FirstChildElement("Name")->GetText();
        int optimalTime = atoi(pDishElement->FirstChildElement("OptimalTime")->GetText()); //konwersja string na int
        int optimalTemp = atoi(pDishElement->FirstChildElement("OptimalTemp")->GetText());
        dishes.emplace_back(name, optimalTime, optimalTemp); //zastąpienie wektora dishes nowym uzupelnionym, bez powielania
    }

    return dishes;
}