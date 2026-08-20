#ifndef WEATHER_CONTROLLER_H
#define WEATHER_CONTROLLER_H

#include "ISubject.h"

#include "WeatherMetrics.h"

#include <unordered_set>

class WeatherController: public ISubject
{
public:
	WeatherController();

	virtual void addParticipant(const std::shared_ptr<IParticipant>& participant) override;
	virtual void removeParticipant(const std::shared_ptr<IParticipant>& participant) override;
	virtual void notifyAllParticipants() override;

private:
	std::unordered_set<std::shared_ptr<IParticipant>> m_participants;
	WeatherData m_weatherData;
	WeatherMetrics m_weatherMetrics;

	void updateWeatherData(const WeatherData& weatherData);
};

#endif /* WEATHER_CONTROLLER_H */