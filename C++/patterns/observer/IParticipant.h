#ifndef IPARTICIPANT_H
#define IPARTICIPANT_H

struct WeatherData
{
	double m_temperature;
	double m_pressure;
	double m_humidity;
};

class IParticipant
{
public:
	virtual void update(const WeatherData& weatherData) = 0;
};

#endif /* IPARTICIPANT_H */