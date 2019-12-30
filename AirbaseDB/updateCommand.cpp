#include "updateCommand.h"
#include "Attribute.h"
#include "GlobalConnection.h"
#include "BinaryData.h"
#include<cstring>
#include<cassert>
#include<string>
#include<sstream>
#include<fstream>
static GlobalConnection data;

updateCommand::updateCommand() : ICommand(std::string("update")) {}

void updateCommand::execute() {
	assert(this->getArguments().size() == 3);
	std::vector<std::string> arguments = getArguments();
	std::unique_ptr<BinaryData> bd(new BinaryData);
	bd->updateBinaryFile(data.filename, arguments);
}
updateCommand::~updateCommand() {}