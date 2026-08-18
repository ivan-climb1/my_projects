#include "Subject.h"

#include <iostream>

Subject::Subject():
	m_weatherData{25.5, 34.7, 89.3}
{

}

void Subject::addParticipant(const std::shared_ptr<IParticipant>& participant)
{
	auto [_, isEmplaced]{m_participants.emplace(participant)};
	if (!isEmplaced)
	{
		std::cout << "Error: Participant already added" << std::endl;
	}
}

void Subject::removeParticipant(const std::shared_ptr<IParticipant>& participant)
{
	m_participants.erase(participant);
}

void Subject::notifyAllParticipants()
{
	for (const auto& participant : m_participants)
	{
		participant->update(m_weatherData);
	}
}