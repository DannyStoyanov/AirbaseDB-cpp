#include "showCommand.h"
#include "BinaryData.h"
#include "GlobalConnection.h"
#include<cassert>
#include<fstream>
#include<sstream>
#include<iomanip>
static GlobalConnection data;

showCommand::showCommand() : ICommand(std::string("show")) {}

void showCommand::execute() {
	assert(this->getArguments().size() == 2);
	std::vector<std::string> arguments = getArguments();
	unsigned long long offset, limit;
	std::stringstream buffer;
	buffer << arguments[0];
	buffer >> offset;
	buffer.clear();
	buffer << arguments[1];
	buffer >> limit;
	std::unique_ptr<BinaryData> bd(new BinaryData);
	bd->readBinaryFile(data.filename, offset, limit);

}

showCommand::~showCommand() {}