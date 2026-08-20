#include "WeatherController.h"

#include <iostream>

namespace weather
{

	WeatherController::WeatherController()
	{
		m_weatherMetrics.addCallBack([this](const WeatherData& weatherData)
		{
			updateWeatherData(weatherData);
		});
	}

	void WeatherController::addParticipant(const std::shared_ptr<IParticipant>& participant)
	{
		std::lock_guard lock{m_mutex};

		auto [_, isEmplaced]{m_participants.emplace(participant)};
		if (!isEmplaced)
		{
			std::cout << "Error: Participant already added" << std::endl;
		}
	}

	void WeatherController::removeParticipant(const std::shared_ptr<IParticipant>& participant)
	{
		std::lock_guard lock{m_mutex};

		m_participants.erase(participant);
	}

	void WeatherController::notifyAllParticipants()
	{
		std::lock_guard lock{m_mutex};

		for (const auto& participant : m_participants)
		{
			participant->update(m_weatherData);
		}
		std::cout << std::endl;
	}

	void WeatherController::updateWeatherData(const WeatherData& weatherData)
	{
		{
			std::lock_guard lock{m_mutex};

			m_weatherData = weatherData;
		}

		notifyAllParticipants();
	}

}