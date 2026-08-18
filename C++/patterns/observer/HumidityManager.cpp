#include "HumidityManager.h"

#include <iostream>

void HumidityManager::update(const WeatherData& weatherData)
{
	std::cout << "Humidity is " << weatherData.m_humidity << std::endl;
}