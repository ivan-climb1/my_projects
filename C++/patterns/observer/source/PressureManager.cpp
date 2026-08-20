#include "PressureManager.h"

#include <iostream>

void PressureManager::update(const weather::WeatherData& weatherData)
{
	std::cout << "Pressure is " << weatherData.m_pressure << std::endl;
}