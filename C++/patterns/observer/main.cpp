#include "ISubject.h"
#include "IParticipant.h"

#include "Subject.h"
#include "TemperatureManager.h"

#include <iostream>

int main()
{
	std::cout << "Hello, world!" << std::endl;

	std::shared_ptr<ISubject> subject{std::make_shared<Subject>()};
	std::shared_ptr<IParticipant> tempParticipant{std::make_shared<TemperatureManager>()};

	subject->addParticipant(tempParticipant);
	subject->notifyAllParticipants();

	return 0;
}
