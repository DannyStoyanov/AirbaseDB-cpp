#include<iostream>
#include<fstream>
#include<cassert>
#include<sstream> 
#include<cmath>
#include "createCommand.h"
#include "Attribute.h"
const std::string filename = "Planes.db";

createCommand::createCommand() : ICommand(std::string("create")) {}

bool isNumber(const std::string& str)
{
	std::string::const_iterator it = str.begin();
	while (it != str.end() && std::isdigit(*it)) ++it;
	return !str.empty() && it == str.end();
}

bool isValid(std::vector<std::string> arguments) {
	std::stringstream buffer;
	unsigned long long currentId, currentFlights;
	if (!isNumber(arguments[0]) || !isNumber(arguments[3]))return false;
	buffer << arguments[0];
	buffer >> currentId;
	buffer.clear();
	buffer << arguments[3];
	buffer >> currentFlights;
	if (currentId > pow(2, 50) || currentId < 0) {
		return false;
	}
	else if (arguments[1].size() > 256 || arguments[1] == "") {
		return false;
	}
	else if (arguments[2].size() > 256 || arguments[2] == "") {
		return false;
	}
	else if (currentFlights > pow(2, 50) || currentFlights < 0) {
		return false;
	}
	return true;
}

void createCommand::execute() {
	assert(this->getArguments().size() == 4); // checking whether create has 4 arguments
	if (!isValid(getArguments())) {
		std::cout << "Invalid arguments of \"create\" command!" << std::endl;
		return; // checking whether all arguments are valid
	}
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
	std::fstream writeFile;
	writeFile.open(filename, std::ios::app); // CHANGE IT TO STD::IOS APP, OUT IS JUST FOR TESTING!
	writeFile << currentId << " " << currentArguments[1] << " " << currentArguments[2] << " " << currentFlights << '\n';
	writeFile.close();
	std::cout << "Record created: [ID:" << currentId << "\t Plane:" << currentArguments[1] << "\t Type:" << currentArguments[2] << "\t Flights:" << currentFlights << "]" << std::endl;
}

createCommand::~createCommand() {}