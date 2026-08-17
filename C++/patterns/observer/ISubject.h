#ifndef ISUBJECT_H
#define ISUBJECT_H

class ISubject
{
public:
	virtual void addParticipant() = 0;
	virtual void removeParticipant() = 0;
	virtual void notifyAllParticipants() = 0;
};

#endif /* ISUBJECT_H */