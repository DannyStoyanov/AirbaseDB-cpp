#include<iostream>
#include<fstream>
#include<cassert>
#include<sstream> 
#include<cmath>
#include "createCommand.h"
#include "Attribute.h"
#include "GlobalConnection.h"
static GlobalConnection data;

createCommand::createCommand() : ICommand(std::string("create")) {}

void createCommand::execute() {
	assert(this->getArguments().size() == 4); // checking whether create has 4 arguments
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
		std::cout << "Invalid arguments of \"create\" command!" << std::endl;
		return; // checking whether all arguments are valid
	}
	std::fstream writeFile;
	writeFile.open(data.filename, std::ios::app); // CHANGE IT TO STD::IOS APP, OUT IS JUST FOR TESTING!
	writeFile << record.getId() << " " << record.getPlane() << " " << record.getType() << " " << record.getFlights() << " " << '\n';
	writeFile.close();
	std::cout << "Record created: [ID:" << currentId << "\t Plane:" << currentArguments[1] << "\t Type:" << currentArguments[2] << "\t Flights:" << currentFlights << "]" << std::endl;
}

createCommand::~createCommand() {}