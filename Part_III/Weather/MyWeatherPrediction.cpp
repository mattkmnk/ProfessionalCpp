#include <iostream>
#include "MyWeatherPrediction.h"

void MyWeatherPrediction::setCurrentTempCelsius(int inTemp) {
    int fahrenheitTemp = convertCelsiusToFahrenheit(inTemp);
    setCurrentTempFahrenheit(fahrenheitTemp);
}

int MyWeatherPrediction::getTomorrowTempCelsius() const {
    int fahrenheitTemp = getTomorrowTempFahrenheit();
    return convertFahrenheitToCelsius(fahrenheitTemp);
}

void MyWeatherPrediction::showResult() const {
    std::cout << "Tomorrow's temperature will be " <<
        getTomorrowTempCelsius() << " degrees Celsius (" <<
        getTomorrowTempFahrenheit() << " degrees Fahrenheit)\n";
    std::cout << "Chance of rain is " << (getChanceOfRain() * 100) << " percent\n";

    if (getChanceOfRain() > 0.5) {
        std::cout << "Bring an umbrella!\n";
    } 
}

int MyWeatherPrediction::convertCelsiusToFahrenheit(int inCelsius) {
    return inCelsius * 1.8 + 32;
}

int MyWeatherPrediction::convertFahrenheitToCelsius(int inFahrenheit) {
    return (inFahrenheit - 32) * 1.8;
}
