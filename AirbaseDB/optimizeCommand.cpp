#include "optimizeCommand.h"
#include "GlobalConnection.h"
#include "BinaryData.h"
#include<cstring>
#include<cassert>
#include<string>
#include<sstream>
#include<fstream>
static GlobalConnection data;
bool isOptimizeOn = false;
optimizeCommand::optimizeCommand() : ICommand(std::string("optimize")) {}

void optimizeCommand::execute() {
	assert(this->getArguments().size() == 0);
	std::unique_ptr<BinaryData> bd(new BinaryData);
	bd->optimizeBinaryFile(data.filename);
	std::cout << "-----Message: optimize: ON" << std::endl;
	isOptimizeOn = true;
}

optimizeCommand::~optimizeCommand() {}