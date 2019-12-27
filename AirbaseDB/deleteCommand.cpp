#include "deleteCommand.h"
#include<cassert>
#include<fstream>
#include<sstream>
#include<cstring>
const std::string filename = "Planes.db";
deleteCommand::deleteCommand() : ICommand(std::string("delete")) {}

void deleteCommand::execute() { // TO BE CONTINUED . . .
	assert(this->getArguments().size() == 1);
}

deleteCommand::~deleteCommand() {}