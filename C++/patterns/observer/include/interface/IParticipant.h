#ifndef IPARTICIPANT_H
#define IPARTICIPANT_H

#include "WeatherData.h"

namespace observer
{
	class IParticipant
	{
	public:
		virtual void update(const weather::WeatherData& weatherData) = 0;
	};
}

#endif /* IPARTICIPANT_H */