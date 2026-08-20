#include "ISubject.h"
#include "IParticipant.h"

#include "WeatherController.h"
#include "ParticipantFactory.h"

int main()
{
	std::shared_ptr<ISubject> subject{std::make_shared<WeatherController>()};

	auto temperatureManager{participnatFactory::createManager(Manager::Temperature)};
	auto pressureManager{participnatFactory::createManager(Manager::Pressure)};
	auto humidityManager{participnatFactory::createManager(Manager::Humidity)};

	subject->addParticipant(temperatureManager);
	subject->addParticipant(pressureManager);
	subject->addParticipant(humidityManager);

	return 0;
}
