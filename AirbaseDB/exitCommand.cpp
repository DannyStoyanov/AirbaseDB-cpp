#include "exitCommand.h"
#include<cassert>
exitCommand::exitCommand() : ICommand(std::string("exit")) {}

void exitCommand::execute() { 
	assert(this->getArguments().size() == 0);
	exit(0);
}

exitCommand::~exitCommand() {}