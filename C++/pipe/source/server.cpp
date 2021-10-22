#include "pipe_work.h"

int main()
{
    const std::string pipe_name("pipe_for_chat");
    Pipe_work pipe(pipe_name);

    if (!pipe.create_pipe())
    {
        return 1;
    }

    std::cout << "Hello! I am a server.\nWaiting for client." << std::endl;

    if (!pipe.open_pipe_for_reading())
    {
        return 2;
    }

    std::cout << "I am ready." << std::endl;

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
