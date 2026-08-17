#ifndef SUBJECT_H
#define SUBJECT_H

#include "ISubject.h"

class Subject: public ISubject
{
public:
	Subject() = default;

	virtual void addParticipant(const IParticipant& participant) override;
	virtual void removeParticipant(const IParticipant& participant) override;
	virtual void notifyAllParticipants() override;
};

#endif /* SUBJECT_H */