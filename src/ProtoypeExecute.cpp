#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    std::string cmd = "exit"; //FIXME: Bug, ls won't work if str is blank or invalid
                            //       need to shrink the array if there is no args
                            //      my idea is to have a loop make a proerly sized array
    std::string str = "";
    char* args[3];
    args[0] = const_cast<char*>(cmd.c_str());
    args[1] = const_cast<char*>(str.c_str());
    args[2] = nullptr;
    
    pid_t child_id;
    int status;
    
    if((child_id = fork()) < 0)
    {
        perror("+++++ERROR: Forking failed!+++++\n");
    }
    else if(child_id == 0)
    {
        if(execvp(args[0], args) < 0)
        {
            perror("-----ERROR: Execution failed!----- \n");
        }
    }
    else
    {
        //std::cout << "Add Waitipd here!!!" << std::endl;
        //pid_t waitpid(child_id, NULL,WNOHANG);
        if(waitpid(child_id, NULL,WNOHANG) == -1)
        {
            perror("*****ERROR: Wait failed!*****\n");
        }
    }

    
    return 0;
}