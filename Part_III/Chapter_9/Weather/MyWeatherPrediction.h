#pragma once

#include "WeatherPrediction.h"

class MyWeatherPrediction : public WeatherPrediction {
public:
    virtual void setCurrentTempCelsius(int inTemp);
    virtual int getTomorrowTempCelsius() const;
    virtual void showResult() const override;

private:
    static int convertCelsiusToFahrenheit(int inCelsius);
    static int convertFahrenheitToCelsius(int inFahrenheit);
};

