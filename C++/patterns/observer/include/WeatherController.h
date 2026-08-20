#ifndef WEATHER_CONTROLLER_H
#define WEATHER_CONTROLLER_H

#include "ISubject.h"

#include "WeatherMetrics.h"

#include <mutex>
#include <unordered_set>

namespace weather
{
	class WeatherController: public observer::ISubject
	{
	public:
		WeatherController();

		virtual void addParticipant(const std::shared_ptr<observer::IParticipant>& participant) override;
		virtual void removeParticipant(const std::shared_ptr<observer::IParticipant>& participant) override;
		virtual void notifyAllParticipants() override;

	private:
		std::mutex m_mutex;
		std::unordered_set<std::shared_ptr<observer::IParticipant>> m_participants;

		WeatherData m_weatherData;
		WeatherMetrics m_weatherMetrics;

		void updateWeatherData(const WeatherData& weatherData);
	};
}

#endif /* WEATHER_CONTROLLER_H */