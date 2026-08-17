#ifndef SUBJECT_H
#define SUBJECT_H

#include "ISubject.h"

#include <vector>

class Subject: public ISubject
{
public:
	Subject() = default;

	virtual void addParticipant(const std::shared_ptr<IParticipant>& participant) override;
	virtual void removeParticipant(const std::shared_ptr<IParticipant>& participant) override;
	virtual void notifyAllParticipants() override;

private:
	std::vector<std::shared_ptr<IParticipant>> m_participants;
};

#endif /* SUBJECT_H */