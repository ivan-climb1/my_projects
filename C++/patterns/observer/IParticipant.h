#ifndef IPARTICIPANT_H
#define IPARTICIPANT_H

namespace observer
{
	class IParticipant
	{
	public:
		virtual void update(const WeatherData& weatherData) = 0;
	};
}

#endif /* IPARTICIPANT_H */