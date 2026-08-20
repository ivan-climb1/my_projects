#include "WeatherMetrics.h"

namespace
{
	std::vector<weather::WeatherData> allData{
		weather::WeatherData{25.0, 742.9, 67.7},
		weather::WeatherData{19.5, 684.3, 80.7},
		weather::WeatherData{30.6, 745.8, 77.0}
	};

	constexpr size_t sleep_time{3};
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
		for (size_t i{0}; i < allData.size(); ++i)
		{
			{
				std::lock_guard lock{m_mutex};

				m_callBack(allData[i]);
			}

			if (i != allData.size() - 1)
			{
				std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
			}
		}
	}
}