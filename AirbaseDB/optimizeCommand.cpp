#include "optimizeCommand.h"
#include "GlobalConnection.h"
#include<cstring>
#include<cassert>
#include<string>
#include<sstream>
#include<fstream>
static GlobalConnection data;

optimizeCommand::optimizeCommand() : ICommand(std::string("optimize")) {}

void optimizeCommand::execute() {
	assert(this->getArguments().size() == 0);

}

optimizeCommand::~optimizeCommand() {}