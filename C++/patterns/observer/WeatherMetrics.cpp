#include "WeatherMetrics.h"



namespace
{
	std::vector<WeatherData> allData{
		WeatherData{25.0, 742.9, 67.7},
		WeatherData{19.5, 684.3, 80.7},
		WeatherData{30.6, 745.8, 77.0}
	};
}

namespace weather
{

	WeatherMetrics::WeatherMetrics():
		m_thread{&WeatherMetrics::updateMetrics, this}
	{

	}

	WeatherMetrics::~WeatherMetrics()
	{
		m_thread.join();
	}

	void WeatherMetrics::addCallBack(std::function<void(const WeatherData& weatherData)> callBack)
	{
		std::lock_guard lock{m_mutex};

		m_callBack = callBack;
	}

	void WeatherMetrics::removeCallBack()
	{
		std::lock_guard lock{m_mutex};

		m_callBack = nullptr;
	}

	void WeatherMetrics::updateMetrics()
	{
		for (const auto& data : allData)
		{
			{
				std::lock_guard lock{m_mutex};

				m_callBack(data);
			}

			std::this_thread::sleep_for(std::chrono::seconds(3));
		}
	}

}