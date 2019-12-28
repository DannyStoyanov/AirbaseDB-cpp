#include "deleteCommand.h"
#include<cassert>
#include<fstream>
#include<sstream>
#include<cstring>
#include <algorithm>
#include<cstdio>
const std::string filename = "Planes.db";
deleteCommand::deleteCommand() : ICommand(std::string("delete")) {}

void deleteCommand::execute() {
	assert(this->getArguments().size() == 1);
	std::ifstream readFile;
	readFile.open(filename, std::ios::in);
	std::ofstream writeFile;
	writeFile.open("temp.db", std::ios::out);

	std::vector<std::string> arguments = getArguments();
	std::stringstream buffer;
	int myId;
	buffer << arguments[0];
	buffer >> myId;
	buffer.clear();

	bool isDeleted = false;
	std::string line;
	while (getline(readFile, line, '\n')) {
		buffer << line;
		int temp;
		buffer >> temp;
		if (myId != temp) {
			writeFile << line << '\n';
		}
		else {
			isDeleted = true;
		}
		for (int i = 0; i < 3; i++)
		{
			std::string missLine;
			buffer >> missLine;
		}
		buffer.clear();
	}
	/* Not working . . .
	if (remove("Planes.db") == 0)
		std::cout << "File successfully delete!" << std::endl;
	else
		std::cout << "Error deleting file" << std::endl;
	if (std::rename("temp.db", "Planes.db") == 0)
		std::cout << "File successfully renamed!" << std::endl;
	else
		std::cout << "Error renaming file" << std::endl;
		*/
	writeFile.close();
	readFile.close();

	std::ifstream readFile2;
	readFile2.open("temp.db", std::ios::in);
	std::ofstream writeFile2;
	writeFile2.open(filename, std::ios::out);
	while (getline(readFile2, line, '\n')) {
		writeFile2 << line << '\n';
	}
	writeFile2.close();
	readFile2.close();

	if (isDeleted)std::cout << "Successfully deleted!" << std::endl;
	else std::cout << "Record with ID:" << myId << " not found!" << std::endl;
}

deleteCommand::~deleteCommand() {}