#include "pipe_work.h"

int main()
{
    const std::string exit("exit");
    const std::string pipe_name("pipe_for_chat");
    Pipe_work pipe(pipe_name);

    if (!pipe.open_pipe_for_writing())
    {
        return 1;
    }

    std::cout << "Hello! I am a client.\n" << 
                 "If your want exit from program type 'exit'" << std::endl;

    while (true)
    {
        std::cout << "Type a letter: ";
        
        std::string letter;
        std::getline(std::cin, letter);
        if (letter == exit)
        {
            std::cout << "exit from program" << std::endl;
            break;
        }
        
        if (!pipe.write_to_pipe(letter))
        {
            return 2;
        }		
    }

    return 0;
}
