#pragma once
#include<vector>
#include<string>
#include "Attribute.h"
class GlobalConnection{
public:
	const std::string filename;
	GlobalConnection();
	bool isNumber(const std::string&);
	bool isValidNumber(unsigned long long);
	bool isValidString(const std::string&);
	bool isValidRecord(Attribute&);
	void strcpyPtr(char* dest, const char* src);
};

