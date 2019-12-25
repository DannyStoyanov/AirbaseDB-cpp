#include "deleteCommand.h"
#include<cassert>
#include<fstream>
#include<sstream>
#include<cstring>
const std::string filename = "Planes.db"; 
deleteCommand::deleteCommand() : ICommand(std::string("delete")) {}

void deleteCommand::execute() { 
	assert(this->getArguments().size() == 1);
	std::fstream readFile;
	readFile.open(filename,std::ios::in);
	std::fstream writeFile;
	writeFile.open("temp.db", std::ios::out);
	
	// TO BE CONTINUED . . .
		
	readFile.close();
	writeFile.close();
}

deleteCommand::~deleteCommand() {}