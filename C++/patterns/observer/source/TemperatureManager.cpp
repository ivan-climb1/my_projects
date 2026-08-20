#include "TemperatureManager.h"

#include <iostream>

void TemperatureManager::update(const weather::WeatherData& weatherData)
{
	std::cout << "Temperature is " << weatherData.m_temperature << std::endl;
}