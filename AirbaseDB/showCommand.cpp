#include "showCommand.h"
#include "GlobalConnection.h"
#include<cassert>
#include<fstream>
#include<sstream>
#include<iomanip>
static GlobalConnection data;

showCommand::showCommand() : ICommand(std::string("show")) {}

void showCommand::execute() {
	assert(this->getArguments().size() == 2);
	std::vector<std::string> arguments = getArguments();
	unsigned long long offset, limit;
	std::stringstream buffer;
	buffer << arguments[0];
	buffer >> offset;
	buffer.clear();
	buffer << arguments[1];
	buffer >> limit;

	std::fstream readFile;
	readFile.open(data.filename, std::ios::in);
	char line[554];
	for (unsigned long long i = 1; i < offset && !readFile.eof(); i++)
	{
		readFile.getline(line, 100);
	}
	//std::cout << "---List of records---" << std::endl;
	for (unsigned long long i = 0; i < limit && !readFile.eof(); i++)
	{
		std::string temp;
		readFile >> temp;
		if (temp == "")continue;
		std::cout << "[Id:" << std::setw(10) << std::setiosflags(std::ios::left) << temp << "\t";
		readFile >> temp;
		std::cout << "Plane:" << std::setw(10) << std::setiosflags(std::ios::left) << temp << "\t";
		readFile >> temp;
		std::cout << "Type:" << std::setw(10) << std::setiosflags(std::ios::left) << temp << "\t";
		readFile >> temp;
		std::cout << "Flights:" << std::setw(10) << std::setiosflags(std::ios::left) << temp << "]" << std::endl;
	}
	//std::cout << "---\t--\t---" << std::endl;
	readFile.close();
}

showCommand::~showCommand() {}