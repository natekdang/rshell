#include "Base.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/foreach.hpp>

bool Command::execute() //execute(string cmdStr, string argStr)
{
    std::string argStr = parameters;
    std::string cmdStr = commandString;
    
    typedef std::vector<std::string> Tokens;
    Tokens token;
    boost::split(token, argStr, boost::is_any_of(" "));

    char* args[1500];
    args[0] = const_cast<char*>(cmdStr.c_str());
    
    if (argStr.empty() || argStr == " ") //case for ls or empty args
    {
        args[1] = nullptr;
    }
    else if (cmdStr == "echo") //if echo, don't split string
    {
        args[1] = const_cast<char*>(argStr.c_str());
        args[2] = nullptr;
    }
    else //split string
    {
        unsigned y = 1;
        for (y = 1; y < token.size() + 1; y++)
        {
            args[y] = const_cast<char*>(token.at(y - 1).c_str());
        }
        args[++y] = nullptr;
    }
   
    int status;
    
    pid_t child_id;
    
    //Begin execution process
    
    child_id = fork(); //assigns id to child
    
    if (child_id < 0) //Forks child and checks for error
    {
        perror("+++++ERROR: Forking failed!+++++\n");
        return false;
    }
    
    else if (child_id == 0) //This is the child process
    {
        if (execvp(args[0], args) < 0) //Actual exection
        {
            perror("-----ERROR: Execution failed!----- \n");
            exit(1);  //******************************************
            //return false; 
        }
    }
    
    else //this is the parent process
    {
        if (waitpid(child_id, &status, 0) == -1)
        {
            perror("*****ERROR: Wait failed!*****\n");
            return false;
        }
        if (WEXITSTATUS(status) != 0)
        {
            return false;
        }
    }
    return true;
}

bool Exit::execute() //may need to fix !!!!!!!!!!!!!!!!!!!!!!!!!!!
{
    throw false;
}

bool And::execute()
{
    if (lhs->execute()) //left returns true
    {
        if(rhs->execute()) //right successful true
        {
            return true;
        }
        else //right child didn't execute successfully
        {
            return false;  
        }
    }
    else //left child didn't execute successfully so don't execute right child
    {
        return false; 
    }
}

bool Or::execute() 
{
    if (lhs->execute()) //left successful, don't execute right
    {
        return true;
    }
    else 
    {
        if (rhs->execute()) //right successful 
        {
            return true;
        }
        else //both unsuccessful 
        {
            return false; 
        }
    }
}

bool Semicolon::execute()
{
    lhs->execute(); //execute left child first
    if (rhs->execute()) //right hand child's success determines the bool value that execute returns
    {
        return true; 
    }
    else //unsuccessful
    {
        return false; 
    }
}