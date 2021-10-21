#ifndef PIPE_WORK_H
#define PIPE_WORK_H

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>

class Pipe_work
{
public:
	Pipe_work(const std::string& pipe_name);
	~Pipe_work();
	
	bool create_pipe();
	void delete_pipe();
	bool open_pipe_for_reading();
	bool open_pipe_for_writing();
	bool write_to_pipe(std::string letter);
	std::tuple<std::string, bool, bool> read_from_pipe();
	
private:
	bool if_pipe_open();
	void close_pipe();
	
	const std::string m_pipe_name;
	std::fstream m_pipe;
};

#endif /* PIPE_WORK_H */
