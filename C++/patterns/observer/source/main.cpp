#include "ISubject.h"

#include "WeatherController.h"
#include "ParticipantFactory.h"

int main()
{
	std::shared_ptr<observer::ISubject> subject{std::make_shared<weather::WeatherController>()};

	auto temperatureManager{participnatFactory::createManager(weather::Manager::Temperature)};
	auto pressureManager{participnatFactory::createManager(weather::Manager::Pressure)};
	auto humidityManager{participnatFactory::createManager(weather::Manager::Humidity)};

	subject->addParticipant(temperatureManager);
	subject->addParticipant(pressureManager);
	subject->addParticipant(humidityManager);

	return 0;
}
