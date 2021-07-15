#include "pipe_work.h"

int main()
{
	std::string pipe_name("test_pipe");
	Pipe_work pipe(pipe_name);
	
	if (!pipe.create_pipe())
	{
		return 1;
	}
	
	if (!pipe.open_pipe_for_reading())
	{
		return 2;
	}
	
	std::cout << "Hello! I am server." << std::endl;
	
	std::string letter;
	bool success = true;
	bool eof = false;
	
	while (true)
	{
		std::tie(letter, success, eof) = pipe.read_from_pipe();
		if (!success)
		{
			pipe.delete_pipe();
			if (eof)
			{
				break;
			}	
			
			return 3;
		}
		
		std::cout << letter << std::endl;
	}

	return 0;
}
