#include "searchCommand.h"
#include "optimizeCommand.h"
#include "GlobalConnection.h"
#include "BinaryData.h"
#include<fstream>
#include<cassert>
#include<string>
#include<sstream>
#include<iomanip>
GlobalConnection data;

searchCommand::searchCommand() : ICommand(std::string("search")) {}

void searchCommand::execute() {
	assert(this->getArguments().size() == 1); // checking whether create has 1 argument
	std::vector<std::string> arguments = getArguments();
	std::unique_ptr<BinaryData> bd(new BinaryData);
	if (isOptimizeOn == false) {
		bd->searchBinaryFile(data.filename, arguments);
	}
	else {
		bd->binarySearchBinaryFile(data.filename, arguments);
	}
}
searchCommand::~searchCommand() {}