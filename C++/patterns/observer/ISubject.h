#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "IParticipant.h"

#include <memory>

class ISubject
{
public:
	virtual void addParticipant(const std::shared_ptr<IParticipant>& participant) = 0;
	virtual void removeParticipant(const std::shared_ptr<IParticipant>& participant) = 0;
	virtual void notifyAllParticipants() = 0;
};

#endif /* ISUBJECT_H */