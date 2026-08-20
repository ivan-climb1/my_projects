#include "WeatherController.h"

#include <iostream>

WeatherController::WeatherController():
	m_weatherData{25.5, 34.7, 89.3}
{
	m_weatherMetrics.addCallBack([this](const WeatherData& weatherData)
	{
		updateWeatherData(weatherData);
	});
}

void WeatherController::addParticipant(const std::shared_ptr<IParticipant>& participant)
{
	auto [_, isEmplaced]{m_participants.emplace(participant)};
	if (!isEmplaced)
	{
		std::cout << "Error: Participant already added" << std::endl;
	}
}

void WeatherController::removeParticipant(const std::shared_ptr<IParticipant>& participant)
{
	m_participants.erase(participant);
}

void WeatherController::notifyAllParticipants()
{
	for (const auto& participant : m_participants)
	{
		participant->update(m_weatherData);
	}
}

void WeatherController::updateWeatherData(const WeatherData& weatherData)
{
	m_weatherData = weatherData;
	notifyAllParticipants();
}