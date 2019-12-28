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
	assert(this->getArguments().size() == 5);
	std::vector<std::string> arguments = getArguments();
	std::stringstream buffer;

	std::ifstream readFile;
	readFile.open(data.filename, std::ios::in);
	std::ofstream writeFile;
	writeFile.open("temp.db", std::ios::out);

	int myId;
	buffer << arguments[0];
	buffer >> myId;
	buffer.clear();
	bool isUpdated = false;
	std::string line;
	while (getline(readFile, line, '\n')) {
		buffer << line;
		int temp;
		buffer >> temp;
		if (myId != temp) {
			writeFile << line << '\n';
		}
		else {
			std::stringstream tempBuffer;
			unsigned long long currentId, currentFlights;
			tempBuffer << arguments[1];
			tempBuffer >> currentId;
			tempBuffer.clear();
			tempBuffer << arguments[4];
			tempBuffer >> currentFlights;
			Attribute record(currentId, arguments[2], arguments[3], currentFlights);
			if (!data.isValidRecord(record)) {
				std::cout << "Invalid arguments of \"create\" command!" << std::endl;
				return; // checking whether all arguments are valid
			}
			writeFile << record.getId() << " " << record.getPlane() << " " << record.getType() << " " << record.getFlights() << " " << '\n';
			isUpdated = true;
		}
		for (int i = 0; i < 3; i++)
		{
			std::string missLine;
			buffer >> missLine;
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