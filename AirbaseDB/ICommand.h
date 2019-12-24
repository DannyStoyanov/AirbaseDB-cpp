#pragma once
#include<iostream>
#include<string>
#include<vector>
class ICommand {
private:
	std::string name;
	std::vector<std::string> arguments;
public:
	ICommand(const std::string&);
	void setArguments(const std::vector<std::string>&);
	virtual void execute() = 0;
	const std::string& getName() const;
	virtual ~ICommand();
};

