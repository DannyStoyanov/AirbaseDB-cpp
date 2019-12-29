#include "searchCommand.h"
#include "GlobalConnection.h"
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
	std::stringstream buffer;
	int myId;
	buffer << arguments[0];
	buffer >> myId;
	buffer.clear();
	std::fstream readFile;
	readFile.open(data.filename, std::ios::in);
	char line[554];
	for (unsigned long long i = 0; !readFile.eof(); i++)
	{
		std::string str;
		readFile.getline(line, 554, '\n');
		buffer << line;
		buffer >> str;
		if (str == "") {
			std::cout << "Record with ID:" << myId << " is not existing!" << std::endl;
			break;
		}
		if (stoull(str) == myId) {
			std::cout << "[Id:" << std::setw(10) << std::setiosflags(std::ios::left) << myId << "\t";
			buffer >> str;
			std::cout << "Plane:" << std::setw(10) << std::setiosflags(std::ios::left) << str << "\t";
			buffer >> str;
			std::cout << "Type:" << std::setw(10) << std::setiosflags(std::ios::left) << str << "\t";
			buffer >> str;
			std::cout << "Flights:" << std::setw(10) << std::setiosflags(std::ios::left) << str << "]" << std::endl;
			break;
		}
		else {
			for (int i = 0; i < 3; i++)
			{
				buffer >> str;
			}
		}
	}
	readFile.close();
}
searchCommand::~searchCommand() {}