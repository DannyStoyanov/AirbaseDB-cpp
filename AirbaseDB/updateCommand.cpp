#include "updateCommand.h"
#include "Attribute.h"
#include "GlobalConnection.h"
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
	std::stringstream buffer;

	std::ifstream readFile;
	readFile.open(data.filename, std::ios::in);
	std::ofstream writeFile;
	writeFile.open("temp.db", std::ios::out);

	Attribute record;
	unsigned long long myId;
	buffer << arguments[0];
	buffer >> myId;
	buffer.clear();
	buffer.clear();
	bool isUpdated = false;
	std::string line;
	while (getline(readFile, line, '\n')) {
		buffer << line;
		unsigned long long currentAttribute;
		buffer >> currentAttribute;
		if (myId != currentAttribute) {
			writeFile << line << '\n';
		}
		else {
			unsigned long long currentFlights;
			std::string currentPlane, currentType;
			buffer >> currentPlane;
			buffer >> currentType;
			buffer >> currentFlights;
			std::stringstream tempBuffer;
			std::string whichAtt;
			tempBuffer << arguments[1];
			tempBuffer >> whichAtt;
			tempBuffer.clear();
			tempBuffer << arguments[2];
			if (whichAtt == "id" || whichAtt == "ID" || whichAtt == "Id") {
				unsigned long long temp;
				tempBuffer >> temp;
				record.setId(temp);
				record.setPlane(currentPlane);
				record.setType(currentType);
				record.setFlights(currentFlights);
			}
			else if (whichAtt == "flights" || whichAtt == "Flights") {
				unsigned long long temp;
				tempBuffer >> temp;
				record.setId(myId);
				record.setPlane(currentPlane);
				record.setType(currentType);
				record.setFlights(temp);
			}
			else if (whichAtt == "plane" || whichAtt == "Plane") {
				std::string temp;
				tempBuffer >> temp;
				record.setId(myId);
				record.setPlane(temp);
				record.setType(currentType);
				record.setFlights(currentFlights);
			}
			else if (whichAtt == "type" || whichAtt == "Type") {
				std::string temp;
				tempBuffer >> temp;
				record.setId(myId);
				record.setPlane(currentPlane);
				record.setType(temp);
				record.setFlights(currentFlights);
			}
			if (!data.isValidRecord(record)) {
				std::cout << "Invalid arguments of \"create\" command!" << std::endl;
				return; // checking whether all arguments are valid
			}
			writeFile << record.getId() << " " << record.getPlane() << " " << record.getType() << " " << record.getFlights() << " " << '\n';
			isUpdated = true;
			// CHECK HERE!
			buffer.clear();
			continue;
		}
		for (int i = 0; i < 3; i++)
		{
			std::string missAttribute;
			buffer >> missAttribute;
		}
		buffer.clear();
	}
	writeFile.close();
	readFile.close();

	std::ifstream readFile2;
	readFile2.open("temp.db", std::ios::in);
	std::ofstream writeFile2;
	writeFile2.open(data.filename, std::ios::out);
	while (getline(readFile2, line, '\n')) {
		writeFile2 << line << '\n';
	}
	writeFile2.close();
	readFile2.close();

	if (isUpdated)std::cout << "Successfully updated!" << std::endl;
	else std::cout << "Record with ID:" << myId << " not found!" << std::endl;
}

updateCommand::~updateCommand() {}