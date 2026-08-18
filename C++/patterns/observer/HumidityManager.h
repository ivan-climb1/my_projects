#ifndef HUMIDITY_MANAGER_H
#define HUMIDITY_MANAGER_H

#include "IParticipant.h"

class HumidityManager: public IParticipant
{
public:
	HumidityManager() = default;

	virtual void update(const WeatherData& weatherData) override;
};

#endif /* HUMIDITY_MANAGER_H */