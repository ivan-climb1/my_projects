#include "TemperatureManager.h"

#include <iostream>

void TemperatureManager::update(const WeatherData& weatherData)
{
	std::cout << "Temperature is " << weatherData.m_temperature << std::endl;
}