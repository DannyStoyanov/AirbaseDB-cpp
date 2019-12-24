#include "ICommand.h"
ICommand::ICommand(const std::string& _name) : name(_name) {}

void ICommand::setArguments(const std::vector<std::string>& arguments) {
	this->arguments = arguments;
}

const std::string& ICommand::getName() const {
	return this->name;
}

ICommand::~ICommand(){}