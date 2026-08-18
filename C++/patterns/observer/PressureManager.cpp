#include "PressureManager.h"

#include <iostream>

void PressureManager::update(const WeatherData& weatherData)
{
	std::cout << "Pressure is " << weatherData.m_pressure << std::endl;
}