#include "searchCommand.h"
#include "GlobalConnection.h"
#include "BinaryData.h"
#include<fstream>
#include<cassert>
#include<string>
#include<sstream>
#include<iomanip>
static GlobalConnection data;

searchCommand::searchCommand() : ICommand(std::string("search")) {}

void searchCommand::execute() {
	assert(this->getArguments().size() == 1); // checking whether create has 1 argument
	std::vector<std::string> arguments = getArguments();
	std::unique_ptr<BinaryData> bd(new BinaryData);
	bd->searchIdInBinaryFile(data.filename, arguments);
}
searchCommand::~searchCommand() {}