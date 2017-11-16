#include "Base.h"

#include <boost/tokenizer.hpp>
#include <iostream>
#include <string>
#include <vector>

class Tree //TEST!!!!!!!!!!!!!
{
    public:
        Base *root;
        
        Tree() : root(0) {};
        Tree(Base *pointer) : root(pointer) {};
        
        void destructor(Base *);
};

void Tree::destructor(Base *curr) //will deallocate memory in tree (Base objects)
{
    if(dynamic_cast<Executable *>(curr) == NULL)
    {
        destructor(dynamic_cast<Connector *>(curr)->lhs);
        destructor(dynamic_cast<Connector *>(curr)->rhs);
    }
    delete curr; 
}

void checkForComment(std::string& userCommand) //comment checker
{
    for (unsigned int i = 0; i < userCommand.size(); i++)
    {
        if (userCommand.at(i) == '#')
        {
            userCommand.erase(i); //DELETES ANYTHING AFTER A HASH SYMBOL SINCE IT IS A COMMENT
            break;
        }
    }
}

void createTree(std::vector<Base *>& objects, std::vector<Base *>& postFix) //create tree
{
    Base *pointer;
    while (!postFix.empty())
    {
        if (dynamic_cast<Connector *>(postFix.at(0) ) == NULL) //IF COMMAND SIMPLY PUSH ONTO QUEUE 
        {
            objects.push_back(postFix.at(0));
            postFix.erase(postFix.begin());
        }
        else //IF CONNECTOR POP TWICE, SET FIRST POPPED VALUE TO CONNECTOR->LHS AND SECOND POPPED VALUE TO CONNECTOR->RHS
        {
            pointer = postFix.at(0);
            postFix.erase(postFix.begin()); 
            
            dynamic_cast<Connector *>(pointer)->lhs = objects.at(0); //pop top set connector left to pointer
            objects.erase(objects.begin());
            
            dynamic_cast<Connector *>(pointer)->rhs = objects.at(0); //pop top again set connect right to pointer
            objects.erase(objects.begin());
            objects.push_back(pointer);
        }
    }
}

int main()
{
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep{" ", ";"};
    
    while(1)
    {
        Tree *treePointer = new Tree(); //holds tree that will be built
        std::vector<std::string> tokens; //vector that will HOLD our tokens
        std::string userCommand; //input command string from user
        std::string commandLine; //string that we will CONSTRUCT to push in tokens
        
        std::cout << "$ "; //OUTPUT COMMAND PROMPT EVERY TIME
        std::getline(std::cin, userCommand); //get userCommand
        checkForComment(userCommand); //checks for command and erases rest of line if comment
        
        tokenizer tok{userCommand, sep}; //Parse, breaking up by spaces and semicolons 
        
        bool notCommand = true;  
        
        try
        {
            for (tokenizer::iterator it = tok.begin(); it != tok.end(); it++) //ITERATE THROUGH EVERY TOKEN
            {
                if (*it != ";" && *it != "||" && *it != "&&") //if not a connector 
                {
                    if (notCommand) //if is command set to false so that we know
                    {
                        notCommand = false;
                        commandLine = *it;
                    }
                    else
                    {
                        commandLine += " " + *it; //append space and
                    }
                }
                //ADDING BRANCH FOR TEST     DONT THINK WE NEED THIS, JUST NEED TO CHECK FOR TEST WHEN BUILDING THE ACTUAL TREE
                /*else if (*it == "test")
                {
                    if (notCommand)
                    {
                        notCommand = false;
                        commandLine = *it;
                    }
                    else 
                    {
                        commandLine += " " + *it; //append space 
                    }
                }*/
                else
                {
                    if (notCommand) 
                    {
                        throw 1; //invalid connector 
                    }
                    notCommand = true;
                    tokens.push_back(commandLine);
                    commandLine.clear();
                    tokens.push_back(*it);
                }
            } //FOR LOOP
            
            if (!commandLine.empty()) //IF THERE WAS AN INPUT, PUSH CONSTRUCTED COMMANDLINE ONTO TOKEN VECTOR
            {
                tokens.push_back(commandLine);
            }
            else if (!tokens.empty())
            {
                if (tokens.at(tokens.size() - 1) == ";" || tokens.at(tokens.size() - 1) == "||" || tokens.at(tokens.size() - 1) == "&&")
                {
                    throw 1; /// invalid connector
                }
            }
            else
            {
                throw 'e'; //empty command line
            }
            
            std::vector<std::string> stack;
            std::vector<Base *> postFix;
            Base *pointer;
            
            for (unsigned int i = 0; i < tokens.size(); i++)
            {
                if (tokens.at(i) == ";" || tokens.at(i) == "||" || tokens.at(i) == "&&") //IF TOKEN IS A CONNECTOR!!!!!!!!
                {
                    if (!stack.empty())
                    {
                        if (stack.at(0) == "||")
                        {
                            pointer = new Or;
                        }
                        else if (stack.at(0) == "&&")
                        {
                            pointer = new And;
                        }
                        else
                        {
                            pointer = new Semicolon;
                        }
                        postFix.push_back(pointer);
                        stack.erase(stack.begin() );
                    }
                    stack.push_back(tokens.at(i) );
                }
                
                else //ELSE IT IS A COMMAND AND ITS ARGUMENTS, NEED TO BREAK UP THE COMMAND AND ITS ARGUMENTS INTO TWO SEPARATE STRINGS IN ORDER TO CREATE OBJECT
                {
                    //if is "test" need to break up the next string check for '-' for flag, if no '-' the next string should be filepath string 
                    if (tokens.at(i).find(" ") != std::string::npos)
                    {
                        std::string commandString = tokens.at(i).substr(0, tokens.at(i).find(" ") );
                        std::string parameters = tokens.at(i).substr(tokens.at(i).find(" ") + 1);
                        
                        if (commandString == "exit")
                        {
                            pointer = new Exit;
                        }
<<<<<<< HEAD
                        else if (commandString == "test" || commandString == "[")  //CREATE TEST OBJECT WITH PARAMETERS
=======
                        else if (commandString == "test")  //CREATE TEST OBJECT WITH PARAMETERS
>>>>>>> a9fcb07469ffcb41d6342d277cbd8407dcdc0dc7
                        {
                            pointer = new Test(parameters);
                        }
                        else
                        {
                            pointer = new Command(commandString, parameters);
                        }
                    }
                    else
                    {
                        if(tokens.at(i) == "exit")
                        {
                            pointer = new Exit;
                        }
                        else
                        {
                            pointer = new Command(tokens.at(i), "");
                        }
                    }
                    postFix.push_back(pointer);
                }
            }
            
            if (!stack.empty()) 
            {
                if (stack.at(0) == "||")
                {
                    pointer = new Or;
                }
                else if (stack.at(0) == "&&")
                {
                    pointer = new And;
                }
                else
                {
                    pointer = new Semicolon;
                }
                postFix.push_back(pointer);
            }
            
            std::vector<Base *> objects;
            
            // CREATE AND EXECUTE TREE, CURRENTLY DEALLOCATES MEMORY RIGHT AFTER EXECUTING THE TREE
            createTree(objects, postFix); 
            
            treePointer->root = objects.at(0);
            treePointer->root->execute(); //execute from root
            treePointer->destructor(treePointer->root); //deallocate memory
            delete treePointer; //delete container
            // ***************************************************************************
        } //TRY BLOCK
        
        //CATCH BLOCK FOR INVALID CONNECTOR INPUT
        catch (int formatError)
        {
            std::cout << "Invalid Input for Connectors: connectors cannot lead, end, or be consecutive" << std::endl; //TESTING ONLY, WILL SIMPLY PROMPT FOR INPUT AGAIN IF THIS HAPPENS
        }
        
        catch (char emptyError) 
        {
            //std::cout << "No Command Inputted" << std::endl; //OUTPUT FOR TESTING ONLY, WHEN USER DOESN'T INPUT ANYTHING AND PRESSES ENTER JUST PROMPT FOR INPUT AGAIN
        }
        
        //CATCH BLOCK FOR EXITTING LOOP AND DEALLOCATING MEMORY
        catch (bool error)
        {
            treePointer->destructor(treePointer->root);
            delete treePointer;
            
            exit(0); //****************************************************TESTING
        }
    }
    
    return 0;
}