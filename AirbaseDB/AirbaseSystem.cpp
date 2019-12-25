#include "AirbaseSystem.h"
#include <sstream>
AirbaseSystem::AirbaseSystem() {

}
void AirbaseSystem::parseLineToCommand(const std::string& line) {
	std::stringstream stream;
	stream << line;
	std::string commandName;
	stream >> commandName;
	std::vector<std::string> arguments;
	std::string currentArgument;
	while (stream >> currentArgument) {
		arguments.push_back(currentArgument);
	}
	findAndExecuteCommand(commandName, arguments);
}
void AirbaseSystem::findAndExecuteCommand(const std::string& commandName, const std::vector<std::string>& arguments) {
	if (commandName == dispatcher.getCreateCommand().getName()) {
		dispatcher.getCreateCommand().setArguments(arguments);
		dispatcher.getCreateCommand().execute();
	}
	else if (commandName == dispatcher.getDeleteCommand().getName()) {
		dispatcher.getDeleteCommand().setArguments(arguments);
		dispatcher.getDeleteCommand().execute();
	}
	else if (commandName == dispatcher.getUpdateCommand().getName()) {
		dispatcher.getUpdateCommand().setArguments(arguments);
		dispatcher.getUpdateCommand().execute();
	}
	else if (commandName == dispatcher.getShowCommand().getName()) {
		dispatcher.getShowCommand().setArguments(arguments);
		dispatcher.getShowCommand().execute();
	}
	else if (commandName == dispatcher.getOptimizeCommand().getName()) {
		dispatcher.getOptimizeCommand().setArguments(arguments);
		dispatcher.getOptimizeCommand().execute();
	}
	else if (commandName == dispatcher.getSearchCommand().getName()) {
		dispatcher.getSearchCommand().setArguments(arguments);
		dispatcher.getSearchCommand().execute();
	}
	else if (commandName == dispatcher.getExitCommand().getName()) {
		dispatcher.getExitCommand().setArguments(arguments);
		dispatcher.getExitCommand().execute();
	}
	else {
		std::cout << "Invalid command!" << std::endl;
	}
}
void AirbaseSystem::run() {
	std::string line;
	while (true) {
		getline(std::cin, line);
		parseLineToCommand(line);
	}
}
