#ifndef SUBJECT_H
#define SUBJECT_H

#include "ISubject.h"

#include <unordered_set>

class Subject: public ISubject
{
public:
	Subject();

	virtual void addParticipant(const std::shared_ptr<IParticipant>& participant) override;
	virtual void removeParticipant(const std::shared_ptr<IParticipant>& participant) override;
	virtual void notifyAllParticipants() override;

private:
	std::unordered_set<std::shared_ptr<IParticipant>> m_participants;
	WeatherData m_weatherData;
};

#endif /* SUBJECT_H */