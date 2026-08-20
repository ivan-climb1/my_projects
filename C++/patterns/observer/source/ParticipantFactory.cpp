#include "ParticipantFactory.h"

#include "TemperatureManager.h"
#include "PressureManager.h"
#include "HumidityManager.h"

#include <iostream>

std::shared_ptr<observer::IParticipant> participnatFactory::createManager(weather::Manager manager)
{
	using namespace weather;
	switch (manager)
	{
		case Manager::Temperature:
		{
			return std::make_shared<TemperatureManager>();
		}
		case Manager::Pressure:
		{
			return std::make_shared<PressureManager>();
		}
		case Manager::Humidity:
		{
			return std::make_shared<HumidityManager>();
		}
		default:
		{
			std::cout << "Error: unknown type of manager" << std::endl;
			return {};
		}
	}
}