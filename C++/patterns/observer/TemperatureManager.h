#ifndef TEMPERATURE_MANAGER_H
#define TEMPERATURE_MANAGER_H

#include "IParticipant.h"

class TemperatureManager: public IParticipant
{
public:
	TemperatureManager() = default;

	virtual void update(const WeatherData& weatherData) override;
};

#endif /* TEMPERATURE_MANAGER_H */