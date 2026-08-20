#include "ISubject.h"
#include "IParticipant.h"

#include "WeatherController.h"
#include "TemperatureManager.h"

#include <iostream>

int main()
{
	std::cout << "Hello, world!" << std::endl;

	std::shared_ptr<ISubject> subject{std::make_shared<WeatherController>()};
	std::shared_ptr<IParticipant> tempParticipant{std::make_shared<TemperatureManager>()};

	subject->addParticipant(tempParticipant);

	return 0;
}
