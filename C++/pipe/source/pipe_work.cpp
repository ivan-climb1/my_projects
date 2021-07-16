#include <experimental/filesystem>
#include <cstdio>

#include <sys/types.h>
#include <sys/stat.h>

#include "pipe_work.h"

Pipe_work::Pipe_work(const std::string pipe_name):
	m_pipe_name{pipe_name}
{
}

Pipe_work::~Pipe_work()
{
	close_pipe();
}

bool Pipe_work::create_pipe()
{
	int result = mkfifo(m_pipe_name.c_str(), S_IRUSR | S_IWUSR |
								 			 S_IRGRP | S_IWGRP |
											 S_IROTH | S_IWOTH);
								 
	if (result != 0)
	{
		std::cout << "Error: can not create pipe: " << m_pipe_name << std::endl;
		return false;
	}
	return true;
}

void Pipe_work::delete_pipe()
{
	close_pipe();
	
	if (std::remove(m_pipe_name.c_str()) != 0)
	{
		std::cout << "Error: can not delete pipe \"" << m_pipe_name << "\"" << std::endl;
	}
}

bool Pipe_work::open_pipe_for_reading()
{
	m_pipe.open(m_pipe_name, std::ios_base::in);
	return if_pipe_open();
}

bool Pipe_work::open_pipe_for_writing()
{
	if (!std::experimental::filesystem::exists(m_pipe_name))
	{
		std::cout << "Error: file \"" << m_pipe_name << "\" does not exist." << std::endl;
		return false;
	}
	
	m_pipe.open(m_pipe_name, std::ios_base::out);
	return if_pipe_open();
}

bool Pipe_work::write_to_pipe(std::string letter)
{
	if (!if_pipe_open())
	{
		return false;
	}
	
	letter.append("\n");
	m_pipe << letter;
	m_pipe.flush();
	return true;
}

std::tuple<std::string, bool, bool> Pipe_work::read_from_pipe()
{	
	if (!if_pipe_open())
	{
		return std::make_tuple("", false, false);
	}
	
	std::string letter;
	bool success = true;
	bool eof = false;
	
	if (!std::getline(m_pipe, letter))
	{
		success = false;
		if (m_pipe.eof())
		{
			eof = true;
			std::cout << "End Of File!" << std::endl;
		}
		else
		{
			std::cout << "Error: getline fall!" << std::endl;
		}
		
		return std::make_tuple(letter, success, eof);
	}
	
	return std::make_tuple(letter, success, eof);
}

bool Pipe_work::if_pipe_open()
{
	if (!m_pipe.is_open())
	{
		std::cout << "Error: the pipe \"" << m_pipe_name << "\" is closed." << std::endl;
		return false;
	}
	
	return true;
}

void Pipe_work::close_pipe()
{
	if (m_pipe.is_open())
	{
		m_pipe.close();
	}
}

