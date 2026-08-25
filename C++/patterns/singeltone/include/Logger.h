#ifndef LOGGER_H
#define LOGGER_H

#include <cstddef>

class Logger
{
public:
	Logger(const Logger& other) = delete;
	Logger& operator=(const Logger& other) = delete;
	Logger(Logger&& other) = delete;
	Logger& operator=(Logger&& other) = delete;

	static Logger& getInstance();

	void increment();
	size_t getValue();

private:
	Logger();

	size_t m_value;
};

#endif /* LOGGER_H */