#include<iostream>
#include "createCommand.h"
createCommand::createCommand() : ICommand(std::string("create")) {}

void createCommand::execute() { // TO BE CONTINUED . . .
	std::cout << "created!" << std::endl;
}

createCommand::~createCommand(){}