#ifndef PARTICIPANT_FACTORY_H
#define PARTICIPANT_FACTORY_H

#include "IParticipant.h"

#include <memory>

namespace participnatFactory
{
	std::shared_ptr<observer::IParticipant> createManager(weather::Manager manager);
}

#endif/* PARTICIPANT_FACTORY_H */