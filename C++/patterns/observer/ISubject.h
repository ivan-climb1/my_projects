#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "IParticipant.h"

class ISubject
{
public:
	virtual void addParticipant(const IParticipant& participant) = 0;
	virtual void removeParticipant(const IParticipant& participant) = 0;
	virtual void notifyAllParticipants() = 0;
};

#endif /* ISUBJECT_H */