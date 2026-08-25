#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
public:
	Logger() = delete;
	Logger(const Logger& other) = delete;
	Logger& operator=(const Logger& other) = delete;
	Logger(Logger&& other) = delete;
	Logger& operator=(Logger&& other) = delete;

	static Logger& getInstance();
};

#endif /* LOGGER_H */