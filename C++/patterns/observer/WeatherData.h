#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

namespace weather
{
	struct WeatherData
	{
		double m_temperature;
		double m_pressure;
		double m_humidity;
	};

	enum class Manager
	{
		Temperature,
		Pressure,
		Humidity
	};
}

#endif /* WEATHER_DATA_H */