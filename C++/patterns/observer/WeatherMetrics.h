#ifndef WEATHER_METRICS_H
#define WEATHER_METRICS_H

#include "IParticipant.h"

#include <thread>
#include <functional>

class WeatherMetrics
{
public:
	WeatherMetrics();
	~WeatherMetrics();

	void addCallBack(std::function<void(const WeatherData& weatherData)> callBack);
	void removeCallBack();

private:
	std::thread m_thread;
	std::function<void(const WeatherData& weatherData)> m_callBack;

	void updateMetrics();
};

#endif /* WEATHER_METRICS_H */