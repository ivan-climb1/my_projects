#include "Logger.h"

Logger& Logger::getInstance()
{
	static Logger logger;
	return logger;
}

void Logger::increment()
{
	++m_value;
}