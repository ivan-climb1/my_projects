#include "Logger.h"

Logger::Logger():
	m_value{0}
{
}

Logger& Logger::getInstance()
{
	static Logger logger;
	return logger;
}

void Logger::increment()
{
	++m_value;
}

size_t Logger::getValue()
{
	return m_value;
}