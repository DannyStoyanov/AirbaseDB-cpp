#include "BinaryData.h"
#include "createCommand.h"
#include "Attribute.h"
#include "GlobalConnection.h"
#include "optimizeCommand.h"
#include<iostream>
#include<fstream>
#include<cassert>
#include<sstream> 
#include<cmath>
static GlobalConnection data;

createCommand::createCommand() : ICommand(std::string("create")) {}

void createCommand::execute() {
	assert(this->getArguments().size() == 4); // checking whether create has 4 arguments
	isOptimizeOn = false;
	std::vector<std::string> currentArguments;
	currentArguments = this->getArguments();
	std::stringstream buffer;
	unsigned long long currentId, currentFlights;
	buffer << currentArguments[0];
	buffer >> currentId;
	buffer.clear();
	buffer << currentArguments[3];
	buffer >> currentFlights;
	Attribute record(currentId, currentArguments[1], currentArguments[2], currentFlights);
	if (!data.isValidRecord(record)) {
		std::cout << "-----Message: Invalid arguments of \"create\" command!" << std::endl;
		return; // checking whether all arguments are valid
	}
	std::unique_ptr<BinaryData> bd(new BinaryData);
	bd->setData(currentId, currentArguments[1], currentArguments[2], currentFlights);
	bd->writeToBinaryFile(data.filename);
}

createCommand::~createCommand() {}