#ifndef TEMPERATURE_MANAGER_H
#define TEMPERATURE_MANAGER_H

#include "IParticipant.h"

class TemperatureManager: public observer::IParticipant
{
public:
	TemperatureManager() = default;

	virtual void update(const weather::WeatherData& weatherData) override;
};

#endif /* TEMPERATURE_MANAGER_H */