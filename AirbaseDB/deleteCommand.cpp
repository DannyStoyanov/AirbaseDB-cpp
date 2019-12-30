#include "deleteCommand.h"
#include "GlobalConnection.h"
#include "BinaryData.h"
#include<cassert>
#include<fstream>
#include<sstream>
#include<cstring>
#include <algorithm>
#include<cstdio>
static GlobalConnection data;

deleteCommand::deleteCommand() : ICommand(std::string("delete")) {}

void deleteCommand::execute() {
	assert(this->getArguments().size() == 1);
	std::vector<std::string> arguments = getArguments();
	std::unique_ptr<BinaryData> bd(new BinaryData);
	bd->deleteBinaryFile(data.filename, arguments);
}

deleteCommand::~deleteCommand() {}