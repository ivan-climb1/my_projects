#include "Subject.h"

#include <algorithm>

void Subject::addParticipant(const std::shared_ptr<IParticipant>& participant)
{
	m_participants.push_back(participant);
	auto it = std::find(m_participants.begin(), m_participants.end(), participant);
	it->get()->update();
}

void Subject::removeParticipant(const std::shared_ptr<IParticipant>& participant)
{

}

void Subject::notifyAllParticipants()
{

}