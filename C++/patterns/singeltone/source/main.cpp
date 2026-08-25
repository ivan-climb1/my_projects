#include "Logger.h"

#include <iostream>
#include <thread>

int main()
{
	auto worker{[]()
	{
		Logger::getInstance().increment();
	}};

	std::thread t1{worker};
	std::thread t2{worker};
	t1.join();
	t2.join();

	auto value{Logger::getInstance().getValue()};
	std::cout << "After work value = " << value << std::endl;
	return 0;
}