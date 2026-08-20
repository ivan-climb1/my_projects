cmake_minimum_required(VERSION 3.10)

project(Observer)

set(files_s
	main.cpp
	ISubject.h
	IParticipant.h

	WeatherController.h
	WeatherController.cpp

	WeatherMetrics.h
	WeatherMetrics.cpp

	WeatherData.h

	ParticipantFactory.h
	ParticipantFactory.cpp

	TemperatureManager.h
	TemperatureManager.cpp
	PressureManager.h
	PressureManager.cpp
	HumidityManager.h
	HumidityManager.cpp
)

add_executable(observer ${files_s})