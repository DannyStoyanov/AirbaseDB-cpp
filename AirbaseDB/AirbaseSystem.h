#pragma once
#include<string>
#include<vector>
#include "Dispatcher.h"
class AirbaseSystem {
private:
	Dispatcher dispatcher;
	void parseLineToCommand(const std::string&);
	void findAndExecuteCommand(const std::string&, const std::vector<std::string>&);
public:
	AirbaseSystem();
	void run();
};

