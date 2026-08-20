#ifndef PARTICIPANT_FACTORY_H
#define PARTICIPANT_FACTORY_H

#include "IParticipant.h"

#include <memory>

namespace participnatFactory
{
	std::shared_ptr<IParticipant> createManager(Manager manager);
}

#endif/* PARTICIPANT_FACTORY_H */