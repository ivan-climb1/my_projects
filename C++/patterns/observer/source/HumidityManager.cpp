#include "HumidityManager.h"

#include <iostream>

void HumidityManager::update(const weather::WeatherData& weatherData)
{
	std::cout << "Humidity is " << weatherData.m_humidity << std::endl;
}