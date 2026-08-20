#ifndef PRESSURE_MANAGER_H
#define PRESSURE_MANAGER_H

#include "IParticipant.h"

class PressureManager: public observer::IParticipant
{
public:
	PressureManager() = default;

	virtual void update(const weather::WeatherData& weatherData) override;
};

#endif /* PRESSURE_MANAGER_H */